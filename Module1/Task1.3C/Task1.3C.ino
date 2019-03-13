uint8_t lengthTiltPin = 2;
uint8_t widthTiltPin = 3;
uint8_t lengthOutputPin = 13;
uint8_t widthOutputPin = 12;

volatile bool lengthIsLevel = 1;
volatile bool widthIsLevel = 1;
volatile bool lengthChangeDetected = 0;
volatile bool widthChangeDetected = 0;

void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(lengthTiltPin, INPUT);
  pinMode(widthTiltPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(lengthTiltPin), lengthTiltResponse, CHANGE);
  attachInterrupt(digitalPinToInterrupt(widthTiltPin), widthTiltResponse, CHANGE);
  
  Serial.begin(9600);
  Serial.println("Arduino tilt sensing started\n");
}

void loop()
{
  if(lengthChangeDetected)
  {
    if(lengthIsLevel)
    {
      digitalWrite(lengthOutputPin, LOW);
      Serial.println("Arduino length is level");
    }
    else
    {
      digitalWrite(lengthOutputPin, HIGH);
      Serial.println("Arduino length is tilted");
    }
    if(widthIsLevel)
    {
      digitalWrite(widthOutputPin, LOW);
      Serial.println("Arduino width is level");
    }
    else
    {
      digitalWrite(widthOutputPin, HIGH);
      Serial.println("Arduino width is tilted");
    }
  }
}

void tiltOneResponse()
{
  isLevel = digitalRead(tiltPinOne);
}

void tiltTwoResponse()
{
  isLevel = digitalRead(tiltPinTwo);
}
