// EduKit1 - Basics
// Worksheet 4 - User Input

/*
 * This sketch requires no breadboard components
 * 
 * This code will introduce variables to store information
 * as well as explain how to get input from the user.
 * 
 * Two user functions are also used: 
 *    getUserName() and getUserAddress()
 * 
 * User will be prompted for the following:
 *  1) What is your name?
 *  2) What is your address?
 * 
 * Comments have been placed within the code to remind 
 * you what the code is intended to do.

 */
 
String name;
String address;

void setup() {
  // run once, when the sketch starts

  Serial.begin(9600);       // set up Serial library at 9600 bps

  Serial.println("USER INPUT EXAMPLE");
  Serial.println("");

  Serial.flush();       // Clear Serial Monitor Input Buffer

  name = getUserName();         // prompt user's name
  address = getUserAddress();   // prompt user's address

  Serial.println();
  Serial.println("You entered your name: " + name);
  Serial.println("You entered your address: " + address);
}

void loop() {
  // not used in this example
}

String getUserName() {      // ******* User Defined Function *******
    Serial.println("What is your name?");
      
    while (Serial.available() == 0) ;  // Wait until input buffer ready
    { name = Serial.readStringUntil("\n");  }    // save name in variable 
    return name;
}

String getUserAddress() {   // ******* User Defined Function *******

    // Ask the user how many times they want LED to blink
    Serial.println("What is your address?");
    while (Serial.available() == 0) ;   // Wait until input buffer ready
    { address = Serial.readStringUntil("\n"); }   // save address in variable
    return address;
}

