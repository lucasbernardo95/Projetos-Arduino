//Pino do Arduino ao qual o sensor está conectado
int sensor = A0;
int valor = 0;

void setup() {
  // Inicia a comunicação serial para que seja possível exibir
  // Mensagens de log
  Serial.begin(9600);
}

void loop() {
  // Lê o valor detectado pelo sensor
  valor = analogRead(sensor);
  /**
   * Verifica se o valor detectado é maior ou igual a 40
   * Caso essa condição seja verdadeira exibe o valor detectado
   * E printa uma mensagem no minitor serial
   */
  delay(200);
  if(valor >= 40){
    Serial.println("\n\nFogo detectado!!! ");
    Serial.print("Valor coletado: ");
    Serial.println(valor);
    delay(1200);
  } 
}
