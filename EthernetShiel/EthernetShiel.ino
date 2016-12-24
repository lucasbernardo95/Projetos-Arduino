#include <SPI.h>//protocolo serial
#include <Ethernet.h>

//Definição do endereço MAC da placa de rede (48 bits)
byte mac[] = {0xAB, 0xCD, 0x12, 0x34, 0xFF, 0xCA};//pode ser qualquer um

//Configuração da rede
IPAddress ip(192,168,1,2); //Define o endereço ip
IPAddress gateway(192,168,1,1); //Define o gateway
IPAddress subnet(255,255,255,0); //Define a máscara de rede

int l1 = 8, l2 = 9;
int b1 = 6, b2 = 7;
int leitura = 0, leitura2 = 0;

EthernetServer server(80);

void setup() {
  pinMode(l1 ,OUTPUT);
  pinMode(l2 ,OUTPUT);
  pinMode(b1 ,OUTPUT);
  pinMode(b2 ,OUTPUT);
  
  Ethernet.begin(mac,ip,gateway, subnet);//inicializa o Ethernet Shiel
  server.begin();//inicia a conexão com o servidor e o servidor web na porta 80
  Serial.begin(9600);
  Serial.print("serve is at ");
  Serial.println(Ethernet.localIP());
}

void loop(){
  
  leitura = digitalRead(b1);
  
  if (leitura == 1){
    
    digitalWrite(l1, HIGH);
    char mensagem[] = "Botao 1 acionado!!!";
    char mensagem2[] = "Aguardando...";
    apresentaDados(mensagem, mensagem2);
    delay(5000);  
    apresentaDados("Aguardando...", "Aguardando...");
    digitalWrite(l1, LOW);
    
  }

  leitura2 = digitalRead(b2);
  
  if (leitura2 == 1){
    
    digitalWrite(l2 , HIGH);
    char mensagem2[] = "Botao 2 acionado!!!";
    char mensagem[] = "Aguardando...";
    apresentaDados(mensagem, mensagem2);
    delay(5000);  
    apresentaDados("Aguardando...", "Aguardando...");
    digitalWrite(l2, LOW);
    
  }
  
}

void apresentaDados(char msg[],char msg2[]){
  EthernetClient client = server.available();
  if (client){
    Serial.println("new client");
    boolean currentLinesBlank = true;
    while(client.connected()){
      
      if(client.available()){
        char c = client.read();
        Serial.write(c);  
        
        if(c == '\n' && currentLinesBlank){
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");  
          client.println("Connection close");
          client.println("Refresh: 0");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<hmtl>");
          
          client.print("Estado Botao 1: ");
          client.print(msg);
          client.print("<br/>");
          client.print("Estado Botao 2: ");
          client.print(msg2);
          client.print("<br/>");
          client.print("</html>");
          break;
        }if (c == '\n'){
          currentLinesBlank = true;  
        } else if (c !='\r'){
          currentLinesBlank = false; 
        }

      }
        
    } 
    delay(1);
    client.println("<!DOCTYPE HTML>");
    client.println("<hmtl>");
    client.println("<p> client disconnected<p/>"); 
    client.print("</html>");
    client.stop();
    Serial.println("client disconnected"); 
  }
  
}
