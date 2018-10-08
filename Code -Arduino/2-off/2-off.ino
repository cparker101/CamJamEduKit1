// EduKit1 - Basics
// Worksheet 2 - Turn Off LEDs

/*
 * In this program, you will be connecting three LEDs
 * to the GPIO Header pins of your Arduino, and using
 * this Arduino sketch to turn the LEDs on and OFF
 * 
 *  The power for each LED will be provided from GPIO
 *  pins 10, 9, and 8 for the Red, Yellow and Green LEDs
 *  respectively.
 *  
 *  When they are 'taken high', which means they output
 *  5 volts, the LEDs will light.
 *  
 *  When they are 'taken low', which means they output
 *  0 volts, the LEDs will turn off.
 *  
 *  Each LED is connected to a 220 ohm resistor which 
 *  will limit the curent that can flow through the LED
 */

 // Declare pin assignments
 const int RED = 10;
 const int YELLOW = 9;
 const int GREEN = 8;

 void setup() {
  
  // setup Serial Monitor - so you can view your output
  // Note that 9600 is the baud rate for the Serial Monitor
  Serial.begin(9600);

  // define each LED as an OUTPUT pin:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  Serial.println("Lights Off");

 // now turn off all three lignts
 
 /* (they are all remain on until will unplug the
  *  *  Arduino - don't worry, in the next exercise
  *  will will write another sketch to turn them off
  */

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
