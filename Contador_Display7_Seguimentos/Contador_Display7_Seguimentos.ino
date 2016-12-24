
int R = 10;
int G = 11;
int B = 9;

// the setup routine runs once when you press reset:
void setup() {
  //pinos do led
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  
  digitalWrite(R,HIGH);
  digitalWrite(G,0);
  digitalWrite(B,0);
  Serial.println("Acende");
  delay(500);
  digitalWrite(R,LOW);
  Serial.println("Apaga");
  digitalWrite(G,HIGH);
  Serial.println("Acende");
  delay(500);
  digitalWrite(G,LOW);
  digitalWrite(B,HIGH);
  Serial.println("Acende");
  delay(500);
  digitalWrite(B,LOW);
}
