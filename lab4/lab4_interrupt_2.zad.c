
class flasher{
  
  int ledPinB;       // the number of the LED pin
  long OnTimeB;     // milliseconds of on-time
  long OffTimeB;    // milliseconds of off-time

  int ledStateB;             		// ledState used to set the LED
  unsigned long previousMillisB;  	// will store last time LED was updated

  public:
  flasher(int pin, long ontime, long offtime){
    ledPinB = pin;
    OnTimeB = ontime;
    OffTimeB = offtime;
    pinMode(ledPinB, OUTPUT);
    
    ledStateB = LOW;
    previousMillisB = 0;
  }
  
  void Update(long currentMillis){
     
  if((ledStateB == HIGH) && (currentMillis - previousMillisB >= OnTimeB)){
    ledStateB = LOW;  // Turn it off
    previousMillisB = currentMillis;  // Remember the time
    digitalWrite(ledPinB, ledStateB);  // Update the actual LED
  }
  else if ((ledStateB == LOW) && (currentMillis - previousMillisB >= OffTimeB)){
    ledStateB = HIGH;  // turn it on
    previousMillisB = currentMillis;   // Remember the time
    digitalWrite(ledPinB, ledStateB);	  // Update the actual LED
  }
  }

};

flasher ledB(13, 100, 200);
flasher ledR(12, 200, 600);
flasher ledO(11, 300, 900);

void setup(){
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}

void loop(){
  delay(1000);
}

SIGNAL(TIMER0_COMPA_vect){
  unsigned long currentMillis = millis();

  ledB.Update(currentMillis);
  ledR.Update(currentMillis);
  ledO.Update(currentMillis);
}

