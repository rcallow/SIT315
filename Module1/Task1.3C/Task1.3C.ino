uint8_t lengthTiltPin = 2;
uint8_t widthTiltPin = 3;
uint8_t outputPin = 13;

volatile bool lengthIsLevel = 1;
volatile bool widthIsLevel = 1;

void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(lengthTiltPin, INPUT);
  pinMode(widthTiltPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(lengthTiltPin), lengthTiltResponse, CHANGE);
  attachInterrupt(digitalPinToInterrupt(widthTiltPin), widthTiltResponse, CHANGE);
  
  Serial.begin(9600);
  Serial.println("Anduino tilt sensing started\n");
}

void loop()
{
  if(isLevel)
  {
    digitalWrite(13, LOW);
    Serial.println("Anduino is level");
  }
  else
  {
    digitalWrite(13, HIGH);
    Serial.println("Anduino is tilted");
  }
  delay(1000);
}

void tiltOneResponse()
{
  isLevel = digitalRead(tiltPinOne);
}

void tiltTwoResponse()
{
  isLevel = digitalRead(tiltPinTwo);
}
