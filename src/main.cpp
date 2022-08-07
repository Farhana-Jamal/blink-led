#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "Farhana";
const char* password = "1234567890";
void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid , password);
  Serial.println("Connecting to wifi network");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() 
{
  Serial.begin(115200);
  initWiFi();
  Serial.print("RSSI : ");
  Serial.println(WiFi.RSSI());
  delay(1000);
 
}

void loop() 
{
    Serial.println("scan start");
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n==0)
  {
    Serial.println("no networks found");
  }
  else
  {
    Serial.println("networks found:");
    Serial.println(n);
    for (int i = 0; i < n; i++)
    {
      Serial.print(i + 1);
      Serial.print(":");
      Serial.print(WiFi.SSID(i));
      Serial.print("(");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)? "" : "*");
      delay(100);
    }
  }
   Serial.println("*");
   delay(100);
}
