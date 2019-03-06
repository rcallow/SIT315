int inputPin = A0;
int lightLevel = 0;
bool isDark = 0;

void setup()
{
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Anduino light sensing started\n");
}

void loop()
{
  lightLevel = analogRead(inputPin);
  
  if(lightLevel < 30)
  {
    isDark = 1;
    digitalWrite(13, HIGH);
    Serial.println("LED on");
  }
  else
  {
    isDark = 0;
    digitalWrite(13, LOW);
    Serial.println("LED off");
  }
  
  Serial.print("Current light level: ");
  Serial.println(lightLevel);
  delay(1000);
}
