//Imclue a biblioteca para o sensor
#include <Thermistor.h>

//Informa a porta que o sensor está conectado, no caso A0
//Necessário passar apenas o número da porta
Thermistor temp(0);

void setup() {
  Serial.begin(9600);
}
void loop() {
  //Recebe o valor coletado pelo sensor
  int temperatura = temp.getTemp();
  //Exibe o valor obtido pelo sensor em graus Celsius
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("*C");
  delay(1000);
}
