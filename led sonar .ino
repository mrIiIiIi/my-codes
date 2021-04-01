#define echoPin 12 // attach pin D12 Arduino to pin Echo 
#define trigPin 13 //attach pin D13 Arduino to pin Trig 
int ledpin[] = {11,10,9,8,7,6,5,4,3,2}; //connect leds to these pins 11,10,9,8,7,6,5,4,3,2
int noofleds = 10;//enter the no of leds
int range = 300;//enter the range of sensor use minimum 20 maximum 300
long duration; // variable for the duration of sound wave travel !dont change
int distance; // variable for the distance measurement !dont change

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("started"); // print some text in Serial Monitor
 for(int i=0;i<=noofleds;i++){
    pinMode(ledpin[i],OUTPUT);
  }

  Serial.println("All ok");
}




void loop() {
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
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int vali = range/noofleds;
  
  for(int i = 0;i<=noofleds-1;i++){
    if(distance<=i*vali){
      digitalWrite(ledpin[i],HIGH);
    }
    else{
      digitalWrite(ledpin[i], LOW);
   }
   
  }
  
  //gitalWrite(ledpin[1],LOW);
   Serial.println(vali);
  
}
