/*
   Fundacion Kinal
   Centro educativo tecnico laboral kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6 primera parte
   Dev: Diego Alejandro Felipe Chis
   Profesor: Alejandro Navas
   Fecha: 24 de mayo de 2024
*/
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
}
void loop() {
  lcd.setCursor(0,0);
  lcd.print("Diego");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("2023367");
  delay(1000);
}