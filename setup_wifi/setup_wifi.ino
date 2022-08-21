#include <WiFi.h>
//=================================================================================================
const char* ssid = "CE-ESL";
const char* password = "ceeslonly";                                        
//=================================================================================================
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//=================================================================================================
void setup() {
  //===============================================================================================
  Serial.begin(115200);
  setup_wifi();
}

void loop() {
}
