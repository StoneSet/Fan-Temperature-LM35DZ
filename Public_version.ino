#include<LiquidCrystal.h>
int always10percent=24;
//Set vos temperatures ici
int temp_7=25;
int temp_1=30;
int temp_2=35;
int temp_3=40;
int temp_4=45;
int temp_5=50;
int temp_6=55;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd2(12, 11, 5, 4, 3, 2);
#define pwm 10 //Pin du mosfet
#define led1 6 //Pin de la led Verte
#define led2 7 //Pin de la led Orange
#define led3 8 //Pin de la led Rouge

void setup()
{
 lcd.begin(16, 2);
 
 lcd.clear();
 lcd.print("Fan controlled");
 lcd.setCursor(0,1); //Changer de ligne
 lcd.print("by temp");
 digitalWrite(led1, HIGH); //Allumer led 1
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 delay(2050);
 digitalWrite(led1, LOW); //Eteindre led 1
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 delay(1000); //Attendre une secone
 analogWrite(pwm, 255); //Generer un signal PWM de 255 (Le maximum)
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("   DEVELOPED  ");
 lcd.setCursor(0,1);
 lcd.print("  BY STONESET");
 delay(2000);
 analogWrite(pwm, 255);
 delay(1000);
 analogWrite(pwm, 150);
 delay(1000);
 analogWrite(pwm, 255);
 delay(1000);
 
}
void loop()
{
  int valeur_brute = analogRead(A0); //Lire la valeur analogique sur le pin 0 de l'arduino
  float temp = valeur_brute * (5.0 / 1023.0 * 100.0); //Transformation de la valeur brute en la valeur réelle
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Afficher la temp sur le screen
  lcd.print(" C");
  lcd.setCursor(0,1);

  //Si vous voulez que le texte defile :
    //for (int positionCounter = 0; positionCounter < 21; positionCounter++) {
    //scroll one position left:
    //lcd.scrollDisplayLeft();
    //wait a bit:
    //delay(150);
    //}
  
  if(temp < always10percent )   // Si la temp est plus petite que A
    { 
      analogWrite(pwm, 100);
      lcd.print("Vitesse: 10% -- ");
      delay(100);
      digitalWrite(led1, HIGH);
    }

    else if(temp > temp_7)
    {
      analogWrite(pwm, 170);
      lcd.print("Vitesse: 10%   ");
      delay(100);
      digitalWrite(led1, HIGH);
    }

lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Afficher la temp sur le screen
  lcd.print(" C");
  lcd.setCursor(0,1);
    
  if(temp > temp_1)
    {
      analogWrite(pwm, 200);
      lcd.print("Vitesse: 20%   ");
      digitalWrite(led1, HIGH);
      delay(100);
    }
    
     else if(temp > temp_2)
    {
      analogWrite(pwm, 230);
      lcd.print("Vitesse: 40%   ");
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(100);
    }

lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Afficher la temp sur le screen
  lcd.print(" C");
  lcd.setCursor(0,1);
    
  if(temp > temp_3)
    {
      analogWrite(pwm, 255);
      lcd.print("Vitesse: 60%   ");
      digitalWrite(led2, HIGH);
      delay(100);
    }
    
    else if(temp > temp_4)
    {
      analogWrite(pwm, 204);
      lcd.print("Vitesse: 80%    ");
       digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(100);
    }

lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Afficher la temp sur le screen
  lcd.print(" C");
  lcd.setCursor(0,1);

  if(temp > temp_5)
    {
      analogWrite(pwm, 255);
      lcd.print("Vitesse: 100%   ");
      delay(100);
      digitalWrite(led3, HIGH);
    } 
    else if(temp > temp_6)
    {
      analogWrite(pwm, 255);
      lcd.print("MAXIMUM ATTEINT");
      delay(100);
    } 
  delay(3000);
  
}

