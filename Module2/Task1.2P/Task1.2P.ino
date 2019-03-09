int inputPin = 2;
//int lightLevel = 0;
bool isLevel = 0;
byte ledStatus = LOW;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("Anduino tilt sensing started\n");
}

void loop()
{
}

void tiltResponse()
{
  ledStatus = HIGH;
  digitalWrite(13, ledStatus);
  delay(500);
  digitalWrite(13, !ledStatus);
}
