#define RedLED 13     // The pin the red LED is connected to
#define YellowLED 12  // The pin the yellow LED is connected to
#define BlueLED 11    // The pin the blue LED is connected to
#define GreenLED 10   // The pin the green LED is connected to

bool redLightOn = false;
bool yellowLightOn = false;

void setup() {
  Serial.begin(9600);   //Opens the serial port, sets data rate to 9600 bps
  //pinMode(relay, OUTPUT);
  pinMode(RedLED, OUTPUT);    // Declare the red LED as an output
  pinMode(YellowLED, OUTPUT); // Declare the yellow LED as an output
  pinMode(BlueLED, OUTPUT);   // Declare the blue LED as an output
  pinMode(GreenLED, OUTPUT);  // Declare the green LED as an output

  digitalWrite(RedLED, LOW);        //Turn the red LED off
  digitalWrite(YellowLED, LOW);     //Turn the Yellow LED off
  digitalWrite(BlueLED, LOW);       //Turn the Blue LED off
  digitalWrite(GreenLED, LOW);    //Turn the Green LED off

}

void loop() {
  //digitalWrite(relay,HIGH);


  if(Serial.available() > 0)
  {
    //incomingByte = Serial.read(); //read the incoming byte
    char c = Serial.read();
    

    if(c == 'A')
    {
      redLightOn = true;
      c = NULL;
    }
    if(c == 'Z')
    {
      redLightOn = false;
      c = NULL;
    }

    if(c == 'R')
    {
      yellowLightOn = true;
    }
    if(c == 'F')
    {
      yellowLightOn = false;
    }

    // if(incomingByte = 30)
    // {
    //   digitalWrite(BlueLED, HIGH);   //Turn the Blue LED On
    // }
    // else
    // {
    //   digitalWrite(BlueLED, LOW);    //Turn the Blue LED off
    // }

    // if(incomingByte = 30)
    // {
    //   digitalWrite(GreenLED, HIGH);   //Turn the Green LED On
    // }
    // else
    // {
    //   digitalWrite(GreenLED, LOW);    //Turn the Green LED off
    // }
    c = NULL;
  }

  if(redLightOn == true){
    digitalWrite(RedLED, HIGH);   //Turn the red LED On
  }else{
    digitalWrite(RedLED, LOW);    //Turn the red LED off
  }

  if(yellowLightOn == true){
    digitalWrite(YellowLED, HIGH);   //Turn the Yellow LED On
  }else{
    digitalWrite(YellowLED, LOW);    //Turn the Yellow LED off
  }
  //delay(1000);
}
