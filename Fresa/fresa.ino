/*
 * Empresa: Electromining LTDA.
 * 3 de abril 2019
 * Autor Jacobo Cordova
 * Se desarrolla el control de una fresadora yugoslava 
 * Se utiliza un variador de frecuencias para controlar
 * el motor y se utilizan enganches a 24 Volts para 
 * activar las marchas
 */
//------------ Status

enum direccion_elegida {
  nula, arriba, abajo, izquierda, derecha, adelante, atras, parada, lento, rapido
};

direccion_elegida direccion = nula;

enum enganches {
  neutro, horizontal, vertical, sagital, fast, slow, encendido, apagado, forward, reverse, embrague
};

enum estados{
  off, on, enganchado
};

estados Status = off;
 //----------- contadores
int uno = 0;
int dos = 0;
int tres = 0;
int cuatro = 0;
int cinco = 0;
int seis = 0;
int siete = 0;
int ocho = 0;
int nueve = 0;
int fin_horizontal = 0;
int fin_vertical = 0;
int fin_sagital = 0;


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
  // pinMode(SCL, INPUT_PULLUP); // disponible 
  // pinMode(SDA, INPUT_PULLUP); // disponible
  //pinMode(SCK, INPUT_PULLUP); // horizontal

  pinMode(MOSI, INPUT_PULLUP); // vertical
  //pinMode(MISO, INPUT_PULLUP); // Sagital
  // Reles
  
  // enganches
  //pinMode(Q0_1, OUTPUT); // horizontal
  pinMode(Q0_2, OUTPUT); // vertical
  //pinMode(Q0_3, OUTPUT); // Sagital
  pinMode(Q0_4, OUTPUT); // rapido
  pinMode(Q0_5, OUTPUT); //lento
  // motor
  pinMode(Q0_6, OUTPUT); // MI1
  pinMode(Q0_7, OUTPUT); // MI2

}

/*
   Loop que realiza el control general de la fresadora.
*/
void loop() {
  //-----------------------------------------------------------
  // Verifica que se haya pulsado algún boton de direccion
  // verifica que sea posible ir en esa dirección
  // y activa el rele de esa dirección (engancha direccion)
  // y arranca el motor() con rele de partida (variador)
  verifica_direccion();   // Se pulsa rele direccion de motor
  //-----------------------------------------------------------
  // verifica que se haya pulsado el boton de marcha
  // velocidad (rapido o lento)
  // hace el enganche (engancha velocidad)
  //verifica_marcha();
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
  direccion = verifica_botones();
  Serial.println(direccion);
  if ( direccion == arriba || direccion == abajo){
    setea_reles ( horizontal );
    if ( direccion == arriba) setea_reles( forward );
    if ( direccion == abajo) setea_reles( reverse );
    if ( Status == off ){
      setea_reles( encendido );
      Status = on;
    }
  }
  if (direccion == lento && Status != off){
    setea_reles( slow );
    Status = enganchado;
  }
  if (direccion == rapido && Status != off){
    setea_reles( fast );
    Status = enganchado;
  }
  if (direccion == parada && Status == on){
    setea_reles( neutro );
    setea_reles( apagado );
    Status = off;
  }
  if (direccion == parada && Status == enganchado){
    setea_reles( embrague );
    Status = on;
  }
  //delay(40);
}

//-----------------------------------------------------------
// verifica que se haya pulsado el boton de marcha
// velocidad (rapido o lento)
// hace el enganche (engancha velocidad)
void verifica_marcha()
{
  //int marcha 

}

// ----------------------------------------------------------
// Verifica que se haya pulsado el boton de paro
// desengancha reles direccion y velocidad
// y posiblemente encendido de motor
void verifica_paro()
{
  if ( verifica_fin_carrera() ){
    setea_reles( apagado );
    setea_reles( embrague );
    setea_reles( neutro );
    Status = off;
          
  }
}

/*
   Funciones auxiliares secundarias
*/
// ----------------------------------------------------------
// Verifica los botones
// verifica cual es el estado de todos los botones

int verifica_botones()
{
//------------------------------
  if ( digitalRead(I0_0) == 1) {
    uno++;
    if (uno >= 10){
      uno = 0;
      return 1;
    }  
  } else uno = 0;
//------------------------------
  if ( digitalRead(I0_1) == 1) {
    dos++;
    if (dos >= 10){
      dos = 0;
      return 2;
    }  
  } else dos = 0;
//------------------------------
  if ( digitalRead(I0_2) == 1) {
    tres++;
    if (tres >= 10){
      tres = 0;
      return 3;
    }  
  } else tres = 0;
//------------------------------
  if ( digitalRead(I0_3) == 1) {
    cuatro++;
    if (cuatro >= 10){
      cuatro = 0;
      return 4;
    }  
  } else cuatro = 0;
//------------------------------
  if ( digitalRead(I0_4) == 1) {
    cinco++;
    if (cinco >= 10){
      cinco = 0;
      return 5;
    }  
  } else cinco = 0;
//------------------------------
  if ( digitalRead(I0_5) == 1) {
    seis++;
    if (seis >= 10){
      seis = 0;
      return 6;
    }  
  } else seis = 0;
//------------------------------
  if ( digitalRead(I0_6) == 1) {
    siete++;
    if (siete >= 10){
      siete = 0;
      return 7;
    }  
  } else siete = 0;
//------------------------------
  if ( digitalRead(I0_7) == 1) {
    ocho++;
    if (ocho >= 10){
      ocho = 0;
      return 8;
    }  
  } else ocho = 0;
//------------------------------
  if ( digitalRead(I0_8) == 1) {
    nueve++;
    if (nueve >= 10){
      nueve = 0;
      return 9;
    }  
  } else nueve = 0;
  
  return 0;

}

// ----------------------------------------------------------
// Verifica los fines de carrera
// verifica cual es el estado de todos los fines de carrera

int verifica_fin_carrera()
{
  if ( digitalRead(SCK) == 0){
    fin_horizontal++;
    if ( fin_horizontal >= 10 ){
      fin_horizontal = 0;
      return 1;
    }
  }
  //----------------------------------------
  if ( digitalRead(MOSI) == 0){
    fin_vertical++;
    if ( fin_vertical >= 10 ){
      fin_vertical = 0;
      return 2;
    }
  }
  
  //-----------------------------------------
  if ( digitalRead(MISO) == 0){
    fin_sagital++;
    if ( fin_sagital >= 10 ){
      fin_sagital = 0;
      return 3;
    }
  }
  return 0;
}

// ----------------------------------------------------------
// activa los reles

void setea_reles(int rele)
{
  

}
