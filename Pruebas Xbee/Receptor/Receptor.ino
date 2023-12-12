void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    char cmd = Serial.read();
    Serial.print("Mensaje recibido :");
    Serial.println(cmd);
    delay(1000);
  }
  // put your main code here, to run repeatedly:

}
 