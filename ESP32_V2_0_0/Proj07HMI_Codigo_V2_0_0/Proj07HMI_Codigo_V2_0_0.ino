
// Criando Buffer e bytes para ler e escrever na IHM
unsigned char Buffer[9];
unsigned char teste[9];

#define resp_Lamp_address     0x72
#define ps_Lampada_address    0x56

#define resp_Ventilador_address     0x73
#define ps_Ventilador_address    0x57

#define resp_Motor_address     0x74
#define ps_Motor_address    0x58

#define resp_Sirene_address     0x75
#define ps_Sirene_address    0x59

// Criando os framers com 8 bytes para ler e escrever na IHM

unsigned char   byte_ps_Lampada[8] = {0x5A, 0xA5, 0x05, 0x82, ps_Lampada_address, 0x00, 0x00, 0x00};      // 0x56
unsigned char   byte_resp_Lamp[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Lamp_address , 0x00, 0x00, 0x00};       // 0x72

unsigned char   byte_ps_Ventilador[8] = {0x5A, 0xA5, 0x05, 0x82, ps_Ventilador_address, 0x00, 0x00, 0x00};      // 0x57
unsigned char   byte_resp_Ventilador[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Ventilador_address , 0x00, 0x00, 0x00};       // 0x73

unsigned char   byte_ps_Motor[8] = {0x5A, 0xA5, 0x05, 0x82, ps_Motor_address, 0x00, 0x00, 0x00};      // 0x58
unsigned char   byte_resp_Motor[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Motor_address , 0x00, 0x00, 0x00};       // 0x74

unsigned char   byte_ps_Sirene[8] = {0x5A, 0xA5, 0x05, 0x82, ps_Sirene_address, 0x00, 0x00, 0x00};      // 0x59
unsigned char   byte_resp_Sirene[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Sirene_address , 0x00, 0x00, 0x00};       // 0x75

unsigned long Elapsed_Time[20];
unsigned long End_Time[20];
unsigned long Start_Time[20] = {0}; // Todos os 20 elementos do array começam com o valor 0

int StatusLampada, inteiroStatusLampada;
int StatusVentilador, inteiroStatusVentilador;
int StatusMotor, inteiroStatusMotor;
int StatusSirene, inteiroStatusSirene;

//Definição dos pinos do controlador
//Saidas digiais
#define pin_Y1 27  // Lampada
#define pin_Y2 26  // Ventilador
#define pin_Y3 25  // Motor
#define pin_Y4 33  // Sirene

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // (USB)
  Serial1.begin(115200); // (TTL)

  pinMode(pin_Y1, OUTPUT); // Lampada
  digitalWrite(pin_Y1, LOW);

  byte_ps_Lampada[6] = highByte(0);
  byte_ps_Lampada[7] = lowByte(0);
  Serial1.write(byte_ps_Lampada, 8); // 0x56
  StatusLampada = 0;


  pinMode(pin_Y2, OUTPUT); // Ventilador
  digitalWrite(pin_Y2, LOW);

  byte_ps_Ventilador[6] = highByte(0);
  byte_ps_Ventilador[7] = lowByte(0);
  Serial1.write(byte_ps_Ventilador, 8); // 0x57
  StatusVentilador = 0;


  pinMode(pin_Y3, OUTPUT); // Motor
  digitalWrite(pin_Y3, LOW);

  byte_ps_Motor[6] = highByte(0);
  byte_ps_Motor[7] = lowByte(0);
  Serial1.write(byte_ps_Motor, 8); // 0x58
  StatusMotor = 0;

  pinMode(pin_Y4, OUTPUT); // Sirene
  digitalWrite(pin_Y4, LOW);

  byte_ps_Sirene[6] = highByte(0);
  byte_ps_Sirene[7] = lowByte(0);
  Serial1.write(byte_ps_Sirene, 8); // 0x59
  StatusSirene = 0;
  

}

void loop() {
  hmi_para_Esp32(); 
  ciclo_rx_tx();
  ciclo_rx_tx();
  ciclo_rx_tx();
  ciclo_rx_tx();

  saidas();
  ciclo_rx_tx();
  ciclo_rx_tx();

  ciclo_rx_tx();
  ciclo_rx_tx();
  delay(10);

}
