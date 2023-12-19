// No es necesario incluir SoftwareSerial.h para ESP32

// Definir pines
int boton = 2; // El pin al que está conectado el botón

void setup() {
  pinMode(boton, INPUT);  // Configurar el pin del botón como entrada
  Serial.begin(9600);    // Iniciar la comunicación serial a 9600 baudios
}

void loop() {
  int estadoBoton = digitalRead(boton); // Leer el estado del botón

  if (estadoBoton == HIGH) {
    // Si el botón está presionado, enviar 'A' al monitor serial
    Serial.write('A');
    delay(200); // Un pequeño retardo para evitar múltiples impresiones
  }
}

