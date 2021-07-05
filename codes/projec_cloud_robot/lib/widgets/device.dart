/////////////////////////////libraries and package import part/////////////////////////////
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
////class BluetoothDeviceListEntry/////////////////
class BluetoothDeviceListEntry extends StatelessWidget {
  final Function onTap;
  final BluetoothDevice device;
//////// se the passing parametes of the class
  BluetoothDeviceListEntry({this.onTap, @required this.device});

  @override
  Widget build(BuildContext context) {
    return ListTile(
      onTap: onTap,
      //create icons of listed devices
      leading: Icon(Icons.devices),
      //passing the name if not known will set  "Unknown device"
      title: Text(device.name ?? "Unknown device"),
      //setting the mac adderess bluetooth of the devices 
      subtitle: Text(device.address.toString()),
      //create button with text 'connect' when pressed acive 'OnTap' fuction
      trailing: FlatButton(
        child: Text('Connect'),
        onPressed: onTap,
        color: Colors.blue,
      ),
    );
  }
}

