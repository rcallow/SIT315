int inputPin = 2;
//int lightLevel = 0;
bool isLevel = 0;
volatile byte ledStatus = LOW;

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
    digitalWrite(13, ledStatus);
}

void tiltResponse()
{
  ledStatus = !ledStatus;
}
