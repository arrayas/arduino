const byte ldrPin = A0;
const int ledPin = 2;

void setup()
{
   Serial.begin(9600);
   Serial.println("LDR Test Program");
   pinMode(ledPin, OUTPUT);
}

void loop()
{
   static unsigned long timer = 0;
   unsigned long interval = 1000;
   if (millis() - timer >= interval)
   {
      timer = millis();
      int ldrReading = analogRead(ldrPin);
      Serial.print("ldr reading = ");
      Serial.println(ldrReading);
      if (ldrReading > 100){
        digitalWrite(ledPin, LOW);
        delay(1000);
      }
      else {
        digitalWrite(ledPin, HIGH);
        delay(1000);
      }
   }
}
