int AOUTpin =A5;
   int DOUTpin =2;
   int blue=13;
   int green=12;
   
   int limit;
   int value;

   #include <LiquidCrystal.h>
   LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

void setup() {
      Serial.begin(9600);
      pinMode(DOUTpin,INPUT);
      pinMode(blue,OUTPUT);
      pinMode(green,OUTPUT);
      pinMode(11,OUTPUT);
       
      lcd.begin(16, 2);
      lcd.setCursor(0,0);
      lcd.print("ALCOHOL DETECTOR");
      lcd.setCursor(5,1);
      lcd.print("SYSTEM");
      delay(5000);

}

void loop() {
     value=analogRead(AOUTpin);
     limit=digitalRead(DOUTpin); 
     
     Serial.print("Alcohol value:");
     Serial.println(value);
     Serial.print("Limit:");
     Serial.print(limit);
     delay(100);

if((value>25)&&(value<50))
  {

     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("LEVEL NORMAL");
     
   
    
   
     lcd.setCursor(0,1);
     lcd.print("<*SYSTEM IS ON*>");
     delay(2000);
     
     digitalWrite(green,HIGH);
     delay(100);

     
  }
     lcd.clear();
     lcd.print("ALCOHOL DETECTOR");
     
     lcd.setCursor(2, 1);
     lcd.print("Value:- ");
     lcd.setCursor(10, 1);
     lcd.println(value);
     delay(150);

     
 if(value>500)
  {
     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("LEVEL HIGH!!");
     
     
      lcd.setCursor(0,1);
  
      lcd.print("<SYSTEM IS OFF*>");
      delay(1000);

      digitalWrite(11,HIGH);
     digitalWrite(green,LOW);
     digitalWrite(blue,HIGH);
     delay(100000000); 
     digitalWrite(blue,LOW);
     delay(1000);
     
  }



     lcd.clear();
     lcd.print("ALCOHOL DETECTOR");

     lcd.setCursor(2, 1);
     lcd.print("Value:- ");
     lcd.setCursor(10, 1);
     lcd.println(value);
     delay(150);


     delay(50);

}