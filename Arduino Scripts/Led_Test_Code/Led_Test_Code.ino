#define RedLED 13     // The pin the red LED is connected to
#define YellowLED 12  // The pin the yellow LED is connected to
#define BlueLED 11    // The pin the blue LED is connected to
#define GreenLED 10   // The pin the green LED is connected to

void setup() {
  pinMode(RedLED, OUTPUT);    // Declare the red LED as an output
  pinMode(YellowLED, OUTPUT); // Declare the yellow LED as an output
  pinMode(BlueLED, OUTPUT);   // Declare the blue LED as an output
  pinMode(GreenLED, OUTPUT);  // Declare the green LED as an output
}

void loop() {
  digitalWrite(RedLED, HIGH);     // Turn the red LED on
  digitalWrite(YellowLED, HIGH);  // Turn the yellow LED on
  digitalWrite(BlueLED, HIGH);    // Turn the blue LED on
  digitalWrite(GreenLED, HIGH);   // Turn the green LED on
}