// EduKit1 - Basics
// Worksheet 5 - Button

/*
 * In this program, we will add a button to the 
 * breadboard.  The button acts as a switch.  When
 * the switch is not being pressed, the Arduino will
 * recognize a LOW condition; and conversely, a HIGH
 * will be sent when the button is pressed.
 * 
 * A message will be displayed on the Serial Monitor
 * to indicate the state of the button.
 */

 // Declare pin assignments
const int ButtonPin = 2;   // button pin variable
int ButtonValue = 0;      // variable to hold button state
 void setup() {
  
  // setup Serial Monitor - so you can view your output
  // Note that 9600 is the baud rate for the Serial Monitor
  Serial.begin(9600);
  
  // define each LED as an OUTPUT pin:
  pinMode(ButtonPin, INPUT);    // button is INPUT only

  Serial.println("----------------");
  Serial.println("  Button + GPIO ");
  Serial.println("----------------");
 }

void loop() {
  // put your main code here, to run repeatedly:

  ButtonValue = digitalRead(ButtonPin);
  Serial.println(ButtonValue);  // display button's value

  // if the button is NOT pressed, ButtonPin will be 'true'
  if (ButtonValue == HIGH) {
    Serial.flush();         // clears the Terminal window
    Serial.println("Waiting for you to press the button");
    delay(1000);        // wait for 1 second
  }
  else {    // User pressed the button
    Serial.println("Button Pressed");
    Serial.println(ButtonValue);    // display button's value
    delay(1000);                    // wait for 1 second
  }
}
