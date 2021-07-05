/////////////////////////////libraries and import part///////////////////////////// 
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:projectapp/widgets/connection.dart';
import 'package:projectapp/widgets/chat.dart';
////////////////////main function caling MyAppmm class/////////////////////////////
void main() {
  runApp(MyAppmm());
}
////////////////////////////////////////myappmm class////////////////////////////// 
class MyAppmm extends StatelessWidget {
  ///////////////// note:This widget is the root of your application/////////////////
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: FutureBuilder(
        future: FlutterBluetoothSerial.instance.requestEnable(),
        builder: (context, future) {
          //witing to check the connection but untill check the blutooth is defult off is considered 
          if (future.connectionState == ConnectionState.waiting) {
            return Scaffold(
              body: ListView(
                children: [
                  Container(
                    height: double.infinity,
                    child: Center(
                      child: Icon(
                        Icons.bluetooth_disabled,
                        size: 200.0,
                        color: Colors.blue,
                      ),
                    ),
                  ),
                ],
              ),
            );
            //case connection done for blutooth on or module is disconected  to "Home" class
          } else if (future.connectionState == ConnectionState.done) {
            // return MyHomePage(title: 'Flutter Demo Home Page');
            return Home();
          } else {
            return Home();
          }
        },
        // child: MyHomePage(title: 'Flutter Demo Home Page'),
      ),
    );
  }
}
////////////////////////////home class/////////////////////////////
///making the connection page and calling the "connection" and "device" and "chat" tabs to show thepaired devices to connect
class Home extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      appBar: AppBar(
        title: Text('Connection'),
      ),
      body: SelectBondedDevicePage(
        
        onCahtPage: (device1) {
          BluetoothDevice device = device1;
          Navigator.push(
            //device1: is Hc05 the wanted device to connect
            context,
            MaterialPageRoute(
              builder: (context) {
                //server in chat.dart
                return ChatPage(server: device);
              },
            ),
          );
        },
      ),
    ));
  }
}
