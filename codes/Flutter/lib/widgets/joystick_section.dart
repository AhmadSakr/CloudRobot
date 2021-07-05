///////////////////////////////libraries and package import part/////////////////////////////

import 'package:flutter/material.dart';
import 'package:projectapp/widgets/joystick_dialog.dart';
//intialize  JoyStickSection class
class JoyStickSection {
  static joyStick(
    //taking the motion variables and the msg that send to chat page and connection that true
      context,
      upFieldController,
      rightFieldController,
      leftFieldController,
      downFieldController,
      _sendTextMessageToBluetooth,
      _connected) {
    return Column(
      children: [
          //creating the icon button 
        IconButton(
          iconSize: 20,
          //when we pressed the icon button
          onPressed: () {
            return JoyStickDialog.showJoyStickComponents(
              //passing motion and msg and connection and context to joystick dialog 
                context,
                upFieldController,
                rightFieldController,
                leftFieldController,
                downFieldController,
                _sendTextMessageToBluetooth,
                _connected);
          },
          //showing the image of joystic 
          icon: Image.asset(
            //the direction 
            'assets/images/joystick.png',
          ),
        ),
      ],
    );
  }
}
