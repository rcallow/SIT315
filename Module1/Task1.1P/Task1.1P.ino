uint8_t inputPin = 2;
uint8_t outputPin = 13;
bool changeDetected = 0;
bool isLevel = 0;

void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("Anduino tilt sensing started");
}

void loop()
{
  isLevel = digitalRead(inputPin);

  if(isLevel)
  {
    digitalWrite(13, HIGH);
    Serial.println("LED on");
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.println("LED off");
  }
  if(isLevel)
  {
    Serial.print("Arduino is not tilted");
  }
  else
  {
    Serial.println("Arduino is tilted");
  }
  delay(1000);
}
