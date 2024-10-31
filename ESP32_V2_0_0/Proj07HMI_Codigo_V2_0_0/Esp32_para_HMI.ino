 void Esp32_para_hmi() {
  
  // Escrevendo Ligado ou Desligado no botao Lampada 0x56
  byte_resp_Lamp[6] = highByte(StatusLampada);
  byte_resp_Lamp[7] = lowByte(StatusLampada);
  Serial1.write(byte_resp_Lamp, 8);  // 0x72
  
  // Escrevendo Ligado ou Desligado no botao Ventilador 0x57
  byte_resp_Ventilador[6] = highByte(StatusVentilador);
  byte_resp_Ventilador[7] = lowByte(StatusVentilador);
  Serial1.write(byte_resp_Ventilador, 8);  // 0x73

  // Escrevendo Ligado ou Desligado no botao Motor 0x58
  byte_resp_Motor[6] = highByte(StatusMotor);
  byte_resp_Motor[7] = lowByte(StatusMotor);
  Serial1.write(byte_resp_Motor, 8);  // 0x74

  // Escrevendo Ligado ou Desligado no botao Sirene 0x59
  byte_resp_Sirene[6] = highByte(StatusSirene);
  byte_resp_Sirene[7] = lowByte(StatusSirene);
  Serial1.write(byte_resp_Sirene, 8);  // 0x75
 
}
