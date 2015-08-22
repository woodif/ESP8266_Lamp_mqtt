MqttConnector::prepare_data_hook_t on_prepare_data = 
[&](JsonObject * root) -> void {
    JsonObject& data = root->at("d");
    data["myName"] = "Wooddy";
  //  data["adc"] = analogRead(A0);
    data["tag"] = "Lamp";
    data["zone"] = "1";
};
