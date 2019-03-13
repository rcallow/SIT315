uint8_t inputPin = 2;
uint8_t outputPin = 13;
bool changeDetected = 0;
bool isLevel = 1;

void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("Arduino tilt sensing started");
}

void loop()
{
  // Test whether the tilt sensor has detected a change
  if(isLevel != digitalRead(inputPin))
  {
    // Record change in tilt status
    changeDetected = 1;
    isLevel = digitalRead(inputPin);
  }
  
  if(changeDetected)
  {
    if(isLevel)
    {
      // Turn on LED at pin 13
      digitalWrite(13, HIGH);
      Serial.println("LED on");
      Serial.println("Arduino is not tilted");
    }
    else
    {
      // Turn off LED at pin 13
      digitalWrite(13, LOW);
      Serial.println("LED off");
      Serial.println("Arduino is tilted");
    }
    // Reset change monitor
    changeDetected = 0;
  }
  // Delay to reduce false readings
  delay(200);
}
