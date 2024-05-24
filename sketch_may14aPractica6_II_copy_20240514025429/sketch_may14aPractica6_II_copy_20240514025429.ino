/*
   Fundacion Kinal
   Centro educativo tecnico laboral kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6 Segunda parte
   Dev: Diego Alejandro Felipe Chis
   Profesor: Alejandro Navas
   Fecha: 24 de mayo de 2024
*/
#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const byte rowCount = 4;
const byte columnCount = 4;
char keys[rowCount][columnCount] = {
  { '1','2','3','A' },
  { '4','5','6','B' },
  { '7','8','9','C' },
  { '*','0','#','D' },
};
const byte rowPin[rowCount] = {11,10,9,8};
const byte columnPin[columnCount] = {7,6,5,4};

Keypad keypad = Keypad(makeKeymap(keys), rowPin, columnPin, rowCount, columnCount);

char password[] = "2023367";
char teclado[7]; 
const int buzzer = 2;
int open = 12;
int on =  13;
int close = A2;
int teclado2 = 0;
Servo motor;

char inf[7];

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(open, OUTPUT);
  pinMode(on, OUTPUT);
  pinMode(close, OUTPUT);
  motor.attach(3);
  Serial.println("Sistema energizado");
  digitalWrite(on, HIGH);
  digitalWrite(close, HIGH);
  motor.write(0);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("   Bienvenido   ");
  char key = keypad.getKey();

  if(key != NO_KEY){
    teclado[teclado2] = key;
    Serial.print(teclado[teclado2]);
    teclado2++;
  }
    if(teclado2 == 7){
      if (teclado[0]==password[0]&&teclado[1]==password[1]&&teclado[2]==password[2]&&teclado[3]==password[3]&&teclado[4]==password[4]&&teclado[5]==password[5]&&teclado[6]==password[6]){
        lcd.setCursor(0, 1);
        lcd.print(" Puerta Abierta ");
        Serial.println(" ");
        Serial.println("Puerta Abierta");
        digitalWrite(open, HIGH);
        digitalWrite(close, LOW);
        for(int i = 0; i < 2; i++){
          tone(buzzer, 500);
          delay(250);
          noTone(buzzer);
          delay(250);
        }
        while(digitalRead(open) == HIGH){
          for(int i1 = 0; i1 < 180; i1++){
            motor.write(i1);
            delay(10);
          }
          for(int i2 = 180; i2 > 0; i2--){
            motor.write(i2);
            delay(10);
          }
        }
        delay(1000);
      }else if(teclado != password){
        lcd.setCursor(0, 1);
        lcd.print(" Puerta Cerrada ");
        Serial.println(" ");
        Serial.println("Puerta Cerrada");
        digitalWrite(close, HIGH);
        for(int i3 = 0; i3 < 5; i3++){
          tone(buzzer, 500);
          delay(250);
          noTone(buzzer);
          delay(250);
        }
        delay(1000);
      }
    }
  if(Serial.available()>0){
    size_t datos = Serial.readBytesUntil('\n', inf, 7);
    for(int i4 = 0; i4 < datos; i4++){
      Serial.print(inf[i4]);
    }
    Serial.println(" ");
  if(inf[0]==password[0]&&inf[1]==password[1]&&inf[2]==password[2]&&inf[3]==password[3]&&inf[4]==password[4]&&inf[5]==password[5]&&inf[6]==password[6]){
    lcd.setCursor(0, 1);
    lcd.print(" Puerta Abierta ");
    Serial.println(" ");
    Serial.println("Puerta Abierta");
    digitalWrite(open, HIGH);
    for(int i = 0; i < 2; i++){
      tone(buzzer, 500);
      delay(250);
      noTone(buzzer);
      delay(250);
    }
    while(digitalRead(open) == HIGH){
      for(int i1 = 0; i1 < 180; i1++){
        motor.write(i1);
        delay(10);
      }
      for(int i2 = 180; i2 > 0; i2--){
        motor.write(i2);
        delay(10);
      }
    }
  }else if(inf != password){
    lcd.setCursor(0, 1);
    lcd.print(" Puerta Cerrada ");
    Serial.println(" ");
    Serial.println("Puerta Cerrada");
    digitalWrite(close, HIGH);
    for(int i3 = 0; i3 < 5; i3++){
      tone(buzzer, 500);
      delay(250);
      noTone(buzzer);
      delay(250);
    }
    delay(1000);
  }
  }
}