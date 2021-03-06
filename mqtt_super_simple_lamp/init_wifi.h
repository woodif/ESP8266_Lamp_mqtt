
void init_wifi()
{
  // use flash memory ssid & smartconfig
   wifi = new WiFiConnector("NAT.11","guestnetwork");
  //wifi = new WiFiConnector();


  wifi->on_connecting([&](const void* message)
  {
    Serial.print("connecting -> ");
    Serial.println(wifi->counter);
    Serial.println(wifi->get("ssid") + ", " + wifi->get("password"));
    // Serial.println ((char*)message);
    delay(500);
  });

  wifi->on_connected([&](const void* message)
  {
    Serial.println("WIFI CONECTED: ");
    // Print the IP address
    Serial.println(WiFi.localIP());
    // Serial.println ((char*)message);
  });

  wifi->on_disconnected([&](const void* message)
  {
    Serial.println("WIFI DISCONECTED.");
    // Serial.println ((char*)message);
  });

  wifi->on_smartconfig_enter([&](const void* message)
  {
    Serial.println("ENTER SMARTCONFIG.");
  });

  wifi->on_smartconfig_done([&](const void* message)
  {
    Serial.println("SMARTCONFIG DONE.");
  });

  wifi->on_smartconfig_doing([&](const void* message)
  {
    // Serial.println("CONFIGURING WIFI..");
    // delay(500);
  });

  wifi->connect();

}
