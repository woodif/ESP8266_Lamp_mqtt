PubSubClient::callback_t on_message_arrived = 
[&](const MQTT::Publish & pub) -> void {
    Serial.print("ON MESSAGE: ");
    Serial.print(pub.topic());
    Serial.print(" => ");
    Serial.println(pub.payload_string());
  String color = pub.payload_string();
  String colorred = color.substring(0,2);
  String colorgreen = color.substring(2,4);
  String colorblue = color.substring(4,6);
  int red = strtol (colorred.c_str(), NULL, HEX);
  int green = strtol (colorgreen.c_str(), NULL, HEX);
  int blue = strtol (colorblue.c_str(), NULL, HEX);
  Serial.println(colorred);
  Serial.println(colorgreen);
  Serial.println(colorblue);
  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);
  int ledred = (red*4);
  int ledgreen = (green*4);
  int ledblue = (blue*4);
  analogWrite(12,ledred);
  analogWrite(16,ledgreen);
  analogWrite(13,ledblue);
  Serial.println(ledred);
  Serial.println(ledgreen);
  Serial.println(ledblue);
 };
