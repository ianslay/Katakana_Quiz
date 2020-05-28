#include <LiquidCrystal.h>

int score = 0;
int pot = 0;
int row = 0;
int col = 0;
int pick = 1;
char a,b,c,d,p;
int randA,randB,randC,randD,randQ;

const int apin = A0;    // user inputs
const int button = 10;  //

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // LCD pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(button, INPUT);
  lcd.begin(20, 4);
  lcd.display();
  Serial.begin(9600);
  randomSeed(analogRead(5));
  lcd.print("Score:");

}

void loop() {

  lcd.setCursor(6,0);
  lcd.print(score);
  
  randA = random(177,187);
  randB = random(177,187);
  randC = random(177,187);
  randD = random(177,187);
  randQ = random(4)+1;
  
  lcd.setCursor(16,0);
  a = randA + B00000000;
  lcd.print(a);
  lcd.setCursor(16,1);
  b = randB + B00000000;
  lcd.print(b);
  lcd.setCursor(16,2);
  c = randC + B00000000;
  lcd.print(c);
  lcd.setCursor(16,3);
  d = randD + B00000000;
  lcd.print(d);

    for(col=0;col<4;col++){
      lcd.setCursor(15,col);
      lcd.print(" ");
    }
          
      pot = ((analogRead(apin)/270)%4);
      lcd.setCursor(15,pot);
      p = B01111110;
      lcd.print(p);
      Serial.print(pot);
      Serial.print("\n");
      

  lcd.setCursor(0,1);
  lcd.print(randQ);

  score++;
  delay(1000);
}
