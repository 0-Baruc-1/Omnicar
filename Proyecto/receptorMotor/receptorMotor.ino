// Definir los pines para el L298N
const int IN1 = 19; 
const int IN2 = 18; 
const int ENA = 4;  // D4 (se asume que se usa PWM con ledcWrite)
const int IN3 = 23; 
const int IN4 = 22;
const int ENB = 5;  // D5 (se asume que se usa PWM con ledcWrite)


const int IN5 = 27;
const int IN6 = 26;
const int ENBB = 14;  // D5 (se asume que se usa PWM con ledcWrite)
const int IN7 = 13;
const int IN8 = 12;
const int ENAA = 25;  // D5 (se asume que se usa PWM con ledcWrite)



void setup() {
  // Configurar los pines del controlador L298N como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(ENAA, OUTPUT);
  pinMode(ENBB, OUTPUT);
  // Configurar la comunicación serial con el modulo XBee
  Serial.begin(9600);
}

const int bufferSize = 64; // Ajusta este valor según tus necesidades
char buffer[bufferSize];
int bufferIndex = 0; // Índice para el buffer

void loop() {
  // Leer datos disponibles y agregarlos al buffer
  while (Serial.available()) {
    char c = Serial.read();
    // Comprobar si es el final de un comando
    if (c == '\n' || c == '\r') {
      if (bufferIndex > 0) {
        // Procesar el comando
        buffer[bufferIndex] = '\0'; // Terminar el string
        String cmd = String(buffer);
        processCommand(cmd);
        bufferIndex = 0; // Restablecer el índice del buffer
      }
    } else {
      if (bufferIndex < bufferSize - 1) {
        buffer[bufferIndex++] = c; // Agregar al buffer y aumentar el índice
      }
    }
  }
}

void processCommand(String cmd) {
  // Realizar el movimiento correspondiente de los motores segun el comando recibido
  cmd.trim(); // Eliminar espacios en blanco y caracteres de control
  //Serial.println("Comando recibido: " + cmd); // Imprimir el comando recibido
  
  if (cmd == "F") {
    // Mover hacia adelante
    left_Top_Forward();
    right_Top_Forward();
    left_Bottom_Forward();
    right_Bottom_Forward();
  } else if (cmd == "B") {
    // Mover hacia atras
    left_Top_Back();
    right_Top_Back();
    left_Bottom_Back();
    right_Bottom_Back();
  } 
  else if(cmd == "L"){
    left_Top_Back();
    right_Top_Forward();
    right_Bottom_Back();
    left_Bottom_Forward();
  } else if(cmd == "R"){
    left_Top_Forward();
    right_Top_Back();
    right_Bottom_Forward();
    left_Bottom_Back();
  } else if(cmd == "FL"){
    left_Top_OFF();
    right_Bottom_OFF();
    right_Top_Forward();
    left_Bottom_Forward();
  } else if(cmd == "FR"){
    left_Top_Forward();
    right_Top_OFF();
    left_Bottom_OFF();
    right_Bottom_Forward();
  } else if(cmd == "BL"){
    left_Top_Back();
    right_Top_OFF();
    left_Bottom_OFF();
    right_Bottom_Back();
  } else if(cmd == "BR"){
    left_Top_OFF();
    right_Top_Back();
    right_Bottom_OFF();
    left_Bottom_Back();
  } else if(cmd == "S"){
    // NO MOVIMIENTO
    left_Top_OFF();
    right_Top_OFF();
    left_Bottom_OFF();
    right_Bottom_OFF();
  } 
}


void left_Top_Forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);
}

void left_Top_Back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENA, HIGH);
}

void right_Top_Forward(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, HIGH);
}

void right_Top_Back(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, HIGH);
}

void left_Top_OFF(){
  digitalWrite(ENA, LOW);
}

void right_Top_OFF(){
  digitalWrite(ENB, LOW);//
}

//---------------------RUEDAS DE ABAJO-------------------------

void left_Bottom_Forward(){
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(ENAA, HIGH);
}

void right_Bottom_Forward(){
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  digitalWrite(ENBB, HIGH);
}

void left_Bottom_Back(){//
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(ENAA, HIGH);
}

void right_Bottom_Back(){
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  digitalWrite(ENBB, HIGH);
}

void left_Bottom_OFF(){
  digitalWrite(ENAA, LOW);
}

void right_Bottom_OFF(){
  digitalWrite(ENBB, LOW);
}