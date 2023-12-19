#include <Keypad.h>

const byte ROWS = 4; // Cuatro filas
const byte COLS = 4; // Cuatro columnas

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Conecta los pines del teclado a los pines GPIO del ESP32
byte rowPins[ROWS] = {25, 33, 32, 35}; // Conectar a los pines GPIO que no interfieran con el arranque, establece los pines del ESP32 a los que están conectadas las filas del teclado.
byte colPins[COLS] = {5, 18, 19, 21}; // Conectar a los pines GPIO que no interfieran con el arranque, pines del ESP32 a los que están conectadas las columnas del teclado.

// Se crea una instancia de la clase Keypad, pasando la disposición de las teclas,
// los pines de las filas, los pines de las columnas, y las dimensiones del teclado.

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
byte state = 0;
char pastKey = NO_KEY;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  char key = keypad.getKey(); // Obtiene la tecla presionada en el teclado.
  if (!(pastKey == NO_KEY && key == NO_KEY)){
    if(pastKey != NO_KEY && key == NO_KEY) {
      key = pastKey;
    } else {
      pastKey = key;
    }
    String mensaje = messajeToSend(key);
    Serial.write(mensaje.c_str());
    Serial.println();
  }
}

String messajeToSend(char key){
  switch (key){
  case '1':
    return "FL";
  case '2':
    return "F"; // Envía la letra "F" cuando se presiona la tecla "2"
  case '3':
    return "FR";
  case '4':
    return "L";
  case '5':
    return "S";
  case '6':
    return "R";
  case '7':
    return "BL";
  case '8':
    return "B";
  case '9':
    return "BR";
  default:
    return "S";
  }
};