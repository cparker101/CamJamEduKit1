/*
 * This will be our first Arduino program
 * It will simply print Hello World! to the Serial Monitor
 * 
 * Note that all these lines are considered as comments
 *  They will be ignored by Arduino when the program runs
 */
 
 void setup() {

  // setup Serial Monitor - so you can view your output
  // Note that 9600 is the baud rate for the Serial Monitor
  Serial.begin(9600);

  // print Hello World!
  Serial.println("Hello World!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
