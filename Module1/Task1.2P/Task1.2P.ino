int inputPin = 2;
volatile bool isLevel = 1;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(inputPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(inputPin), tiltResponse, CHANGE);
  
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

void tiltResponse()
{
  isLevel = digitalRead(inputPin);
}
