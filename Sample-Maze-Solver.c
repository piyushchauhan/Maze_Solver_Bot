

const int trig0 = A0;
const int echo0 = A1;
const int trig1 = A2;
const int echo1 = A3;
const int trig2 = A4;
const int echo2 = A5;

//Setting the motor pins
const int motL1 = 11; //Left Motor +
const int motL2 = 10; //Left Motor -
const int motR1 = 6;  //Right Motor +
const int motR2 = 5;  //Right Motor -

long duration[3], distance[3];

void seeLeft()
{
  digitalWrite(trig0, LOW);
  delay(2);
  digitalWrite(trig0, HIGH);
  delay(10);
  digitalWrite(trig0, LOW);
  distance[0] = calcDist(echo0);
}

void seeForward()
{
  digitalWrite(trig1, LOW);
  delay(2);
  digitalWrite(trig1, HIGH);
  delay(10);
  digitalWrite(trig1, LOW);
  distance[1] = calcDist(echo1);
}

void seeRight()
{
  digitalWrite(trig2, LOW);
  delay(2);
  digitalWrite(trig2, HIGH);
  delay(10);
  digitalWrite(trig2, LOW);
  distance[2] = calcDist(echo2);
}
void see()
{
  seeForward();
  seeLeft();
  seeRight();
}
long calcDist(int a)
{
  long t = pulseIn(a, HIGH);
  long distance = t / 58.2;
  return distance;
}
void stopMotor()
{
  digitalWrite(motL1, LOW);
  digitalWrite(motL2, LOW);
  digitalWrite(motR1, LOW);
  digitalWrite(motR2, LOW);
}
void moveForward(int a)
{
  delay(1);
  digitalWrite(motL1, HIGH);
  digitalWrite(motL2, LOW);
  digitalWrite(motR1, HIGH);
  digitalWrite(motR2, LOW);
  delay(a);
  see();
}

void moveLeft(int c)
{
  delay(1);
  digitalWrite(motL1, LOW);
  digitalWrite(motL2, HIGH);
  digitalWrite(motR1, HIGH);
  digitalWrite(motR2, LOW);
  delay(c);
  stopMotor();
  see();
}
void moveRight(int d)
{
  delay(1);
  digitalWrite(motL1, HIGH);
  digitalWrite(motL2, LOW);
  digitalWrite(motR1, LOW);
  digitalWrite(motR2, HIGH);
  delay(d);
  stopMotor();
  see();
}

void setup()
{
  Serial.begin(9600);
  pinMode(trig0, OUTPUT);
  pinMode(echo0, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}
void loop()
{
  see();
  Serial.println(distance[0]);
  Serial.println(distance[1]);
  Serial.println(distance[2]);
  Serial.println();
  Serial.println();
  if (distance[1] > 15)
  {
    moveForward(500);
  }
  else if (distance[1] < 15) //Forward distance
  {

    if (distance[0] > 15) //Left distance
    {
      moveLeft(200);
    }
    else if (distance[2] > 15)
    {
      moveRight(200);
    }
  }
  if (distance[0] < 10)
  {
    moveRight(100);
    moveForward(200);
  }
  else if (distance[2] < 10)
  {
    moveLeft(100);
    moveForward(200);
  }
  delay(50);
}