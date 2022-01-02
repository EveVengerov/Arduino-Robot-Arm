# Arduino-Robot-Arm
  In this project, I build a Robot Arm which can be wirelessly controlled by a smartphone app via bluetooth
  ## 3D Printing and Assembly
   <p align="left">
 <img src="https://github.com/EveVengerov/Arduino-Robot-Arm/blob/cad97122d520cea8cdbd7c94f752824723b98a10/Pictures/RobotArmImage1.jpg" width="350" height="550" title="Robot Image Front View">
   <img src="https://github.com/EveVengerov/Arduino-Robot-Arm/blob/cad97122d520cea8cdbd7c94f752824723b98a10/Pictures/RobotArmImage2.jpg" width="350" height="550" title="Robot Image Back View">
</p>

  The model design was borrowed from [howtomechatronics](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/#Arduino_Robot_Arm_STL_Files) website and the 3D-Printed parts were assembled alongwith six servo motors : 3 MG996R Servo Motor and 3 SG90 Micro Servo motor
  ## Electronics
  The electronics used for the project besides the servos are HC-05 Bluetooth module, an Arduino-uno, a breadboard for connections and a 2Volt 3Amp Dc power source.
  Here is a circuit diagram of the connections:
                           uploading.....
  ## Coding
  ### Arduino Server
   The server side coding for the arduino is giving in the repository under the file name RobotArmServer
  ### Android Client
   The android app is developed using [MIT App Inventor](https://appinventor.mit.edu/). The control is developed using code blocks as given in the CodeBlockClient file.
   Here is the default app view as seen on the smartphone screen :
 <p align="left">
 <img src="https://github.com/EveVengerov/Arduino-Robot-Arm/blob/3b48b41f611cc04e7b1c2b01c3e74b47631c7dc0/RobotControlApp.jpg" width="400" height="550" title="Robot Control App">
</p>
 The sliders are used to control the position of each servo of the arm, varying between 0 - 180 or 90 - 180 degrees. We can save our current move using the Save button. Maximum no. of moves that can be saved is 10. Reset button can be used to set all saved moves to 0. Using Play button we can run our saved moved, the robot runs first in reverse order and then again in forward order till all saved moves are played. 
