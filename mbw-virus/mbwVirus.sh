!/bin/bash
#example device name for attack mydb.test.drop() 
sudo hciconfig hci0 name 'LaptopMBWRIL'
bluetoothctl power off
bluetoothctl power on
bluetoothctl discoverable on