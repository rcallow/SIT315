uint8_t inputPin = 2;
uint8_t outputPin = 13;
volatile bool isLevel = 1;
volatile bool changeDetected = 0;


void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(inputPin), tiltResponse, CHANGE);
  
  Serial.begin(9600);
  Serial.println("Anduino tilt sensing started");
}


void loop()
{
  if(changeDetected)
  {
    if(isLevel)
    {
      digitalWrite(outputPin, HIGH);
      Serial.println("Anduino is level");
    }
    else
    {
      digitalWrite(outputPin, LOW);
      Serial.println("Anduino is tilted");
    }
  changeDetected = 0;
  }
}


void tiltResponse()
{
  changeDetected = 1;
  isLevel = digitalRead(inputPin);
}
