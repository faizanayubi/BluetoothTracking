/*
 * Processing code to send/receive to from the net
 *
 * (c) 2011 D. Cuartielles for Arduino
 *
 * using simpleML from the Learning Processing website by D. Schiffman
 */

import simpleML.*;
import processing.serial.*; /* Needed for Serial Communication */

// A Request object, from the library
HTMLRequest htmlRequestSend;
HTMLRequest htmlRequestReceive;

// the URL for the php_cell
String url = "http://localhost/experiments/php_mem_cell/1.php";

// Data received from the serial port
int val;
boolean receiving = false;
boolean useSerial = false;

/* Global variables */
Serial comPort;
String [] comPortList;
String comPortString;

/*--------------------------------------------------*/

void setup(){
  size(100,100);            /* Set the size of the window  */
  background(0);            /* Set the background to black */
  
  
  /* Get the available com ports. If there is at least one
     com port available, then start communicating on it.
     If there are more than one com ports available, we will
     only open the first one (i.e. comPortList[0])
     The bufferUntil('\n'); statement will generate a serial Event
     when it reads a carriage return */
     
  comPortList = Serial.list();  
  if(comPortList.length>0){
    comPort = new Serial(this, comPortList[0], 9600);
    comPort.bufferUntil('\n');
  }
}

/*--------------------------------------------------*/

void draw(){
  /* The serialEvent function will update the display */
  if ( receiving && myPort.available() > 0 && useSerial ) {  // If data is available,
    val = myPort.read();         // read it and store it in val
    background(val);             // Set background to white
    //println(val);

    // Create and make an asynchronous request
    // PUT THE RIGHT GROUP NUMBER HERE 
    htmlRequestSend = new HTMLRequest( this, url + "?r=" + val );
    // <div id='$count'><div id='key-$count'>f</div><div id='val-$count'>45</div></div>
    htmlRequestSend.makeRequest();
  }

  if ( !receiving ) {
    htmlRequestReceive = new HTMLRequest( this, url );
    htmlRequestReceive.makeRequest();
  }
}

/*--------------------------------------------------*/

void serialEvent(Serial cPort){
  comPortString = cPort.readStringUntil('\n');
  if(comPortString != null) {
    comPortString=trim(comPortString);
    
    /* Print to the Debug screen in Processing IDE */
    println(comPortString);
  }
}

void netEvent(HTMLRequest ml) {
  if ( !receiving ) {
    String html = ml.readRawSource();
    parseHtml( html );
  }
}

void parseHtml ( String html ) {
  // print the values on the website
  int countData = 0;
  String startStr = "<div id='key-"+countData+"'>";
  int start = html.indexOf( startStr );
  while ( start >= 0 ) { // start == -1 means there is no data to be parsed
    start += startStr.length(); 
    String tempStr = html.substring( start, html.length() );
    int end = tempStr.indexOf( "</div>" );
    String theKey = html.substring( start, start + end );

    print( theKey + " - " );

    startStr = "<div id='val-"+countData+"'>";
    start = html.indexOf( startStr );
    start += startStr.length(); 
    tempStr = html.substring( start, html.length() );
    end = tempStr.indexOf( "</div>" );
    String theValue = html.substring( start, start + end );

    println( theValue );

    // send the values back over the serial port
    if ( useSerial )
      if ( int(theValue) <= 255 ) myPort.write( int(theValue) );

    countData++;
    startStr = "<div id='key-"+countData+"'>";
    start = html.indexOf( startStr );
  }
}