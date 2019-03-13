uint8_t inputPin = 2;
uint8_t outputPin = 13;
bool changeDetected = 0;
bool isLevel = 1;

void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("Anduino tilt sensing started");
}

void loop()
{
  if(isLevel != digitalRead(inputPin))
  {
    changeDetected = 1;
    isLevel = digitalRead(inputPin);
  }
  
  if(changeDetected)
  {
    if(isLevel)
    {
      digitalWrite(13, HIGH);
      Serial.println("LED on");
      Serial.println("Arduino is not tilted");
    }
    else
    {
      digitalWrite(13, LOW);
      Serial.println("LED off");
      Serial.println("Arduino is tilted");
    }
    changeDetected = 0;
  }
  delay(200);
}
