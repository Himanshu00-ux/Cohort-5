#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int btnBJP = 2;
int btnJDS = 3;
int btnCONG = 4;
int ledBJP = 8;    // RED
int ledJDS = 9;    // GREEN
int ledCONG = 10;  // YELLOW
int buzzer = 11;
int voteBJP = 0;
int voteJDS = 0;
int voteCONG = 0;

void setup() {
  pinMode(btnBJP, INPUT_PULLUP);
  pinMode(btnJDS, INPUT_PULLUP);
  pinMode(btnCONG, INPUT_PULLUP);
  pinMode(ledBJP, OUTPUT);
  pinMode(ledJDS, OUTPUT);
  pinMode(ledCONG, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Voting System");
  delay(2000);
  lcd.clear();
}

void loop() {
  // ===== BJP =====
  if (digitalRead(btnBJP) == LOW) {
    voteBJP++;
    digitalWrite(ledBJP, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.print("BJP Voted");
    lcd.setCursor(0,1);
    lcd.print("Total: ");
    lcd.print(voteBJP);
    delay(800);
    digitalWrite(ledBJP, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
  }
  // ===== JDS =====
  if (digitalRead(btnJDS) == LOW) {
    voteJDS++
    digitalWrite(ledJDS, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.print("JDS Voted");
    lcd.setCursor(0,1);
    lcd.print("Total: ");
    lcd.print(voteJDS);
    delay(800);
    digitalWrite(ledJDS, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
  }
  // ===== CONG =====
  if (digitalRead(btnCONG) == LOW) {
    voteCONG++;
    digitalWrite(ledCONG, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.print("CONG Voted");
    lcd.setCursor(0,1);
    lcd.print("Total: ");
    lcd.print(voteCONG);
    delay(800);
    digitalWrite(ledCONG, LOW);
    digitalWrite(buzzer, LOW);
    lcd.clear();
  }
}