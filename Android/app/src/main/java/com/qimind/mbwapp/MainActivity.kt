package com.qimind.mbwapp



import android.bluetooth.BluetoothAdapter
import android.bluetooth.BluetoothDevice
import android.content.Intent
import android.content.IntentFilter
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle



class MainActivity : AppCompatActivity() {

    var mReceiver = MyReceiver()
    val bleAdapter = BluetoothAdapter.getDefaultAdapter()
    val REQUEST_ENABLE_BT = 1;




    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var filter = IntentFilter()

        filter.addAction(Intent.ACTION_POWER_CONNECTED)
        filter.addAction(Intent.ACTION_POWER_DISCONNECTED)

        this@MainActivity.registerReceiver(mReceiver, filter)

        if(!bleAdapter.isEnabled()) {
            val enableBTIntent: Intent  = Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBTIntent, REQUEST_ENABLE_BT);
        }

        val bleFilter = IntentFilter(BluetoothDevice.ACTION_FOUND)
        bleAdapter.startDiscovery()

    }

    override fun onDestroy() {

        this@MainActivity.unregisterReceiver(mReceiver)
        super.onDestroy()
    }
}
