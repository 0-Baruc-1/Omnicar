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
const bool usingIDLE = false;
// Se crea una instancia de la clase Keypad, pasando la disposición de las teclas,
// los pines de las filas, los pines de las columnas, y las dimensiones del teclado.

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char key = keypad.getKey();

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
};

void loop() {
  if(key == NO_KEY){
    key = keypad.getKey();
    Serial.write('S');
    Serial.println("");
  } else {
    byte state = keypad.getState(key);
    Serial.println(state);
    isPressed(state);
    // if(isPressed(state)) {
    //   Serial.println("GATO");
    // } else {
    //   Serial.println("PERRO");
    // }
    // Serial.println("Tecla: " + (String)key + " Estado: " + state);
    //Serial.write(messajeToSend(key).c_str());
    delay(1000);
  };
};  

void isPressed(byte  state){
  switch (state) {
      case 0:
      if (usingIDLE) Serial.println("IDLE");
      break;

      case 1:
      Serial.println("PRESSED");
      break;

      case 2:
      Serial.println("HOLD");
      break;

      case 3:
      Serial.println("RELEASED");
      break;
    };

};

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
  };
};