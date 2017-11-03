

/*
  Intializing all the pin variables
*/

//Setting the motor pins
const int mot[2][2];
mot[0][0] = 2; //Left Motor +
mot[0][1] = 3; //Left Motor -
mot[1][0] = 4; //Right Motor +
mot[1][0] = 5; //Right Motor -

const int echo[3];
//0-->Left; 1-->Centre; 2-->Right
echo[0] = 13;      //Ultrasonic 1 Echo
echo[1] = 12;      //Ultrasonic 2 Echo
echo[2] = 11;      //Ultrasonic 3 Echo

const int trig[3];
//0-->Left; 1-->Centre; 2-->Right
trig[0] = 10;      //Ultrasonic 1 Trigger
trig[1] = 9;       //Ultrasonic 2 Trigger
trig[2] = 8;       //Ultrasonic 3 Trigger

long time[3]; //0-->Left; 1-->Centre; 2-->Right in seconds
int dist[3];  //0-->Left; 1-->Centre; 2-->Right in centimeters
const int turnTime = 3; //3 seconds to turn the bot 90 degrees 
void forward()
{
  delay(1);
  digitalWrite(mot[0][0], HIGH);
  digitalWrite(mot[0][1], LOW);
  digitalWrite(mot[1][0], HIGH);
  digitalWrite(mot[1][1], LOW);
}
void backward()
{
  delay(1);
  digitalWrite(mot[0][0], LOW);
  digitalWrite(mot[0][1], HIGH);
  digitalWrite(mot[1][0], LOW);
  digitalWrite(mot[1][1], HIGH);
}
void left()
{
  delay(1);
  digitalWrite(mot[0][0], LOW);
  digitalWrite(mot[0][1], HIGH);
  digitalWrite(mot[1][0], HIGH);
  digitalWrite(mot[1][1], LOW);
  delay(turnTime);
}
void right()
{
  delay(1);
  digitalWrite(mot[0][0], HIGH);
  digitalWrite(mot[0][1], LOW);
  digitalWrite(mot[1][0], LOW);
  digitalWrite(mot[1][1], HIGH);
  delay(turnTime);
}
void observe()
{
  digitalWrite(trig[0], LOW);
  digitalWrite(trig[1], LOW);
  digitalWrite(trig[2], LOW);
  delay(1);
  // Set the trig on HIGH state for 1 second
  digitalWrite(trig[0], HIGH);
  digitalWrite(trig[1], HIGH);
  digitalWrite(trig[2], HIGH);
  delay(1);
  digitalWrite(trig[0], LOW);
  digitalWrite(trig[1], LOW);
  digitalWrite(trig[2], LOW);
  // Reads the echo
  time[0] = pulseIn(echo[0], HIGH);
  time[1] = pulseIn(echo[1], HIGH);
  time[2] = pulseIn(echo[2], HIGH);
  dist[0] = time[0] * 0.034 / 2;
  dist[1] = time[1] * 0.034 / 2;
  dist[2] = time[2] * 0.034 / 2;
}
int calcDist(int t){
  return t * 0.034 / 2;
}

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      pinMode(mot[i][j], OUTPUT);
    }
  }
  for (i = 0; i < 2; i++)
  {
    pinMode(echo[i], OUTPUT);
    pinMode(trig[i], INPUT);
  }
}

void loop()
{
  
  delay(1);
}