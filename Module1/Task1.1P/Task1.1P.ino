int inputPin = 12;
//int lightLevel = 0;
bool isLevel = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  Serial.println("Anduino light sensing started\n");
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
