#define RedLED 13     // The pin the red LED is connected to
#define YellowLED 12  // The pin the yellow LED is connected to
#define BlueLED 11    // The pin the blue LED is connected to
#define GreenLED 10   // The pin the green LED is connected to

bool redLightOn = false;
bool yellowLightOn = false;
bool blueLightOn = false;
bool greenLightOn = false;

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
    
    //Red led Start
    if(c == 'Q')
    {
      redLightOn = true;
    }
    if(c == 'A')
    {
      redLightOn = false;
    }
    //Red led End
    //Yellow led Start
    if(c == 'W')
    {
      yellowLightOn = true;
    }
    if(c == 'S')
    {
      yellowLightOn = false;
    }
    //Yellow led End
    //Blue led Start
    if(c == 'E')
    {
      blueLightOn = true;
    }
    if(c == 'D')
    {
      blueLightOn = false;
    }
    //Blue led End
    //Green led Start
    if(c == 'R')
    {
      greenLightOn = true;
    }
    if(c == 'F')
    {
      greenLightOn = false;
    }
    //Green led End
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

  if(blueLightOn == true){
    digitalWrite(BlueLED, HIGH);   //Turn the Blue LED On
  }else{
    digitalWrite(BlueLED, LOW);    //Turn the Blue LED off
  }

  if(greenLightOn == true){
    digitalWrite(GreenLED, HIGH);   //Turn the Green LED On
  }else{
    digitalWrite(GreenLED, LOW);    //Turn the Green LED off
  }
  //delay(1000);
}
