int tiltPinOne = 2;
int tiltPinTwo = 3;
volatile bool isLevel = 1;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(tiltPinOne, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(tiltPinOne), tiltOneResponse, CHANGE);
  attachInterrupt(digitalPinToInterrupt(tiltPinTwo), tiltTwoResponse, CHANGE);
  
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
