#define BLYNK_TEMPLATE_ID "TMPL31ezSPiUB"
#define BLYNK_TEMPLATE_NAME "DHT IoT sensor"
#define BLYNK_AUTH_TOKEN "gJtw5djx9cNp3RJeOXo4jov5m0eghWS9"

#include<DHT.h>
#include<BlynkSimpleEsp8266.h>
#define DHTPIN 4 //Data pin is connected to D2 on the "ESP"
#define DHTTYPE DHT11


char auth[]="gJtw5djx9cNp3RJeOXo4jov5m0eghWS9";
char ssid[]="OnePLus Nord";
char pass[]="15042006";
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHT Test Successful");
Blynk.begin(auth,ssid,pass);
Serial.println("Blynk connected successfully");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float h=dht.readHumidity();
float t=dht.readTemperature();
float f=dht.readTemperature(true);
if(isnan(h) || isnan(t) || isnan(f))//is not a number
{
  Serial.println("Something is not working as intended");
  return;
}
Serial.println("*************************");
Serial.print("Humidity : ");
Serial.print(h);
Serial.println("%");
Serial.print("Temperature : ");
Serial.print(t);
Serial.println(" degrees celsius");
Serial.println("*************************");
Blynk.virtualWrite(V0, t);
Blynk.virtualWrite(V1, h);
delay(5000);
}
