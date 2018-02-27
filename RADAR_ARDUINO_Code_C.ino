#include <Servo.h>

             
Servo leftRightServo;        
int leftRightPos = 0;         
const int numReadings = 10;  
int index = 0;                
int total = 0;                
int average = 0;              
int echoPin = 6;              
int initPin = 7;             
unsigned long pulseTime = 0; 
unsigned long distance = 0;   
 

void setup() {
  leftRightServo.attach(9);
  // make the init pin an output:
  pinMode(initPin, OUTPUT);
  // make the echo pin an input:
  pinMode(echoPin, INPUT);
  // initialize the serial port:
  Serial.begin(9600);
} 

void loop() {
  for(leftRightPos = 0; leftRightPos < 180; leftRightPos++) {  
    leftRightServo.write(leftRightPos);
      for (index = 0; index<=numReadings;index++) {         
        digitalWrite(initPin, LOW);
        delayMicroseconds(50);
        digitalWrite(initPin, HIGH);                          
        delayMicroseconds(50);                                
        digitalWrite(initPin, LOW);                           
        pulseTime = pulseIn(echoPin, HIGH);                 
        distance = pulseTime/58;                               
        total = total + distance;                            
        delay(10);
      }
    average = total/numReadings;                              
 
    if (index >= numReadings)  {                             
      index = 0;
      total = 0;
    }
    Serial.print("X");                                        
    Serial.print(leftRightPos);                               
    Serial.print("V");                                         
    Serial.println(average);                                 
  }

  for(leftRightPos = 180; leftRightPos > 0; leftRightPos--) {  
    leftRightServo.write(leftRightPos);
    for (index = 0; index<=numReadings;index++) {
      digitalWrite(initPin, LOW);
      delayMicroseconds(50);
      digitalWrite(initPin, HIGH);
      delayMicroseconds(50);
      digitalWrite(initPin, LOW);
      pulseTime = pulseIn(echoPin, HIGH);
      distance = pulseTime/58;
      total = total + distance;
      delay(10);
    }
    average = total/numReadings;
    if (index >= numReadings)  {
      index = 0;
      total = 0;
    }
    Serial.print("X");
    Serial.print(leftRightPos);
    Serial.print("V");
    Serial.println(average);
   }
}
