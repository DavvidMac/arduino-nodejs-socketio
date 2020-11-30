
//#include <SPI.h>
#include <ESP8266WiFi.h>
int led = 8;
int pinVal = 0;

WiFiClient client;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("TP-LINK_A38740", "Hulksmash"); 
  Serial.println("conectando"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
 }
}

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
    if (c == '1') {
      pinVal = HIGH;
//      client.print('1');
    } else if (c == '0') {
      pinVal = LOW;
  //    client.print('0');
    }
    digitalWrite(led, pinVal);
  }
}
