//Project Done By Vinayak.Kelagar And Team ( 3 Members )
#include<LiquidCrystal.h>
 LiquidCrystal lcd(12,11,5,4,3,2);

int digitalSensor = 7; 
int pumpPin = 8;

void setup() {
  Serial.begin(9600);
  analogWrite(6,20);
  lcd.begin(16,2);
  pinMode ( digitalSensor, INPUT );
  pinMode ( pumpPin, OUTPUT);
  delay(5000);
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(500);
  Serial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("System is just now On");// The SMS text you want to send
  delay(100);
  Serial.println((char)26); // ASCII code of CTRL+Z
  delay(1000);
}


void loop()
{
  if( digitalRead(digitalSensor) == LOW) 
  {
      digitalWrite(pumpPin,HIGH); 
      {
      lcd.setCursor(2,0); 
      lcd.print("WATER MOTER");
      lcd.setCursor(4,1);
      lcd.print("OFF");
      delay(1000);
      lcd.clear();

      }
  }
  delay(800);
  
 if( digitalRead(digitalSensor) == HIGH)
  {
      digitalWrite(pumpPin,LOW);
      {
      lcd.setCursor(2,0); 
      lcd.print("WATER MOTER");
      lcd.setCursor(4,1);
      lcd.print("ON");
      delay(1000);
      lcd.clear();
      }
  }
  delay(00);
}
