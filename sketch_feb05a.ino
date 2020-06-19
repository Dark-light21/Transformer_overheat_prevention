int buzzer =7;

int Relay = 10;
int Relay1 = 8;
int Relay2 = 9;
void setup() {
   Serial.begin(9600);
   pinMode(buzzer,OUTPUT);
   pinMode(Relay,OUTPUT);
    pinMode(Relay1,OUTPUT);
     pinMode(Relay2,OUTPUT);
}

void loop() {
  int sensorValue1 = analogRead(A0);
  
int sensorValue2 = analogRead(A1);
  
   // read analog volt from sensor and save to variable temp
   sensorValue1 = sensorValue1 * 0.48828125;
    sensorValue2 = sensorValue2 * 0.48828125;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE1 = ");
  Serial.print(sensorValue1); // display temperature value
  Serial.print("*C");
  Serial.print(" ");
   Serial.print("TEMPERATURE2 = ");
    Serial.print(sensorValue2);
   Serial.print("*C");
   Serial.println();
   
   delay(1000); // update sensor reading each one second
   if(sensorValue1<40 && sensorValue1<=sensorValue2)
   {
    digitalWrite(Relay1,HIGH);
    }
   if(sensorValue1>40 && sensorValue1<50 )
   {
   digitalWrite(Relay,HIGH);
   delay (1000);
    
   }
    if(sensorValue1>50)
   {
    digitalWrite(Relay1,LOW);
    delay(1000);
     digitalWrite(Relay2,HIGH);
    }
    if(sensorValue1>50 && sensorValue2>50)
    {
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
       Serial.begin(9600);
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CMGF=1\r");
  delay(1000);
  Serial.print("AT+CMGS=\"+9732706565\"\r");
  delay(1000);
  Serial.print("Transformer is on fire\r");
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
      }
   
}
