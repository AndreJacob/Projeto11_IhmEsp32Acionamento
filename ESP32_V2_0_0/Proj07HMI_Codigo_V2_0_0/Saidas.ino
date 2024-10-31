void saidas()
{
  // ****************************** CONTROLE DAS SAÍDAS DIGITAIS FÍSICAS Y1, Y2, Y3, Y4 ******************************************************
 
  // Comando das saídas digitais da Lampada 
  if (StatusLampada == 1 ){          
      digitalWrite(pin_Y1, 1);  // pin_Y1 - Relé Lampada
  }
  else{
      digitalWrite(pin_Y1, 0);        
  }

    // Comando das saídas digitais da Ventilador 
  if (StatusVentilador == 1 ){          
      digitalWrite(pin_Y2, 1);  // pin_Y2 - Relé Ventilador
  }
  else{
      digitalWrite(pin_Y2, 0);        
  }

  // Comando das saídas digitais da Motor
  if (StatusMotor == 1 ){          
      digitalWrite(pin_Y3, 1);  // pin_Y3 - Relé Motor
  }
  else{
      digitalWrite(pin_Y3, 0);        
  }


  // Comando das saídas digitais da Sirene
  if (StatusSirene == 1 ){          
      digitalWrite(pin_Y4, 1);  // pin_Y4 - Relé Sirene
  }
  else{
      digitalWrite(pin_Y4, 0);        
  }

  
    // .................................................................................................................................................
}
