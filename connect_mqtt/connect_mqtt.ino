#include <WiFi.h>
#include <PubSubClient.h>
//=================================================================================================
const char* ssid = "ESL-Net";
const char* password = "ceeslonly";
//=================================================================================================
const char* mqtt_broker = "161.246.6.90";
const char* mqtt_username = "admin";
const char* mqtt_password = "esldev@2022";
const int   mqtt_port = 1883;
//=================================================================================================
WiFiClient   espClient;
PubSubClient client(espClient);
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
  randomSeed(micros());
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//=================================================================================================
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");

  for (int i = 0; i < length; i++)
    Serial.print((char) payload[i]);

  Serial.println();
  Serial.println("-----------------------");
}
//=================================================================================================
void reconnect() {
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected())
  {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
      Serial.println("Public emqx mqtt broker connected");
    else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
//=================================================================================================
void setup()
{
  //===============================================================================================
  Serial.begin(115200);
  //===============================================================================================
  setup_wifi();
  reconnect();
  //===============================================================================================
  client.subscribe("NODE_send");
  client.publish("ESP_send", "hello");
  //===============================================================================================
}

void loop()
{
  client.loop();
}
