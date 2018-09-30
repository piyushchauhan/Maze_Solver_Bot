//CODE BY VATSAL SINGHAL
//DATED:- 28-09-2018 to 1-10-2018
#define LMTR1 2
#define LMTR2 3
#define RMTR1 4
#define RMTR2 5
#define trig1 13
#define echo1 12
#define trig2 11
#define echo2 10
#define trig3 9
#define echo3 8


void setup() {
  // STARTING SETUP
  Serial.begin (9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(LMTR1,OUTPUT);
  pinMode(LMTR2,OUTPUT);
  pinMode(RMTR1,OUTPUT);
  pinMode(RMTR2,OUTPUT);
}

void fwd(int x)
{
    Serial.println("going straight");
  digitalWrite(LMTR1,HIGH);
  digitalWrite(LMTR2,LOW);
  digitalWrite(RMTR1,HIGH);
  digitalWrite(RMTR2,LOW);
  delay(x);
}
void right(int x)
{
  Serial.println("Turning RIght");
  digitalWrite(LMTR1,HIGH);
  digitalWrite(LMTR2,LOW);
  digitalWrite(RMTR1,LOW);
  digitalWrite(RMTR2,HIGH);
  delay(x);  
}
void left(int x)
{
   Serial.println("Turning Left");
  digitalWrite(LMTR1,LOW);
  digitalWrite(LMTR2,HIGH);
  digitalWrite(RMTR1,HIGH);
  digitalWrite(RMTR2,LOW);
  delay(x);
}

void bck(int x){
  Serial.println("going straight");
  digitalWrite(LMTR1,LOW);
  digitalWrite(LMTR2,HIGH);
  digitalWrite(RMTR1,LOW);
  digitalWrite(RMTR2,HIGH);
  delay(x);
 }
 
void turn(int x)
{
  Serial.println("Turning RIght");
  left(2*x);
}
void stope()
{
  digitalWrite(LMTR1,LOW);
  digitalWrite(LMTR2,LOW);
  digitalWrite(RMTR1,LOW);
  digitalWrite(RMTR2,LOW);
  delay(50);
}
void loop() {
  
  // put your main code here, to run repeatedly:
  long dura1,dura2,dura3, dist1,dist2,dist3,x=20;
  int flag=2;
  digitalWrite(trig1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig1, HIGH);
  delayMicroseconds(15); // Added this line
  digitalWrite(trig1, LOW);
  dura1 = pulseIn(echo1, HIGH);
  dist1 = (dura1/2) / 29.1;

  digitalWrite(trig2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig2, HIGH);
  delayMicroseconds(15); // Added this line
  digitalWrite(trig2, LOW);
  dura2 = pulseIn(echo2, HIGH);
  dist2 = (dura2/2) / 29.1;

  digitalWrite(trig3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig3, HIGH);
  delayMicroseconds(15); // Added this line
  digitalWrite(trig3, LOW);
  dura3 = pulseIn(echo3, HIGH);
  dist3 = (dura3/2) / 29.1;

if(dist1<x && dist2<20 && dist3<x){
  bck(300);
  stope();
  turn(300);
  stope();
  
}
else if(dist1<x && dist2 <20 && dist3>x && (flag==2 || flag!=1)){
  right(300);
  flag=0;
  stope();
}
else if(dist1>x &&dist2 <20 && dist3<x && (flag!=0 || flag==2)){
  left(300);
  flag=1;
  stope();
}

else if(dist2<30){
  if(dist1>dist3 ) {left(300);
                    stope();
                    flag=0;}
  else {right(300);
        stope();
        flag=1;}
}
else if(dist1<x){
  right(300);
  stope();
}
else if(dist3<x){
  left(300);
  stope();
}
else{
  fwd(250);
  flag=2;
} 
 
Serial.print("dist1 : ");
Serial.print(dist1);
Serial.print("\tdist2 : ");
Serial.print(dist2);
Serial.print("\tdist3 : ");
Serial.println(dist3);

delay(250);
}
    /*fwd(1000);
    stope;*/
    /*right(1000);
    stope;*/
    /*left(1000);
    stope;*/
    /*bck(1000);
    stope;*/
