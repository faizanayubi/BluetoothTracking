## Bluetooth Tracking ##
A Device made on Arduino to track devices/send notifications to devices near it through Bluetooth

### Objective ###
To track any object Realtime, means we will be fully aware of the location of object in terms of latitude and longitude, and would be able to see realtime movement of object.

### Materials and Methods ###
Raspberry Pi Board for Sending Data Received by Arduino board to Global Server, Arduino Uno Board to receive and analyse data, Motion Sensor to detect motion of object, Light Sensor to detect motion of object, Global Server to save data and then act as a server from where data can be fetched to many deveics(laptop, computer)

### Introduction ###
We are going to build the device that is going to take in the information from the physical world and push it to Global Tracking Server using a Raspberry Pi.

They have sensors to detect movement, light, sound, temperature, humidity, and much more. Previously the hard part about gathering all this data was building a way to display it, yeah I can record my sleep movement but then I have to do something visual with the data, now you have Global Server to visualize it for you.

Now that we can trigger GS from off line features lets hook it up to a couple sensors and write a small program to send a message when a door gets open or it notices movement.
In this example we are going to track movement using an Raspberry Pi.
Raspberry Pi Setup

### STEPS ###
Step 1 Raspberry Pi Necessities
- 1 Raspberry Pi Model B Revision 2.0 (512MB)
- 1 PIR (Passive Infrared) Sensor
- 3 M-F Jumper Wires
- 1 Pi Cobbler
- 1 Breadboard
- 1 Ethernet Cord or Wifi Dongle
- 1 Flash Card (at least 8 GB’s)

Step 2 Getting it set up
- Install Raspbian on the Raspberry Pi - Tutorial
- Set up network and wifi - more info and tutorial
- Install Rpi.GPIO to be able to hook things up to the Raspberry pi - Tutorial
- Once its setup and running and you know your way around your Raspberry Pi it’s time to connect the Goodies. I definitely recommend messing around with the Raspberry Pi and trying a couple other tutorials on learn.adafruit.com.

Step 3 - Connecting the wires to the sensor
- Connect 3 of the M-F jumper wires to the GND (Ground), OUT, and +5V 2013-08-22_2251

Step 4 – Connecting the Parts on the Raspberry Pi
- Connect the pi cobbler/cable to the Raspberry Pi and bread board
- raspi and cobblerraspi and cobbler2
- Connect the Black wire coming from Ground on the PIR sensor to the Ground on the breadboard
- Connect the red wire coming from the 5v on the PIR sensor to the 5v on the breadboard
- Connect the yellow wire coming from the OUT on the PIR sensor to port 18 on the breadboard
- raspi_motion_hook_up

Step 5 – Adding the Code
- Remember – you need the Rpi.GPIO package installed Now boot up the Raspberry Pi and add this python code:

Step 6 – Running the Program
- Then open up terminal cd into your proper directory and run it as sudo
	sudo python gamovement.py

Step 7 – Check Real Time Reports in Global Server
- Now look in the Real Time events to see the actions come through.

### Features ###
- Using a light sensor to see which lights/rooms are being used the most.
- Using a magnetic door sensor to see what times you enter & leave your house.
