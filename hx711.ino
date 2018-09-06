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

#include <HX711_ADC.h>

#define SS_PIN 10
#define RST_PIN 9

//HX711 constructor (dout pin, sck pin)
HX711_ADC LoadCell(3, 2);

long t;

void setup() {
  Serial.begin(9600);
  Serial.println("ESPERE");
  LoadCell.begin();
  long stabilisingtime = 2000; // tempo de estabilizacao
  LoadCell.start(stabilisingtime);
  LoadCell.setCalFactor(696.0); // factor de calibracao
  Serial.println("Processo Startup + Tare Completo");
}

void loop() {
  LoadCell.update();

  if (millis() > t + 250) {
    float i = LoadCell.getData();
    Serial.print("Load_cell output val: ");
    Serial.println(i);
    t = millis();
  }

  //RECEBE INFORMACAO DO TERMINAL SERIAL
  if (Serial.available() > 0) {
    float i;
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  //CHECK SE O PROCESSO DE TARE FOI COMPLETO
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare COMPLETO");
  }

}
