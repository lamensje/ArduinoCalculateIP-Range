#include <ESP8266WiFi.h>

void setup() {  
  // Begin serial connection at 9600 baud
  Serial.begin(115200);
  
  // Connect to WiFi access point
  bool stationConnected = WiFi.begin(
  "replace with your network name",
  "password");

  // Check if connection errors
  if(!stationConnected)
  {
    Serial.println("Error, unable to connect specified WiFi network.");
  }
  
  // Wait connection completed
  Serial.print("Connecting to AP...");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected!\n");

  delay(2000);
  
  IPAddress localIP = WiFi.localIP();
  IPAddress subnetMask = WiFi.subnetMask();
  IPAddress network;
  IPAddress broadcast;

  for(int i = 0; i < 4; i++){
    network[i] = localIP[i] & subnetMask[i];
    broadcast[i] = network[i] + (255 - subnetMask[i]);
  }

  Serial.printf("\nIP Address: %s\n", localIP.toString().c_str());
  Serial.printf("Subnet Mask: %s\n", subnetMask.toString().c_str());
  Serial.printf("Network Address: %s\n", network.toString().c_str());
  Serial.printf("Broadcast Address: %s\n", broadcast.toString().c_str());
}

void loop() {
}
