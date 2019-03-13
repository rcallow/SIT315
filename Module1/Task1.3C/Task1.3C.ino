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
  pinMode(lengthOutputPin, OUTPUT);
  pinMode(widthOutputPin, OUTPUT);
  pinMode(lengthTiltPin, INPUT);
  pinMode(widthTiltPin, INPUT);

  // Attach interrupts to both tilt sensors
  attachInterrupt(digitalPinToInterrupt(lengthTiltPin), lengthTiltResponse, CHANGE);
  attachInterrupt(digitalPinToInterrupt(widthTiltPin), widthTiltResponse, CHANGE);
  
  Serial.begin(9600);
  Serial.println("Arduino tilt sensing started\n");
}

void loop()
{
  // If length-tilt interrupt has occurred
  if(lengthChangeDetected)
  {
    if(lengthIsLevel)
    {
      // Turn off yellow LED
      digitalWrite(lengthOutputPin, LOW);
      Serial.println("Arduino length is level");
    }
    else
    {
      // Turn on yellow LED
      digitalWrite(lengthOutputPin, HIGH);
      Serial.println("Arduino length is tilted");
    }
    // Reset length interrupt detector
    lengthChangeDetected = 0;
  }
  // If width-tilt interrupt has occurred
  if(widthChangeDetected)
  {
    if(widthIsLevel)
    {
      // Turn on blue LED
      digitalWrite(widthOutputPin, LOW);
      Serial.println("Arduino width is level");
    }
    else
    {
      // Turn on blue LED
      digitalWrite(widthOutputPin, HIGH);
      Serial.println("Arduino width is tilted");
    }
    // Reset width interrupt detector
    widthChangeDetected = 0;
  }
}

void lengthTiltResponse()
{
  // Set length interrupt detector
  lengthChangeDetected = 1;
  lengthIsLevel = digitalRead(lengthTiltPin);
}

void widthTiltResponse()
{
  // Set width interrupt detector
  widthChangeDetected = 1;
  widthIsLevel = digitalRead(widthTiltPin);
}
