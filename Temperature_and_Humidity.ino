#include "DHT.h"      // libray of DHT11 temperature and humidity sensor
#include <ESP8266WiFi.h>
#include <TM1637Display.h>

#define DHTTYPE DHT11 // DHT 11
#define dht_dpin 0    // D3 pin
DHT dht(dht_dpin, DHTTYPE);

#define CLK D7  // pin 13
#define DIO D6  // pin 12
TM1637Display display(CLK, DIO);

String ClientRequest;
WiFiServer server(80);
void setup() {
  Serial.begin(9600);
  // Wifi connection
  ClientRequest = "";
  WiFi.disconnect();
  WiFi.begin("SSID","password");
  Serial.println("Connecting..");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");
  }
  Serial.print("\nIP address: ");
  Serial.print(WiFi.localIP().toString());
  server.begin();

  // Temperature and Humidity sensor setup
  dht.begin();
  Serial.println("\nHumidity and temperature\n\n");
  delay(700);
  display.setBrightness(0x0f);
  display.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
    
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("C");

  display.showNumberDec(temperature, false, 2, 0);
  display.showNumberHexEx(0xc,0,false,1,3);
  delay(1000);
  display.show
  delay(1000);
  WiFiClient client = server.available();
  if (!client) {
    delay(5000);
    return;
  }
  
  while (!client.available()) {delay(1); }
  Serial.println("Web request received...");

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.print("Humidity = ");
  client.print(humidity);
  client.print("%  Temperatura = ");
  client.print(temperature);
  client.print("C \n");
  delay(1);
  client.flush();
  Serial.println("Web request was answered !");
}
