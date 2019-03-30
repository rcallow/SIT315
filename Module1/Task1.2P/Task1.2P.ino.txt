uint8_t inputPin = 2;
uint8_t outputPin = 13;
volatile bool isLevel = 1;
volatile bool changeDetected = 0;


void setup()
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);

  // Attach external interrupt to the data pin
  attachInterrupt(digitalPinToInterrupt(inputPin), tiltResponse, CHANGE);

  // Start serial output
  Serial.begin(9600);
  Serial.println("Arduino tilt sensing started");
}


void loop()
{
  // If an interrupt has occurred
  if(changeDetected)
  {
    if(isLevel)
    {
      // Turn off LED if board is not tilted
      digitalWrite(outputPin, LOW);
      Serial.println("Arduino is not tilted");
    }
    else
    {
      // Turn on LED if board is tilted
      digitalWrite(outputPin, HIGH);
      Serial.println("Arduino is tilted");
    }
  // Reset interrupt monitor
  changeDetected = 0;
  }
}


// Interrupt routine
void tiltResponse()
{
  changeDetected = 1;
  // When the board is level, inputPin reads as 1
  isLevel = digitalRead(inputPin);
}
