
//0-->Left; 1-->Centre; 2-->Right
int echo0 = A0; //Ultrasonic 1 Echo 
int echo1 = A2; //Ultrasonic 2 Echo
int echo2 = A4; //Ultrasonic 3 Echo

//0-->Left; 1-->Centre; 2-->Right
int trig0 = A1; //Ultrasonic 1 Trigger
int trig1 = A3;  //Ultrasonic 2 Trigger
int trig2 = A5;  //Ultrasonic 3 Trigger
long t[3]; //0-->Left; 1-->Centre; 2-->Right in seconds
int dist[3];  //0-->Left; 1-->Centre; 2-->Right in centters
void observe()
{
    analogWrite(trig0, LOW);
    analogWrite(trig1, LOW);
    analogWrite(trig2, LOW);
    delay(1);
    // Set the trig on HIGH state for 1 second
    analogWrite(trig0, HIGH);
    analogWrite(trig1, HIGH);
    analogWrite(trig2, HIGH);
    delay(1);
    analogWrite(trig0, LOW);
    analogWrite(trig1, LOW);
    analogWrite(trig2, LOW);
    // Reads the echo
    t[0] = pulseIn(echo0, HIGH);
    t[1] = pulseIn(echo1, HIGH);
    t[2] = pulseIn(echo2, HIGH);
    dist[0] = calcDist(t[0]);
    dist[1] = calcDist(t[1]);
    dist[2] = calcDist(t[2]);
}
int calcDist(long t)
{
    return t * 34 / 2;
}
void setup() {
  // put your setup code here, to run once:

    //Echo Pins
    pinMode(echo0, INPUT);
    pinMode(echo1, INPUT);
    pinMode(echo2, INPUT);
    //Trig Pins
    pinMode(trig0, OUTPUT);
    pinMode(trig1, OUTPUT);
    pinMode(trig2, OUTPUT);
    Serial.begin(9600);
    Serial.println("--- Start Serial Monitor SEND_RCVE ---");
    Serial.println(" Type in Box above, . ");
    Serial.println("(Decimal)(Hex)(Character)");  
    Serial.println(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  observe();
  Serial.println(dist[0]);
  Serial.print(dist[1]);
  Serial.print(dist[2]);
  
}
