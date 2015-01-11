// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


 #include <Servo.h> 
 
 Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
 int pos = 0;    // variable to store the servo position 
 int ledPin = 13;
 int tiltPin = 2;
 int counter = 1;
 boolean switcher = true; 
 int state = LOW;
 int pushed = 0;
 
 void setup() { 
   Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(tiltPin,INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
     attachInterrupt(0, change, CHANGE);
} 
 
 
 void loop() { 
  if(state==HIGH){
    if(counter >= 28){
      
      switcher = false;
  }
    if(counter <= 0){
      switcher = true;
    }
    
    if(switcher == true){
      counter++;
    }else{
      counter--;
    }
    
    digitalWrite(ledPin,HIGH);
 //  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
 //  {             // in steps of 1 degree 
 
 Serial.println("switch is HIGH");
    myservo.write(counter);              // tell servo to go to position in variable 'pos' 
 //    delay(1);                       // waits 15ms for the servo to reach the position 
 //  } 
  }else{
    digitalWrite(ledPin,LOW);
    counter--;
    if(counter <= 0){
      counter = 0;
    }
    Serial.println("switch is low");
    myservo.write(counter);
  }
Serial.println(counter);
 } 
 
 void change(){
     if(digitalRead(tiltPin)==HIGH){
 state = !state;
     }
 }
