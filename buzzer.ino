  /////////////////////
//       TI-Trash      //
//                     //
//       Autores:      //
//   Tiago Goncalves   //
//  Alexandre Salgado  //
// ------------------- //
//     com ajuda de    //
// Dr. Fernando Moita  //
  /////////////////////

//Testado com Arduino Uno

#include <Wire.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

//BUZZER
int BUZZER = 4;

void setup(){
  
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
}

void loop(){
  tone(BUZZER, 200);
  delay(2500);
  tone(BUZZERM 500);
}
