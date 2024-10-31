void hmi_para_Esp32()
{
  if (Serial1.available()) 
  {   
    for (int i = 0; i <= 9; i++) // 5A A5 06 83 56 00 01 00 01 - Exemplo de estrutura recebida
    {
      Buffer[i] = Serial1.read();

      Serial.println(Buffer[4]);
      // Verifica o valor do byte na posição 4 (0x56, por exemplo)
      switch (Buffer[4]) 
      {
        case 0x56: // Leitura do botão lâmpada vindo da IHM
        {
          Serial.print("statusLampada: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          inteiroStatusLampada = (byteAlto << 8) | byteBaixo;
          StatusLampada = inteiroStatusLampada;
          Serial.println(StatusLampada); 
        
              break;
        }
        
        case 0x57: // Leitura do botão Ventilador vindo da IHM
        {
          Serial.print("statusVentilador: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          inteiroStatusVentilador = (byteAlto << 8) | byteBaixo;
          StatusVentilador = inteiroStatusVentilador;
          Serial.println(StatusVentilador); 
        
              break;
        }

        case 0x58: // Leitura do botão Motor vindo da IHM
        {
          Serial.print("statusMotor: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          inteiroStatusMotor = (byteAlto << 8) | byteBaixo;
          StatusMotor = inteiroStatusMotor;
          Serial.println(StatusMotor); 
        
              break;
        }

        case 0x59: // Leitura do botão Sirene vindo da IHM
        {
          Serial.print("statusSirene: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          inteiroStatusSirene = (byteAlto << 8) | byteBaixo;
          StatusSirene = inteiroStatusSirene;
          Serial.println(StatusSirene); 
        
              break;
        }
        
      } // Fecha Switch Case
    } // Fecha o Looping For
  } // Fecha Serial Available
} // Fecha a função
