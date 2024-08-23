  IPAddress localIP(192,168,3,69);
  IPAddress subnetMask(255,255,248,0);
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
