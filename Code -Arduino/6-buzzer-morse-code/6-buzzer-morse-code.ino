// EduKit1 - Basics
// Worksheet 6 - Morse Code (using Buzzer)

/*
 * Keep the same circuit as was used in Worksheet 5.
 * This time, however, you will add a Buzzer.
 * 
 * Place the buzzer on the breadboard straddling the 
 * middle divide.  The longer leg should be connected
 * to digital pin 4.  The other leg should be connected
 * to the ground rail.
 * 
 * When pin 4 is set on, the buzzer will sound.
 * 
 * Based on user input, the buzzer will sound SOS a 
 * specified number of times.
 */

const int BuzzerPin = 4;    // buzzer pin variable
int numTimes = 0;           // variable for number of SOSs

void setup() {
  // run once, when the sketch starts
  Serial.begin(9600);       // set up Serial library at 9600 bps

  pinMode(BuzzerPin, OUTPUT);   // define BuzzerPin as OUTPUT
  digitalWrite(BuzzerPin, LOW); // initialize buzzer to 'off'

  Serial.println("Morse Code");   // display title
  Serial.println("******************************************");
  Serial.println();
  
  numTimes = getNumTimes();     // prompt user for number of times to blink LED
  while (numTimes > 0) {        // loop around the chosen number of times

    numTimes--;                 // decrement numTimes counter
    morse_s();
    letterspace();
    morse_o();
    letterspace();
    morse_s();
    letterspace();
    wordspace();
  }
}

void loop() {
  // not used in this example
}

int getNumTimes() {   // ******* User Defined Function *******

    // Ask the user how many times they want SOS to sound
    Serial.println("How many times would you like SOS to loop? - press ENTER (SEND)");
    while (Serial.available() == 0) ;   // Wait until input buffer ready
      { numTimes = Serial.parseInt(); }   // save numTimes in variable
    return numTimes;
}

void dot() {      // A single Morse dot

  digitalWrite(BuzzerPin, HIGH);
  delay(100);
  digitalWrite(BuzzerPin, LOW);
  delay(100);
}

void dash() {     // A single Morse dash

  digitalWrite(BuzzerPin, HIGH);
  delay(300);
  digitalWrite(BuzzerPin, LOW);
  delay(300);
}

void letterspace() {    // the space between letters

  delay(300);
}

void wordspace() {      // the space between words

  delay(700);
}

void morse_s() {        // the Morse for S, (3 dots)
 
  dot();
  dot();
  dot();
}

void morse_o() {        // the Morse for O, (3 dashes)

  dash();
  dash();
  dash();
}
