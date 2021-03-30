
//connect gnd to gnd
// connect vcc to 5v
// connect echo to pin digital pin 12
// connect trig to pin 13
// connect led to 12,10,9,8,7,6,5,4,3,2,
#define echoPin 12 // change here if required. attach pin D12 Arduino to pin Echo 
#define trigPin 13 //attach pin D13 Arduino to pin Trig 
int rangeled[] = {12,10,9,8,7,6,5,4,3,2};
// defines variables
long duration; // variable for the duration of sound wave travel
int distance_cm; // variable for centimeters measurement
int distance_inch; // variable for inches measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);// Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.print("started");
  int arrLen = sizeof(rangeled) / sizeof(rangeled[0]);
  int i;
  for (i=0;i<arrLen;i++) {
    pinMode(rangeled[i],OUTPUT);}

}
void loop() {
   for(int a=0;a<10;a++){
     digitalWrite(rangeled[a], LOW);
   }
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance_cm = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance_inch = duration * 0.0133 / 2; // Speed of sound wave divided by 2 (go and back)
  
  for(int a=0;a<distance_cm;a++){  
  digitalWrite(rangeled[a],HIGH);
  }

}
