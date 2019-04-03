/*
 * Empresa: Electromining LTDA.
 * 3 de abril 2019
 * Autor Jacobo Cordova
 */
int a = 0;

void setup() {
  Serial.begin(9600);
  //Botones 24 V
  // NORMALMENTE ESTAN EN CERO Y CUANDO SE PULSAN PASAN A 1
  pinMode(I0_0, INPUT); // Arriba
  pinMode(I0_1, INPUT); // Abajo
  //pinMode(I0_2, INPUT); // Izquierda
  //pinMode(I0_3, INPUT); // Derecha
  //pinMode(I0_4, INPUT); // Adelante
  //pinMode(I0_5, INPUT); // Atras
  pinMode(I0_6, INPUT); // Parada
  pinMode(I0_7, INPUT); // Lento
  pinMode(I0_8, INPUT); // Rapido
  //pinMode(I0_9, INPUT); // parte disponible

  // finales de carrera
  pinMode(SCL, INPUT_PULLUP);
  pinMode(SDA, INPUT_PULLUP);
  pinMode(SCK, INPUT_PULLUP);

  pinMode(MOSI, INPUT_PULLUP);
  pinMode(MISO, INPUT_PULLUP);
  // Reles
  // enganches
  pinMode(Q0_0, OUTPUT);
  pinMode(Q0_1, OUTPUT);
  pinMode(Q0_2, OUTPUT);
  pinMode(Q0_3, OUTPUT);
  pinMode(Q0_4, OUTPUT);
  // motor
  pinMode(Q0_5, OUTPUT);
  pinMode(Q0_6, OUTPUT);

}

/*
   Loop que realiza el control general de la fresadora.
*/
void loop() {
  //-----------------------------------------------------------
  // Verifica que se haya pulsado algun boton de direccion
  // verifica que sea posible ir en esa dirección
  // y activa el rele de esa dirección (engancha direccion)
  // y arranca el motor() con rele de partida (variador)
  verifica_direccion();   // Se pulsa rele direccion de motor
  //-----------------------------------------------------------
  // verifica que se haya pulsado el boton de marcha
  // velocidad (rapido o lento)
  // hace el enganche (engancha velocidad)
  verifica_marcha();
  // ----------------------------------------------------------
  // Verifica que se haya pulsado el boton de paro
  // desengancha reles direccion y velocidad
  // y posiblemente encendido de motor
  verifica_paro();
}


/*
   Funciones auxiliares principales
*/
//-----------------------------------------------------------
// Verifica que se haya pulsado algun boton de direccion
// verifica que sea posible ir en esa dirección
// y activa el rele de esa dirección (engancha direccion)
// y arranca el motor() con rele de partida (variador)

void verifica_direccion()
{
  int boton = verifica_botones();
  Serial.println(boton);
  delay(40);
}

//-----------------------------------------------------------
// verifica que se haya pulsado el boton de marcha
// velocidad (rapido o lento)
// hace el enganche (engancha velocidad)
void verifica_marcha()
{

}

// ----------------------------------------------------------
// Verifica que se haya pulsado el boton de paro
// desengancha reles direccion y velocidad
// y posiblemente encendido de motor
void verifica_paro()
{
  Serial.println( verifica_fin_carrera() );
}

/*
   Funciones auxiliares secundarias
*/
// ----------------------------------------------------------
// Verifica los botones
// verifica cual es el estado de todos los botones

int verifica_botones()
{

  if ( digitalRead(I0_0) == 1) return 1;
  return 0;

}

// ----------------------------------------------------------
// Verifica los fines de carrera
// verifica cual es el estado de todos los fines de carrera

int verifica_fin_carrera()
{
  //if ( analogRead(A0_6) >= 200) return 6 ;
  //return 0;

  return digitalRead(SCL);

}

// ----------------------------------------------------------
// activa los reles

void setea_reles()
{
  //  lectura_arriba = analogRead(arriba);

}
