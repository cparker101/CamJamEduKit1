// EduKit1 - Basics
// Worksheet 3 - Blinking LEDs

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
 *  
 *  To make the LEDs BLINK, you will turn the LEDs on
 *  and then off twice, with one second in between each
 *  change.
 *  
 *  NOTE: This code will run in the loop() function,
 *  which runs forever ...
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
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Lights Off");

 // first, now turn on all three lignts
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, HIGH);

  // wait one second
  delay(1000);      // 1000 milliseconds = 1 second

  // then, then off all three lights
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  // wait one second
  delay(1000);      // 1000 milliseconds = 1 second
}
