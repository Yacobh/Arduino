void setup() {
  Serial.begin(9600);
 /* pinMode(2, INPUT); // Arriba
  pinMode(12, INPUT); // Abajo
  pinMode(8, INPUT); // Izquierda
  pinMode(4, INPUT); // Derecha
  pinMode(I0_5, INPUT); // Adelante
  pinMode(I0_6, INPUT); // Atras
  pinMode(I0_7, INPUT); // Parada
  pinMode(I0_8, INPUT); // Lento
  pinMode(I0_9, INPUT); // Rapido
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  if( digitalRead(1) == 1 ) Serial.println("1");
  if( digitalRead(2) == 1 ) Serial.println("2");
  if( digitalRead(3) == 1 ) Serial.println("3");
  if( digitalRead(4) == 1 ) Serial.println("4");
  if( digitalRead(5) == 1 ) Serial.println("5");
  if( digitalRead(6) == 1 ) Serial.println("6");
  if( digitalRead(7) == 1 ) Serial.println("7");
  if( digitalRead(8) == 1 ) Serial.println("8");
  if( digitalRead(9) == 1 ) Serial.println("9");
  if( digitalRead(10) == 1 ) Serial.println("10");
  if( digitalRead(11) == 1 ) Serial.println("11");
  if( digitalRead(12) == 1 ) Serial.println("12");
  if( digitalRead(13) == 1 ) Serial.println("13");
  if( digitalRead(A1) == 1 ) Serial.println("A1");
  if( digitalRead(A2) == 1 ) Serial.println("A2");
  if( digitalRead(A3) == 1 ) Serial.println("A3");
  if( digitalRead(A4) == 1 ) Serial.println("A4");
  if( digitalRead(A5) == 1 ) Serial.println("A5");
  
  
}
