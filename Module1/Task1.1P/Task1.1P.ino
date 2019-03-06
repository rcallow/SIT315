int inputPin = A0;
int lightLevel = 0;

void setup()
{
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(inputPin);
  
  if(lightLevel < 30)
  {
    Serial.println("LED on");
  }
  else
  {
    Serial.println("LED off");
  }
  
  Serial.print("Current light level: ");
  Serial.println(lightLevel);
  delay(1000);
}
