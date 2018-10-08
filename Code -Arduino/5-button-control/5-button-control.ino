// EduKit1 - Basics
// Worksheet 5 - Control Start of User Input based on button

/*
 * This sketch is based on the same circuit that was
 * used in Worksheet4.  This time, however,
 * you will not begin accepting input from the user 
 * until a button has been pressed.
 * 
 * In this program, we will add a button to the 
 * breadboard.  The button acts as a switch.  
 * 
 * When the button is not being pressed, current will 
 * flow between the 5v power rail, through the resistor
 * and to the ButtonPin; causing a HIGH condition.
 *    Message "Waiting for you to press the button"
 * 
 * When the button is pressed, the current takes 
 * another route.  It also goes from the resistor,
 * through the ButtonPin and back to ground (0v). 
 * This splits enough of the current off so that 
 * the voltage across the button is much lower, causing
 * a LOW condition.
 *    User input will begin
 */

const int ButtonPin = 2;    // button pin variable
int ButtonValue = 0;        // variable to hold button state

const int RED = 10;     // RED led
const int YELLOW = 9;   // YELLOW led
const int GREEN = 8;    // GREEN LED

int color;
int numTimes;

void setup() {
  // run once, when the sketch starts

  Serial.begin(9600);       // set up Serial library at 9600 bps

  /* ************* WAIT FOR BUTTON PRESS *********** */
  // define ButtonPin as INPUT pin:
  pinMode(ButtonPin, INPUT);

  Serial.println("Waiting for you to press the button");

  while (digitalRead(ButtonPin) == HIGH) {
    // program will remain here until button is pressed
    // pause Serial Monitor from any input until button pressed
    Serial.end();
  }

  Serial.begin(9600);   // reopen Serial Monitor
  
  Serial.println();
  Serial.println("***************");
  /* ****** BUTTON HAS BEEN PRESSED - CONTINUE  ******/

  color = getColor();             // prompt user for LED color
  numTimes = getNumTimes();       // prompt user for number of times to blink LED

  switch (color) {
    case 1:
      Serial.println("RED blinking " + String(numTimes) + " times (max 10)" );
      blinkLed(RED);        // light up red LED numTimes
      break;

    case 2:
      Serial.println("YELLOW blinking "  + String(numTimes) + " times (max 10)" );
      blinkLed(YELLOW);     // light up Yellow LED numTimes
      break;

    case 3:
      Serial.println("GREEN blinking "  + String(numTimes) + " times (max 10)" );
      blinkLed(GREEN);      // light up Green LED numTimes
      break;

    default:
      // user entered an invalid color
      Serial.println("invalid color");   
  }
}

void loop() {
  // not used in this example
}

int getColor() {      // ******* User Defined Function *******

    // Ask the user which color LED to blink
    Serial.println("Which LED would you like to blink?");
    Serial.println("1: Red?");
    Serial.println("2: Yellow?");
    Serial.println("3: Green?");
    Serial.println("");
    Serial.println("Choose your option - press ENTER (SEND)");

    while (Serial.available() == 0) ;  // Wait until input buffer ready
      { color = Serial.parseInt();  }    // save color in variable 
    return color;
}

int getNumTimes() {   // ******* User Defined Function *******

    // Ask the user how many times they want LED to blink
    Serial.println("Choose number of times to blink - press ENTER (SEND)");
    while (Serial.available() == 0) ;   // Wait until input buffer ready
      { numTimes = Serial.parseInt(); }   // save numTimes in variable
    return numTimes;
}

void blinkLed(int led) {  // ******* User Defined Function *******

  // turn on chosen LED for numTimes (max 10)
  if (numTimes > 10) numTimes = 10;
  
  for (int i=0; i < numTimes; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }     
}

