int trig = 12;

int echo = 13;

int red = 2;

int blue = 4;

int green = 7;

int val=200;

int potpin = A0;

void setup() {

//pins for motor controller

pinMode(11, OUTPUT);

pinMode(10, OUTPUT);

pinMode(9, OUTPUT);

pinMode(6, OUTPUT);

pinMode(red,OUTPUT);

pinMode(blue,OUTPUT);

pinMode(green,OUTPUT);

//set trig as output and echo as input for ultrasonic sensor

pinMode(trig, OUTPUT);

pinMode(echo,INPUT);

}

void loop() {

val = analogRead(potpin);

val = map(val, 0, 1028, 0, 225);

digitalWrite(trig, LOW);

delayMicroseconds(2);

digitalWrite(trig, HIGH);

delayMicroseconds(5);

digitalWrite(trig, LOW);

int duration = pulseIn(echo, HIGH);

int distance = duration / 29 / 2;

if(distance > 15){

digitalWrite(blue,0);

digitalWrite(red,1);

forward(50);

}else if(distance < 15){

digitalWrite(red,0);

digitalWrite(blue,1);

backward(600);

digitalWrite(red,1);

digitalWrite(green,0);

left(700);

digitalWrite(green,1);

}

}

// function for driving straight

void forward(int delay_time){

analogWrite(11, val);

digitalWrite(10, LOW);

analogWrite(9, val);

digitalWrite(6, LOW);

delay(delay_time);

}

//function for reversing

void backward(int delay_time){

digitalWrite(11, LOW);

analogWrite(10, val);

digitalWrite(9, LOW);

analogWrite(6, val);

delay(delay_time);

}

//function for turning left

void left(int delay_time){

analogWrite(11, val);

digitalWrite(10, LOW);

digitalWrite(9, LOW);

analogWrite(6, val);

delay(delay_time);

}

//function for turning right

void right(int delay_time){

digitalWrite(11, LOW);

analogWrite(10, val);

analogWrite(9, val);

digitalWrite(6, LOW);

delay(delay_time);

}

//function for stopping motors

void motors_stop(int delay_time){

digitalWrite(11, LOW);

digitalWrite(10, LOW);

digitalWrite(9,LOW);

digitalWrite(6, LOW);

delay(delay_time);

}
