// EduKit1 - Basics
// Worksheet 7 - Traffic Light Simulation

/*
 * In this project, you will probram a traffic
 * light simulator using the same circuit from
 * Workksheet 6.
 * 
 * Using techniques earned in earlier lessons, your
 * aim is to make the traffic lights work like
 * standard UK Pelican Crossing:
 * 
 *    One set of LEDs act as signals to vehicles
 *    The other set of LEDs act as pedestrian signals
 */

// set up variables for the LED, Buzzer and Button pins
const int ButtonPin = 2;    // button pin variable
int ButtonValue = 0;        // variable to hold button state
int BuzzerPin = 4;          // buzzer pin variable

const int REDDriver = 10;     // RED led (driver)
const int YELLOWDriver = 9;   // YELLOW led (driver)
const int GREENDriver = 8;    // GREEN LED (driver)

const int REDPed = 7;     // RED led (pedestrian)
const int YELLOWPed = 6;   // YELLOW led (pedestrian)
const int GREENPed = 5;    // GREEN LED (pedestrian)

// control variables
boolean buttonnotpressed;
int startTime;
int now;
int elapsedTime;

void setup() {
  // run once, when the sketch starts

  Serial.begin(9600);       // set up Serial library at 9600 bps

  // setup each of the input (button), and output (LEDs, Buzzer) pins
  pinMode(ButtonPin, INPUT);
  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, LOW);

  pinMode(REDDriver, OUTPUT);
  pinMode(YELLOWDriver, OUTPUT);
  pinMode(GREENDriver, OUTPUT);
  pinMode(REDPed, OUTPUT);
  pinMode(YELLOWPed, OUTPUT);
  pinMode(GREENPed, OUTPUT);

  digitalWrite(YELLOWDriver, LOW);
  digitalWrite(REDPed, HIGH);
  digitalWrite(GREENPed, LOW);

  Serial.println("Traffic Light Simulation");

  // initialize the traffic lights
  startgreen();
}

/* define a function for the initial state 
 * Driver - Green LED on, rest off)
 * Pedestrian - Red LED on, rest off)
 */

 void startgreen() {
  digitalWrite(REDDriver, LOW);
  digitalWrite(YELLOWDriver, LOW);
  digitalWrite(GREENDriver, HIGH);

  digitalWrite(REDPed, HIGH);
  digitalWrite(YELLOWPed, LOW);
  digitalWrite(GREENPed, LOW);
 }

 /* turn the green off and yellow on for 3 seconds
  *  ('Pedestrian' red LED stays lit)
  */

 void steadyyellow() {
   Serial.println("steadyyellow()");
   digitalWrite(GREENDriver, LOW);
   digitalWrite(YELLOWDriver, HIGH);
   delay(3000);
 }

  /* turn the yellow off, and then the red on for 
   *  1 second
   */

void steadyred() {
  Serial.println("steadyred()");
  digitalWrite(YELLOWDriver, LOW);
  digitalWrite(REDDriver, HIGH);
  delay(1000);
}


/* sound the buzzer for 4 secondds
 *  (also, for the 'pedestrian' LEDs, turn the red off and green on)
 */

 void startwalking() {
   Serial.println("startwalking()");
   digitalWrite(YELLOWPed, HIGH);
   delay(4000);
   digitalWrite(REDPed, LOW);
   digitalWrite(YELLOWPed, LOW);
   digitalWrite(GREENPed, HIGH);

   int i = 10;
   while (i > 0) {
      digitalWrite(BuzzerPin, HIGH);
      delay(300);
      digitalWrite(BuzzerPin, LOW);
      delay(600);
      i--;
   }
 }

 /* make the buzzer on and off, half a second of
  *  sound followed by half a second of silence
  *  
  *  turn the buzzer off and wait for 2 seconds
  *  flash the pedestrian Green on and off for the two seconds
  */

 void dontwalk() {
   Serial.println("dontwalk()");
   digitalWrite(GREENPed, LOW);
   delay(1000);
   digitalWrite(YELLOWPed, HIGH);
   delay(1000);
}

/* flash the yellow on and off for 4 seconds
 *  and the green 'pedestrian' LED also
 */

void flashingambergreen() {
    Serial.println("flashingambergreen()");

    digitalWrite(REDPed, LOW);
    delay(1000);
    
    int i = 2;
    while(i > 0) {
      digitalWrite(YELLOWDriver, HIGH);
      delay(1000);
      digitalWrite(YELLOWDriver, LOW);
      delay(1000);

      digitalWrite(YELLOWPed, HIGH);
      delay(1000);
      digitalWrite(YELLOWPed, LOW);
      delay(1000);
      i--;    
    }
}

/* flash the amber for one more second
 *  (turn the green 'pedestrian' LED off and the red on)
 */

void flashingyellow() {
    Serial.println("flashinyellow()");
    digitalWrite(YELLOWDriver, LOW);
    delay(1000);

    digitalWrite(GREENPed, LOW);
    digitalWrite(REDPed, HIGH);

    digitalWrite(GREENDriver, HIGH);
    digitalWrite(REDDriver, LOW);
}

/* go through the entire traffic light sequence by
 *  calling each function one after the other
 */

void trafficlightsequence() {
    steadyyellow();
    steadyred();
    startwalking();
    dontwalk();
    flashingambergreen();
    flashingyellow();
}

void loop() {

  /* here is the loop that waits at least 20 seconds before
   *  stopping the cars if the button has been pressed
   */
  
  buttonnotpressed = true;      // button has not been pressed
  startTime = millis();       // records the current time

  while(buttonnotpressed) {
    delay(100);       // wait for 0.1s
    if (digitalRead(ButtonPin) == LOW) {
        now = millis();       // current time now
        buttonnotpressed = false;   // button has been pressed

        elapsedTime = now - startTime;
        Serial.println(elapsedTime);
        if (elapsedTime >= 0 && elapsedTime < 20000) {  // if under 20 seconds (20000 milliseconds)
          delay(20000 - elapsedTime);   // wait until 20s is up
        } else {
          delay(5000);            // wait for 5s (slow pedestrian traffic)
        }
        trafficlightsequence();   // run the trafic light sequence
    }
  }
}


