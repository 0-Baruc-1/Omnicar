// Definir los pines para el L298N
const int IN1 = 18; // D18
const int IN2 = 19; // D19
const int ENA = 4;  // D4 (se asume que se usa PWM con ledcWrite)
const int IN3 = 22; // D22
const int IN4 = 23; // D23
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

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read(); // Definir una variable cmd de lectura de la comunicacion serial entre los modulos XBee
    Serial.print("Comando recibido: ");
    Serial.println(cmd);

    // Realizar el movimiento correspondiente de los motores segun el comando recibido
    if (cmd == 'F') {
      // Mover hacia adelante
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(ENA, HIGH);
      digitalWrite(ENB, HIGH);
      delay(50);
    } else if (cmd == 'B') {
      // Mover hacia atras
      // Aquí se agregaría el código para mover los motores hacia atrás
    }
    // Agregar más condiciones para otros comandos si es necesario
  }
}

