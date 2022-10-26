#define RedLED 13     // The pin the red LED is connected to
#define YellowLED 12  // The pin the yellow LED is connected to
#define BlueLED 11    // The pin the blue LED is connected to
#define GreenLED 10   // The pin the green LED is connected to

int incomingByte = 0; // for incoming serial data
int relay = 7;
int relay2 = 6;
int relay3 = 5;
int relay4 = 4;

void setup() {
  Serial.begin(9600);   //Opens the serial port, sets data rate to 9600 bps
  pinMode(relay, OUTPUT);
  pinMode(RedLED, OUTPUT);    // Declare the red LED as an output
  pinMode(YellowLED, OUTPUT); // Declare the yellow LED as an output
  pinMode(BlueLED, OUTPUT);   // Declare the blue LED as an output
  pinMode(GreenLED, OUTPUT);  // Declare the green LED as an output

}

void loop() {
  //digitalWrite(relay,HIGH);


  if(Serial.available() > 0)
  {
    incomingByte = Serial.read(); //read the incoming byte

    if(incomingByte > 49.5)
    {
      digitalWrite(BlueLED, HIGH);
      digitalWrite(relay, LOW);
      digitalWrite(relay2, LOW);
    }
    else
    {
      digitalWrite(BlueLED, LOW);
      digitalWrite(relay, HIGH);
      digitalWrite(relay, HIGH);
    }
  }
}
