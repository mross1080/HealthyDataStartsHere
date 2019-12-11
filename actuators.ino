
int bottomRight = 12;
int bottomMiddle = 13;
int centerMiddle = 11;

const int buttonPin = 8;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

const int trigPin = 5;
const int echoPin = 4;

// defines variables
long duration;
int distance;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600); // Starts the serial communic`ation
  // initialize the digital pin as an output.
  pinMode(bottomRight, OUTPUT);
  pinMode(bottomMiddle, OUTPUT);
  pinMode(centerMiddle, OUTPUT);

  digitalWrite(bottomMiddle, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(bottomRight, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(centerMiddle, LOW);   // turn the LED on (HIGH is the voltage level)



}


int delayTime = 300;
// the loop routine runs over and over again forever:

int getDistanceUltrasound() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

boolean interruptLoop = false;

void loop() {


  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    // turn LED on:
    if (!interruptLoop) {
      Serial.println("started interrupt");

      digitalWrite(bottomMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(55);
      digitalWrite(bottomRight, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(55);
      digitalWrite(centerMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(55);
      interruptLoop = true;

      //
    }

    int sensorDistance =   getDistanceUltrasound();

    if (sensorDistance < 10 && sensorDistance != 0) {

      lowThenHigh();


    }




  } else {
    //    Serial.println(buttonState);
    if (interruptLoop) {
      Serial.println("flip switched, returning to loop");

      digitalWrite(bottomMiddle, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(55);
      digitalWrite(bottomRight, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(55);
      digitalWrite(centerMiddle, LOW);   // turn the LED on (HIGH is the voltage level)
      interruptLoop = false;

    }
  }

  //    // Broke out of loop reset everything to low state

  //


  //  lowThenHigh();
  //    if (sensorDistance < 10 && sensorDistance != 0) {
  //

  delay(100);
  // wait for a second
}



void lowThenHigh() {

  //
  //    delay(200);
  //    digitalWrite(bottomMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
  //    delay(55);
  //    digitalWrite(bottomRight, HIGH);   // turn the LED on (HIGH is the voltage level)
  //    delay(55);
  //    digitalWrite(centerMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
  //    delay(55);
  //    delay(200);

  // wait for a second
  digitalWrite(bottomMiddle, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  digitalWrite(bottomMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);
  delay(1000);
  //




  digitalWrite(bottomRight, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  digitalWrite(bottomRight, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);
  //  //  //
  //  //  // wait for a second
  delay(1000);
  //
  //  //
  //
  digitalWrite(centerMiddle, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  digitalWrite(centerMiddle, HIGH);   // turn the =LED on (HIGH is the voltage level)
  delay(delayTime);

  ////  // wait for a second
  delay(1000);
  //


}


void highThenLow() {


  delay(1000);
  digitalWrite(bottomMiddle, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(55);
  digitalWrite(bottomRight, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(55);
  digitalWrite(centerMiddle, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(55);
  delay(1000);



  digitalWrite(bottomMiddle, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(bottomMiddle, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  delay(1000);
  //



  digitalWrite(bottomRight, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);
  digitalWrite(bottomRight, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);
  //  //  //
  //  //  // wait for a second
  delay(1000);
  //
  //
  digitalWrite(centerMiddle, HIGH);   // turn the =LED on (HIGH is the voltage level)
  delay(delayTime);
  digitalWrite(centerMiddle, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);

  ////  // wait for a second
  delay(1000);



}

