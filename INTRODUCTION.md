### Introduction ###
We are going to build the device that is going to take in the information from the physical world and push it to Global Tracking Server using a Arduino Board.

They have sensors to detect movement, light, sound, temperature, humidity, and much more. Previously the hard part about gathering all this data was building a way to display it, yeah I can record my sleep movement but then I have to do something visual with the data, now you have Global Server to visualize it for you.

Now that we can trigger GS from off line features lets hook it up to a couple sensors and write a small program to send a message when a door gets open or it notices movement.
In this example we are going to track movement using an Raspberry Pi.
Raspberry Pi Setup

### STEPS ###
Step 1 Arduino Necessities
- 1 Arduino Uno Board
- 1 PIR (Passive Infrared) Sensor
- 3 M-F Jumper Wires
- 1 Pi Cobbler
- 1 Breadboard
- 1 Bluetooth Module

Step 2 Getting it set up
- Download the Arduino IDE and install
- Download the Processing IDE and install

Step 3 - Connecting the wires to the sensor
- Connect 3 of the M-F jumper wires to the GND (Ground), OUT, and +5V 2013-08-22_2251

Step 4 – Connecting the Parts on the ARDUINO
- Connect the pi cobbler/cable to the ARDUINO and bread board
- Connect the Black wire coming from Ground on the PIR sensor to the Ground on the breadboard
- Connect the red wire coming from the 5v on the PIR sensor to the 5v on the breadboard
- Connect the yellow wire coming from the OUT on the PIR sensor to port 8 on the breadboard

Step 5 – Adding the Code
- Arduino
- Processing

Step 6 – Running the Program
- Then open up Processing IDE and see Output Window

Step 7 – Check Real Time Reports in Global Server
- Now look in the Real Time events to see the actions come through.