// Definir los pines para el L298N
const int IN1 = 19; 
const int IN2 = 18; 
const int ENA = 4;  // D4 (se asume que se usa PWM con analogWrite)
const int IN3 = 23; 
const int IN4 = 22;
const int ENB = 5;  // D5 (se asume que se usa PWM con analogWrite)


const int IN5 = 27;
const int IN6 = 26;
const int ENBB = 14;  // D5 (se asume que se usa PWM con analogWrite)
const int IN7 = 13;
const int IN8 = 12;
const int ENAA = 25;  // D5 (se asume que se usa PWM con analogWrite)

const int on_Off = 33; 

const int apagado = 0;
const int prendido = 100;
void setup() {
  // Configurar los pines del controlador L298N como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENAA, OUTPUT);
  pinMode(ENBB, OUTPUT);

  pinMode(on_Off, OUTPUT);
  digitalWrite(on_Off, LOW);

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
<<<<<<< HEAD
        cmd.trim();
        
        if(cmd == "ST"){
          delay(500);
          digitalRead(on_Off) == HIGH ? digitalWrite(on_Off,LOW) : digitalWrite(on_Off, HIGH);
=======
        cmd.trim(); // Eliminar espacios en blanco y caracteres de control
        if(cmd == "X"){
          Serial.println(cmd);
          delay(500);
          digitalWrite(on_Off, !digitalRead(on_Off));
>>>>>>> 39fae750cfc7f14b3b9ce78bc74b99fb4968168d
        }
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
  Serial.println(cmd);
  // Realizar el movimiento correspondiente de los motores segun el comando recibido
<<<<<<< HEAD
  // Eliminar espacios en blanco y caracteres de control
=======
>>>>>>> 39fae750cfc7f14b3b9ce78bc74b99fb4968168d
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
  } else if(cmd == "H"){
    left_Top_Forward();
    left_Bottom_Forward();
    right_Top_Back();
    right_Bottom_Back();
  } else if(cmd == "AH"){
    left_Bottom_Back();
    left_Top_Back();
    right_Top_Forward();
    right_Bottom_Forward();
  }
}

void left_Top_Forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, prendido);
}

void left_Top_Back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, prendido);
}

void right_Top_Forward(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, prendido);
}

void right_Top_Back(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, prendido);
}

void left_Top_OFF(){
 
  analogWrite(ENA, apagado);
}

void right_Top_OFF(){
 
  analogWrite(ENB, apagado);
}

//---------------------RUEDAS DE ABAJO-------------------------

void left_Bottom_Forward(){
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENAA, prendido);
}

void right_Bottom_Forward(){
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENBB, prendido);
}

void left_Bottom_Back(){//
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENAA, prendido);
}

void right_Bottom_Back(){
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENBB, prendido);
}

void left_Bottom_OFF(){
 
  analogWrite(ENAA, apagado);
}

void right_Bottom_OFF(){
  
  analogWrite(ENBB, apagado);
}