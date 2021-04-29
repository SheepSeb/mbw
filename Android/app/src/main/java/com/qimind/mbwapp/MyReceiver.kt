package com.qimind.mbwapp

import android.bluetooth.BluetoothAdapter
import android.bluetooth.BluetoothDevice
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.widget.Toast
import androidx.core.app.ActivityCompat.startActivityForResult

class MyReceiver : BroadcastReceiver() {
    val bluetoothAdapter: BluetoothAdapter? = BluetoothAdapter.getDefaultAdapter()


    override fun onReceive(context: Context, intent: Intent) {
        val intentAction: String? = intent.action

        if(BluetoothDevice.ACTION_FOUND.equals(intentAction)) {

            val device: BluetoothDevice? = intent.getParcelableExtra<BluetoothDevice>(BluetoothDevice.EXTRA_DEVICE)

            val deviceName: String = device?.name ?: "no name"
            val deviceAdress: String = device?.address ?: "no adress"

            Toast.makeText(context, deviceName + " " + deviceAdress, Toast.LENGTH_LONG).show()
        }
    }
}