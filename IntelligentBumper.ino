#include <Servo.h>
Servo servo1;
Servo servo2;
#define LED1 13
#define LED2 12// The pin the LED is connected to
#define echoPin1 4 // attach pin D4 Arduino to pin Echo of HC-SR04
#define trigPin1 5 //attach pin D5 Arduino to pin Trig of HC-SR04
#define echoPin2 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 3 //attach pin D3 Arduino to pin Trig of HC-SR04

long duration1; // variable for the duration of sound wave travel
int distance1; // variable for the distance measurement
long duration2;
int distance2;
unsigned long time1 =0; // = millis() / 1000;
unsigned long time2 =0;
unsigned long time_general1;
unsigned long time_general2;
unsigned long t=0;
double distanta_intre_senzori=22;
double viteza=0;


void setup() {
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(LED1, OUTPUT); // Declare the LED as an output
  pinMode(LED2, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  servo1.attach(9);
  servo2.attach(8);
  servo1.write(40);
  servo2.write(0);
}

void citire_senzor2(){
  while(true){
    // Clears the trigPin condition
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration2 = pulseIn(echoPin2, HIGH);
    // Calculating the distance
    distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

   if(distance2<20 & distance2>0){
      time_general2=millis();///1000;
      if(time_general2!=time2){
        Serial.println("A trecut obiectul prin fata celui de al doilea senzor");
        time2=time_general2;
        calculeaza_viteza();
       // vitezaMica();
        break;
    }
   }
  }
}

void calculeaza_viteza(){
  t=time2-time1;
  if(t>0)
    viteza = distanta_intre_senzori/t; //cm/ms
  Serial.println("S-a calculat viteza");
  Serial.print(time1);
  Serial.print(" ");
  Serial.print(time2);
  Serial.print(" ");
  Serial.print(t); 
  Serial.print(" ");
  Serial.print(viteza); 
  Serial.println("\n");
  display1((int)(viteza*100));
  display2((int)((int)(viteza*1000)%10));
  if(viteza<0.02 && viteza>0.00)
    vitezaMica();
  if(viteza>0.02)
    vitezaMare();

}

void vitezaMare(){
   Serial.println("Viteza mare");
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, HIGH);
   servo1.write(0);
   servo2.write(40);
   delay(3000);
}

void vitezaMica(){
  Serial.println("Viteza mica");
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW); 
  servo1.write(40);
  servo2.write(0);
  delay(1000);
}

void display1(int dig1)
{
  if(dig1 == 0)
  {
    digitalWrite(41, 0);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 1);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  } else if(dig1 == 1) {
    digitalWrite(41, 0);
    digitalWrite(40, 0);
    digitalWrite(32, 1);
    digitalWrite(31, 0);
    digitalWrite(30, 0);
    digitalWrite(43, 1);
    digitalWrite(42, 0);
  } else if(dig1 == 2) {
    digitalWrite(41, 1);
    digitalWrite(40, 0);
    digitalWrite(32, 0);
    digitalWrite(31, 1);
    digitalWrite(30, 1);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  } else if(dig1 == 3) {
    digitalWrite(41, 1);
    digitalWrite(40, 0);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 0);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  } else if(dig1 == 4) {
    digitalWrite(41, 1);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 0);
    digitalWrite(30, 0);
    digitalWrite(43, 1);
    digitalWrite(42, 0);
  } else if(dig1 == 5) {
    digitalWrite(41, 1);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 0);
    digitalWrite(43, 0);
    digitalWrite(42, 1);
  } else if(dig1 == 6) {
    digitalWrite(41, 1);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 1);
    digitalWrite(43, 0);
    digitalWrite(42, 1);
  } else if(dig1 == 7) {
    digitalWrite(41, 0);
    digitalWrite(40, 0);
    digitalWrite(32, 1);
    digitalWrite(31, 0);
    digitalWrite(30, 0);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  } else if(dig1 == 8) {
    digitalWrite(41, 1);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 1);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  } else if(dig1 == 9) {
    digitalWrite(41, 1);
    digitalWrite(40, 1);
    digitalWrite(32, 1);
    digitalWrite(31, 1);
    digitalWrite(30, 0);
    digitalWrite(43, 1);
    digitalWrite(42, 1);
  }
}


   void display2(int dig2)
{
  if(dig2 == 0)
  {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 1);
    digitalWrite(34, 0);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 1);
  } else if(dig2 == 1) {
    digitalWrite(38, 0);
    digitalWrite(37, 1);
    digitalWrite(36, 0);
    digitalWrite(34, 0);
    digitalWrite(33, 1);
    digitalWrite(39, 0);
    digitalWrite(35, 0);
  } else if(dig2 == 2) {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 1);
    digitalWrite(34, 1);
    digitalWrite(33, 0);
    digitalWrite(39, 0);
    digitalWrite(35, 1);
  } else if(dig2 == 3) {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 0);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 0);
    digitalWrite(35, 1);
  } else if(dig2 == 4) {
    digitalWrite(38, 0);
    digitalWrite(37, 1);
    digitalWrite(36, 0);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 0);
  } else if(dig2 == 5) {
    digitalWrite(38, 1);
    digitalWrite(37, 0);
    digitalWrite(36, 0);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 1);
  } else if(dig2 == 6) {
    digitalWrite(38, 1);
    digitalWrite(37, 0);
    digitalWrite(36, 1);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 1);
  } else if(dig2 == 7) {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 0);
    digitalWrite(34, 0);
    digitalWrite(33, 1);
    digitalWrite(39, 0);
    digitalWrite(35, 0);
  } else if(dig2 == 8) {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 1);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 1);
  } else if(dig2 == 9) {
    digitalWrite(38, 1);
    digitalWrite(37, 1);
    digitalWrite(36, 0);
    digitalWrite(34, 1);
    digitalWrite(33, 1);
    digitalWrite(39, 1);
    digitalWrite(35, 1);
  }
}
void loop() {

  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  if(distance1<20 && distance1>1){
    time_general1=millis();
    if(time_general1!=time1){
        Serial.println("A trecut obiectul prin fata primului senzor");
             Serial.println(distance1);
       time1=time_general1;
       citire_senzor2();
   }
  }
  delay(50);
}
