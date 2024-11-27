#include <ESP8266WiFi.h> // incluindo a biblioteca wifi

//variáveis com nome da rede e senha
char ssid [] = "redesiot";
char senha[] = "a1234567";

//definindo o servidor HTTP na porta 80
WiFiServer server(80);

//aqui vamos chamar função que irá efetuar a conexão na rede wifi
void conectarWiFi(char SSID[], char SENHA[])
{
  Serial.print("Conectando a rede");
  Serial.println(SSID);

  WiFi.begin(SSID, SENHA); //inicia a conexão wifi

/* enquanto o wifi não conecta ele fica printando um ponto a cada 0,5s */
while(WiFi.status () != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}

/* quando conectar - vai apresentar a mensagem e o IP */
Serial.println(" ");
Serial.println("Wifi conectado");
Serial.println("Endereço de IP: ");
Serial.println(WiFi.localIP());
}

void setup(){
  Serial.begin(115200);
  delay(10);
  //chama a função dentro do setup
  conectarWiFi(ssid,senha);

  //inicialização do servidor
  server.begin();
  //informando ao usuário que foi inicializado
  Serial.println("Servidor Inicializado");
}

void loop(){
  WiFiClient client = server.available();
  if(!client){
    return;
  }

  while(!client.available()){
    delay(1);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta http-equiv='refresh' content='2' charset='UTF-8'>"); // atualiza a página a cada 2s.
  client.println("<h1>Introdução ao IoT com ESP8266</h1>");
  client.println("<h2>Seja Bem Vindo (a) ao Senai...!</h2>");
  client.println("<h2>Miguel Sacardo Lalla Rosa</h2>");
  client.println("</html>");
}