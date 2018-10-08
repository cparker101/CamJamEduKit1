// EduKit1 - Basics
// Worksheet 4 - User Input

/*
 * This sketch is based on the same circuit as was
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
const int YELLOW = 9; // YELLOW led
const int GREEN = 8;  // GREEN LED

int color;
int numTimes;

int loopCtrl;

void setup()                // run once, when the sketch starts
{
  Serial.begin(9600);       // set up Serial library at 9600 bps

  Serial.println("CONTROL LEDs BASED ON USER INPUT");
  Serial.println("");

  Serial.flush();

  color = getColor();             // prompt user for LED color
  numTimes = getNumTimes();          // prompt user for number of times to blink LED

  switch (color) {
    case 1:
     // light up red LED numTimes
      Serial.print("Red LED will blink " + String(numTimes) + " times" );
      for (int i=0; i < numTimes; i++) {
        digitalWrite(RED, HIGH);
        delay(1000);
        digitalWrite(RED, LOW);
        delay(1000);
      }  
      break;

    case 2:
      // light up Yellow LED numTimes
      Serial.print("Yellow LED will blink "  + String(numTimes) + " times" );
      for (int i=0; i < numTimes; i++) {
        digitalWrite(YELLOW, HIGH);
        delay(1000);
        digitalWrite(YELLOW, LOW);
        delay(1000);
      }
      break;

    case 3:
     // light up Green LED numTimes
      Serial.print("Green LED will blink "  + String(numTimes) + " times" );
      for (int i=0; i < numTimes; i++) {
        digitalWrite(GREEN, HIGH);
        delay(1000);
        digitalWrite(GREEN, LOW);
        delay(1000);
      }   
      break;

    default:
      // user entered an invalid color
      Serial.println("invalid color");   
  }
}

void loop() {
  
}

int getColor() {
    // Ask the user which color LED to blink
    Serial.println("Which LED would you like to blink?");
    Serial.println("1: Red?");
    Serial.println("2: Yellow?");
    Serial.println("3: Green?");
    Serial.println("");
    Serial.println("Choose your option - press ENTER");
      
    while (Serial.available() == 0) ;  // Wait here until input buffer has a character
    {
      color = Serial.parseInt();        // save color in variable
    }     
    return color;
}

int getNumTimes() {
    // Ask the user how many times they want LED to blink
    Serial.println("Choose number of times to blink - press ENTER");
    while (Serial.available() == 0) ;
    {
      numTimes = Serial.parseInt();     // save numTimes in variable
    }
    return numTimes;
}

