// Inclusão de bibliotecas
#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// Insira as credenciais da sua rede Wi-Fi
// Credenciais da rede Wi-Fi (simulada pelo Wokwi)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Cria o objeto "client"
WiFiClient  client;

// Define um nome para o canal de envio dos dados
unsigned long myChannelNumber = 1;

// Define uma variável que recebe a código chave de escrita da API 
// (que copiamos da nossa configuração da API do ThingSpeak)
const char * myWriteAPIKey = "SRP39AE9OTYCJOV9";

// Variáveis de tempo
unsigned long lastTime = 0;

// O ciclo de postagens no ThingSpeak será de 30 segundos.
unsigned long timerDelay = 30000;

//variaveis
float temperatura;
int statusLED_V;
int statusLED_A;

#define LED_V 12
#define LED_A 23
#define dhtPin 5

// Define o sensor como DHT22
#define DHTTYPE DHT22

// Cria o objeto "dht"
DHT dht(dhtPin, DHTTYPE);

// Rotina de configuração
void setup() {

  // Inicializa a porta serial com baud rate de 115200 bits/segundo
  Serial.begin(115200);

  // Conecta à rede Wi-Fi com os parâmetros que foram informados
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  // Aguarda a conexão...
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Imprime na porta serial o endereço IP da rede e inicia o servidor
  Serial.println("");
  Serial.print("Conectado a: ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  Serial.println("Aguarde 30 segundos para a primeira postagem");
   
  // Inicializa o sensor DHT11
  dht.begin();
  
  //define a porta do led
  pinMode(LED_V, OUTPUT);
  pinMode(LED_A, OUTPUT);

  // Define o modo de operação do Wi-Fi (STATION)
  WiFi.mode(WIFI_STA);
  
  // Inicializa ThingSpeak
  ThingSpeak.begin(client);
}

void acenderLED(){
  temperatura = dht.readTemperature();
    if (temperatura >38 ){
    digitalWrite(LED_V, HIGH);
    digitalWrite(LED_A, LOW);
    statusLED_V=1;
    statusLED_A=0;
  }else{
    digitalWrite(LED_V, LOW);
    digitalWrite(LED_A, HIGH);
    statusLED_V=0;
    statusLED_A=1;
  }
}
// Rotina principal
void loop() {
  // Os valores serão atualizados a cada 30 segundos no gráfico do ThingSpeak.
  if ((millis() - lastTime) > timerDelay) {
    
    // Conecta ou reconecta a rede Wi-Fi
    if(WiFi.status() != WL_CONNECTED){
      // Informa mensagem de conexão no Monitor Serial
      Serial.print("Tentando conectar...");
      // Conecta (no início) ou reconecta (se "cair") a rede Wi-Fi a cada 5 segundos
      // Recebe os parâmetros com as credenciais da rede, definidas no cabeçalho do código
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password);
        delay(2000);
      }
      // Informa mensagem de conexão no Monitor Serial
      Serial.println("\nConectado.");
    }

  acenderLED(); 
  // Efetua a leitura da temperatura
  temperatura = dht.readTemperature();

  // Define uma variável "envio", que receberá os parâmetros
  // – Canal do ThingSpeak
  // – Chave de escrita da API do ThingSpeak
  ThingSpeak.setField(1, temperatura);
  ThingSpeak.setField(2, statusLED_V);
  ThingSpeak.setField(3, statusLED_A);
  
  int envio = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if(envio == 200){
    Serial.println("ThingSpeak atualizado");
    Serial.print("Temperatura: ");
    Serial.println(temperatura);
    Serial.print("LED_V: ");
    Serial.println(statusLED_V);
    Serial.print("LED_A: ");
    Serial.println(statusLED_A);
    Serial.println("");
 }
  else{
    Serial.println("Problema na atualização do canal. Código do erro HTTP" + String(envio));
  }
  lastTime = millis();
}
}