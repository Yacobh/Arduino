  /*  TITULO: Comunicación serie entre dos Arduinos - Emisor_serie_TX
       
*/
 
  // Incluimos la librería
  #include <SoftwareSerial.h>
 
  // Declaro un nuevo puerto para la comunicación serie
  SoftwareSerial mySerial(4, 5); // RX, TX
 
  void setup()
  {
    mySerial.begin(9600); // Comienzo de la comunicación serie
    randomSeed(millis());    // genera una semilla para aleatorio a partir de la función millis()

  }
 
  void loop()
  {

      int voltaje = random(255);    // genera número aleatorio entre 0 y 255 
      int corriente = random(255);    // genera número aleatorio entre 0 y 255 
      mySerial.print("Voltaje " );
      mySerial.print(voltaje);
      mySerial.println(" v");
      mySerial.print("Corriente " );
      mySerial.print(corriente);
      mySerial.println(" A");
      delay(3000);
  }
