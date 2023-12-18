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

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  char key = keypad.getKey(); // Obtiene la tecla presionada en el teclado.
  if (key != NO_KEY) {
    if (key == '2') {
      Serial.write('F'); // Envía la letra 'F' cuando se presiona la tecla '2'
    } else if (key == '4'){
      Serial.write('L');
    } else if (key == '6'){ 
      Serial.write('R');
    } else if (key == '8'){
      Serial.write('B');
    } else {
      Serial.write('S');
    }
  }
}