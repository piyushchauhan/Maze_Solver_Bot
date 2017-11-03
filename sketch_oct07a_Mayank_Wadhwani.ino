/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trig1 13
#define echo1 12
#define trig2 11
#define echo2 10
#define trig3 9
#define echo3 8
#define fwd 3
#define left 4
#define right 5
#define bck 2

int x=10;
void setup() {
  Serial.begin (9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(fwd,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(bck,OUTPUT);
}

void goforward(){
  digitalWrite(fwd,HIGH);
  delay(100);
  }

  void turnleft(){
  digitalWrite(left,HIGH);
  delay(100);
  }

  void turnright(){
  digitalWrite(right,HIGH);
  delay(100);
  }

  void goback(){
  digitalWrite(bck,HIGH);
  delay(100);
  }

void loop() {
  long dura1,dura2,dura3, dist1,dist2,dist3;
  digitalWrite(trig1, LOW);  // Added this line   // left 
  delayMicroseconds(2); // Added this line
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig1, LOW);
  dura1 = pulseIn(echo1, HIGH);
  dist1 = (dura1/2) / 29.1;

  digitalWrite(trig2, LOW);  // Added this line       //center
  delayMicroseconds(2); // Added this line
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig2, LOW);
  dura2 = pulseIn(echo2, HIGH);
  dist2 = (dura2/2) / 29.1;

  digitalWrite(trig3, LOW);  // Added this line       //right
  delayMicroseconds(2); // Added this line
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig3, LOW);
  dura3 = pulseIn(echo3, HIGH);
  dist3 = (dura3/2) / 29.1;

if(dist1>x && dist2<15 && dist3<x){
  turnright();
}
  
else if(dist1<x && dist2<15 && dist3>x){
  turnleft();
}

else if(dist1<x && dist3<x && dist2>15){
  goforward();
}

else if(dist1<x && dist2<15 && dist3<x){
  goback();
}
 
Serial.print("dist1 : ");
Serial.print(dist1);
Serial.print("\tdist2 : ");
Serial.print(dist2);
Serial.print("\tdist3 : ");
Serial.println(dist3);

}
