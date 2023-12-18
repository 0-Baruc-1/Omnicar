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
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  char key = keypad.getKey();
  if(key != NO_KEY){
    state = keypad.getState(key);
    Serial.println("Tecla: " + (String)key + " Estado: " + state);
    
  }
}

bool isPressed(byte state){
  switch (state)
  {
  case 0:
    return false;
    break;
  case 1:
    return true;
    break;
  case 2:
    return true;
    break;
  case 3:
    return false;
    break;
  }
}

  // if (keypad.isPressed('2')) {
  //   Serial.write("F"); // Envía la letra "F" cuando se presiona la tecla "2"
  // } else if (keypad.isPressed('4')){
  //   Serial.write("L");
  // } else if (keypad.isPressed('6')){ 
  //   Serial.write("R");
  // } else if (keypad.isPressed('8')){
  //   Serial.write("B");
  // } else if (keypad.isPressed('1')){
  //   Serial.write("FL");
  // } else if (keypad.isPressed('3')){
  //   Serial.write("FR");
  // } else if (keypad.isPressed('7')){
  //   Serial.write("BL");
  // } else if (keypad.isPressed('9')){
  //   Serial.write("BR");
  // } 
  // delay(100);