import urllib2
import time
import RPi.GPIO as io
io.setmode(io.BCM)
 
door_sensor = 18
sensorTrigger = True
 
io.setup(door_sensor, io.IN, pull_up_down=io.PUD_UP)
 
# function for the door opening
def door_open():
    print("Door Open")
    urllib2.urlopen("http://www.google-analytics.com/collect?v=1&tid=UA-40202040-2&cid=1111&t=event&ec=doors&ea=open&el=office").close
 
# function for the door closing
def door_close():
    print("Door Close")
    urllib2.urlopen("http://www.google-analytics.com/collect?v=1&tid=UA-40202040-2&cid=1111&t=event&ec=doors&ea=closed&el=office").close
 
while True:
    if io.input(door_sensor): # if door is opened
        if (sensorTrigger):
            door_open() # fire GA code
            sensorTrigger = False # make sure it doesn't fire again
    if not io.input(door_sensor): # if door is closed
        if not (sensorTrigger):
            door_close() # fire GA code
            sensorTrigger = True # make sure it doesn't fire again