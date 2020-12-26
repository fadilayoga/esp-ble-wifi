#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#define DHTPIN 23
DHT dht(DHTPIN, DHT11);
String apikey = "X4AZ1JKN4C1E90DS";
const char *ssid = "FKY-ARIS";
const char *pass = "instabae";
const char *server = "api.thingspeak.com";
WiFiClient client;
unsigned long myChannelNumber = 1254380;
const char * myWriteAPIKey = "X4AZ1JKN4C1E90DS";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
Serial.println("Connected");
WiFi.begin(ssid,pass);
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
float t = dht.readTemperature();
if(isnan(t)){
  Serial.println("Sensor Tidak Terdeteksi");
  return;
}
ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
Serial.println(t);
}
