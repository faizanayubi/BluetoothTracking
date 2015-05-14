import time
import urllib2
import RPi.GPIO as io
io.setmode(io.BCM)
 
pir_pin = 18
 
io.setup(pir_pin, io.IN) # activate input
 
def hitGA():
    print("sent to GA")
    urllib2.urlopen("http://www.cloudstuffs.com/collect?v=1cid=1111&t=event&ec=Movement&ea=livingRoom&el=desk").close
 
while True:
    if io.input(pir_pin):
        hitGA()
        print("Movement")
