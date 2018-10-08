// EduKit1 - Basics
// Worksheet 4 - Control Leds Based on User Input

/*
 * This sketch is based on the same circuit that was
 * used in Worksheets 1 thru 3.  This time, however,
 * you are going to control the LEDs with user input.
 * 
 * This code will introduce variables to store information
 * as well as explain how to get input from the user.
 * 
 * Two user functions are also used: 
 *    getColor() and getNumTimes()
 * 
 * User will be prompted for the following:
 *  1) Which color LED should be BLINKED
 *  2) How many times should the LED blink
 * 
 * Comments have been placed within the code to remind 
 * you what the code is intended to do.

 */

const int RED = 10;     // RED led
const int YELLOW = 9;   // YELLOW led
const int GREEN = 8;    // GREEN LED

int color;
int numTimes;

void setup() {
  // run once, when the sketch starts

  Serial.begin(9600);       // set up Serial library at 9600 bps

  Serial.println("CONTROL LEDs BASED ON USER INPUT2");
  Serial.println("");

  Serial.flush();       // Clear Serial Monitor Input Buffer

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

