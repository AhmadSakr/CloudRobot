
/////////////////////////////libraries and package import part///////////////////////////// 
import 'dart:async';
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:projectapp/widgets/device.dart';
import 'package:projectapp/widgets/chat.dart';
////////// SelectBondedDevicePage class////////////////////////////////
class SelectBondedDevicePage extends StatefulWidget {
  ///case of bluetooth availabity of my mobile
  /// If true, on page start there is performed discovery upon the bonded devices.
  /// Then, if they are not avaliable, they would be disabled from the selection.
  final bool checkAvailability; 
  final Function onCahtPage;

  const SelectBondedDevicePage(
      {this.checkAvailability = true, @required this.onCahtPage});

  @override
  _SelectBondedDevicePage createState() => new _SelectBondedDevicePage();
}
//the status of paird device 
enum _DeviceAvailability {
  //not paired 
  no,
  //paired but thier buletooth state is off
  maybe,
  //paired and thier buletooth state is on
  yes,
}
///class _DeviceWithAvailability //////////
///is chech the blutooth device availability
class _DeviceWithAvailability extends BluetoothDevice {
  
  BluetoothDevice device;
  _DeviceAvailability availability;
  //need in discovering to ge no. of recived device =no. of paired device 
  int rssi;

  _DeviceWithAvailability(this.device, this.availability, [this.rssi]);
}


//class _SelectBondedDevicePage extends form the bluetooth state is true(selectboundeddevicepage)
class _SelectBondedDevicePage extends State<SelectBondedDevicePage> {
  List<_DeviceWithAvailability> devices = List<_DeviceWithAvailability>();

  // Availability
  StreamSubscription<BluetoothDiscoveryResult> _discoveryStreamSubscription;
  bool _isDiscovering;

  _SelectBondedDevicePage();

  @override
  void initState() {
    super.initState();
//saving the availavility states 
    _isDiscovering = widget.checkAvailability;
//case the availavility states is true or connected 
//start scaning and discover  
    if (_isDiscovering) {
      _startDiscovery();
    }

    // Setup a list of the bonded devices 
    FlutterBluetoothSerial.instance
        .getBondedDevices()
        .then((List<BluetoothDevice> bondedDevices) {
      setState(() {
        devices = bondedDevices
            .map(
              (device) => _DeviceWithAvailability(
                device,
                widget.checkAvailability
                    ? _DeviceAvailability.maybe
                    : _DeviceAvailability.yes,
              ),
            )
            .toList();
      });
    });
  }
//reseting discovery 
  void _restartDiscovery() {
    setState(() {
      _isDiscovering = true;
    });

    _startDiscovery();
  }
//discovering
  void _startDiscovery() {
    _discoveryStreamSubscription =
        FlutterBluetoothSerial.instance.startDiscovery().listen((r) {
      setState(() {
        Iterator i = devices.iterator;
        while (i.moveNext()) {
          var _device = i.current;
          if (_device.device == r.device) {
            _device.availability = _DeviceAvailability.yes;
            //take no.of recived devices from the no. of discoverd device
            _device.rssi = r.rssi;
          }
        }
      });
    });
//after discovering changing the discovering flag to flase 
    _discoveryStreamSubscription.onDone(() {
      setState(() {
        _isDiscovering = false;
      });
    });
  }

  @override
  void dispose() {
    // Avoid memory leak (`setState` after dispose) and cancel discovery
    _discoveryStreamSubscription?.cancel();

    super.dispose();
  }
//calling device.dart and when active OnTap function will go to oncahtpage that will go to chat.dart
  @override
  Widget build(BuildContext context) {
    List<BluetoothDeviceListEntry> list = devices
        .map(
          (_device) => BluetoothDeviceListEntry(
            device: _device.device,
           
            onTap: () {
              widget.onCahtPage(_device.device);
            },
          ),
        )
        .toList();
    return ListView(
      children: list,
    );
  }
}
