// Definir los pines para el L298N
const int IN1 = 18; 
const int IN2 = 19; 
const int ENA = 4;  // D4 (se asume que se usa PWM con ledcWrite)
const int IN3 = 22; 
const int IN4 = 23;
const int ENB = 5;  // D5 (se asume que se usa PWM con ledcWrite)



void setup() {
  // Configurar los pines del controlador L298N como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configurar la comunicación serial con el modulo XBee
  Serial.begin(9600);
}

const int bufferSize = 10; // Ajusta este valor según tus necesidades
char buffer[bufferSize];
int bufferIndex = 0; // Índice para el buffer

void loop() {
  int bytesRead = Serial.readBytes(buffer, bufferSize);

  // Verifica si se han recibido datos
  if (bytesRead > 0) {
    // Procesa los datos almacenados en el buffer
    processSerialData(buffer, bytesRead);
    
    // Limpia el buffer después de procesar los datos
    clearBuffer();
  }
  // if (Serial.available()) {
  //   String cmd = (String)Serial.read(); // Definir una variable cmd de lectura de la comunicacion serial entre los modulos XBee
  //   // Realizar el movimiento correspondiente de los motores segun el comando recibido
  //   if (cmd == "F") {
  //     // Mover hacia adelante
  //     izquierdaSuperior_F();
  //     derechaSuperior_F();
  //   } else if (cmd == "B") {
  //     // Mover hacia atras
  //     izquierdaSuperior_B();
  //     derechaSuperior_B();
  //   } else if(cmd == "L"){
      
  //   } else if(cmd == "R"){
      
  //   } else if(cmd == "FL"){
      
  //   } else if(cmd == "FR"){
      
  //   } else if(cmd == "BL"){
      
  //   } else if(cmd == "BR"){
      
  //   } else if(cmd == "S"){
  //     // NO MOVIMIENTO
  //     izquierdaSuperior_OFF();
  //     derechaSuperior_OFF();
  //   } 
  // }
}

void izquierdaSuperior_F(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);
}

void izquierdaSuperior_B(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENA, HIGH);
}

void derechaSuperior_F(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, HIGH);
}

void derechaSuperior_B(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, HIGH);
}

void izquierdaSuperior_OFF(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
}

void derechaSuperior_OFF(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, LOW);
}

void processSerialData(char* data, int length) {
  Serial.print("Datos recibidos: ");
  for (int i = 0; i < length; i++) {
    Serial.print(data[i]);
  }
  Serial.println();
}

void clearBuffer() {
  memset(buffer, 0, bufferSize);  // Llena el buffer con ceros
}