/*
  Intializing all the pin variables
*/

//Setting the motor pins
const int motL1 = 11; //Left Motor +
const int motL2 = 10; //Left Motor -
const int motR1 = 6; //Right Motor +
const int motR2 = 5; //Right Motor -

//0-->Left; 1-->Centre; 2-->Right
const int echo0 = A1; //Ultrasonic 1 Echo 
const int echo1 = A3; //Ultrasonic 2 Echo
const int echo2 = A5; //Ultrasonic 3 Echo

//0-->Left; 1-->Centre; 2-->Right
const int trig0 = A0; //Ultrasonic 1 Trigger
const int trig1 = A2;  //Ultrasonic 2 Trigger
const int trig2 = A4;  //Ultrasonic 3 Trigger

long t[3]; //0-->Left; 1-->Centre; 2-->Right in seconds
long dist[3];  //0-->Left; 1-->Centre; 2-->Right in centters

void forward()
{
    delay(1);
    digitalWrite(motL1, HIGH);
    digitalWrite(motL2, LOW);
    digitalWrite(motR1, HIGH);
    digitalWrite(motR2, LOW);
}

void left(int c)
{
    delay(1);
    digitalWrite(motL1, LOW);
    digitalWrite(motL2, HIGH);
    digitalWrite(motR1, HIGH);
    digitalWrite(motR2, LOW);
    delay(c);
    stopMotor();
    observe();
}

void right(int d)
{
    delay(1);
    digitalWrite(motL1, HIGH);
    digitalWrite(motL2, LOW);
    digitalWrite(motR1, LOW);
    digitalWrite(motR2, HIGH);
    delay(d);
    stopMotor();
    observe();
}

void observe()
{
    digitalWrite(trig0, LOW);
    digitalWrite(trig1, LOW);
    digitalWrite(trig2, LOW);
    delay(2);
    // Set the trig on HIGH state for 1 second
    digitalWrite(trig0, HIGH);
    digitalWrite(trig1, HIGH);
    digitalWrite(trig2, HIGH);
    delay(10);
    digitalWrite(trig0, LOW);
    digitalWrite(trig1, LOW);
    digitalWrite(trig2, LOW);
    // Reads the echo
    t[0] = pulseIn(echo0, HIGH);
    t[1] = pulseIn(echo1, HIGH);
    t[2] = pulseIn(echo2, HIGH);
    dist[0] = calcDist(t[0]);
    dist[1] = calcDist(t[1]);
    dist[2] = calcDist(t[2]);
    delay(50);
}

long calcDist(long t)
{
  long distance = t/58.2;
    return distance;
}

void stopMotor()
{
    digitalWrite(motL1, LOW);
    digitalWrite(motL2, LOW);
    digitalWrite(motR1, LOW);
    digitalWrite(motR2, LOW);
}
void setup()
{
  
    Serial.begin(9600);
    //Motor pins
    pinMode(motL1, OUTPUT);
    pinMode(motL2, OUTPUT);
    pinMode(motR1, OUTPUT);
    pinMode(motR2, OUTPUT);

    //Echo Pins
    pinMode(echo0, INPUT);
    pinMode(echo1, INPUT);
    pinMode(echo2, INPUT);
    //Trig Pins
    pinMode(trig0, OUTPUT);
    pinMode(trig1, OUTPUT);
    pinMode(trig2, OUTPUT);
    Serial.println("--- Start Serial Monitor SEND_RCVE ---");
    Serial.println(" Type in Box above, . ");
    Serial.println("(Decimal)(Hex)(Character)");  
    Serial.println(); 
    
    
}

void loop()
{
    Serial.println("Loop begins");
    //For Turnings
    observe();
    Serial.println("Dist0 is");
    Serial.print(dist[0]);
    Serial.println("Dist1 is");
    Serial.print(dist[1]);
    Serial.println("Dist2 is");
    Serial.print(dist[2]);
    if (dist[1] >= 15)
    {
        forward();
    }
    else if (dist[0] >= 15)
    {
        left(1000);
    }
    else if (dist[2] >= 15)
    {
        right(1000);
    }

    //For alignment
    if (dist[0] < 10)
    {
        right(100);
    }
    else if (dist[2] < 10)
    {
        left(100);
    }
    forward();
    Serial.println("Dist0 is");
    Serial.println(dist[0]);
    Serial.println("Dist1 is");
    Serial.println(dist[1]);
    Serial.println("Dist2 is");
    Serial.println(dist[2]);
    Serial.println("Loop ends");
}

