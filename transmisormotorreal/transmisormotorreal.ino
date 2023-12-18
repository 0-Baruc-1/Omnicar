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
char key = keypad.getKey();

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  if(key == NO_KEY || (key != NO_KEY && !isPressed(key))){
    key = keypad.getKey();
    Serial.write('S');
  } else {
    state = keypad.getState(key);
    Serial.println("Tecla: " + (String)key + " Estado: " + state);
    Serial.write(messajeToSend(key).c_str());
    delay(100);
  }
}

bool isPressed(byte state){
  switch (state){
  case 0: //IDLE: Indica que la tecla no está siendo presionada.
    return false;
    break;
  case 1: //PRESSED: Indica que la tecla acaba de ser presionada.
    return true;
    break;
  case 2: //HOLD:Indica que la tecla se mantiene presionada continuamente.
    return true;
    break;
  case 3: //RELEASED: Indica que la tecla acaba de ser liberada.
    return false;
    break;
  }
}

String messajeToSend(char key){
  if(key == '2') {
    return "F"; // Envía la letra "F" cuando se presiona la tecla "2"
  } else if (key == '4'){
    return "L";
  } else if (key == '6'){ 
    return "R";
  } else if (key == '8'){
    return "B";
  } else if (key == '1'){
    return "FL";
  } else if (key == '3'){
    return "FR";
  } else if (key == '7'){
    return "BL";
  } else if (key == '9'){
    return "BR";
  } else {
    return "S";
  }
}