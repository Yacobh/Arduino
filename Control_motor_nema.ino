  /* señal PWM */
  /*
   * Se utiliza para la maquina fresadora de walter
   * el control de una velocidad de un motor NEMA0
   */
// configuracion de pines --------------
int finCarrera = A5;
int digPin = 12; // pin digital  que envia el tren de pulsos
int giroPin = 11; // pin giro motor 11
int enable = 10; // enable
int sensorPin = A0;  // determina el sensor que toma los valores desde el divisor de voltaje
int encendido = A1;

// Variables de control
int pot;
int flag = 0;   // bandera que indica si esta encendido o apagado
long T0 = 0 ;  // Variable global para tiempo

//---------------------------
// variables para wel boton on/off
int boton;
int boton_tiempo;
int boton_apagado;

//----------------------------
/*
 * Base de tiempo recopilada para el motor paso a paso 
 * y el driver CW8060 configurado en 1/16
 * para motor nema 23
 */
int base = 10;
int maximo = 1;
int minimo = 1024;

// Contro de giros ------------------- 
long N = 2;

void setup() 
{
  pinMode(digPin, OUTPUT);     // pin en modo salida
  pinMode(giroPin, OUTPUT);     // pin en modo salida
  pinMode(enable, OUTPUT);     // pin en modo salida
  pinMode(finCarrera, INPUT_PULLUP);
  pinMode(encendido, INPUT_PULLUP);
  digitalWrite(enable, 1); // 
  boton_tiempo = 0;
}

void loop() {
  digitalWrite(enable, 1); // 
  //pot = analogRead(sensorPin);
  boton = boton_pulsado();
  if (boton == 1)
    flag = 1;
  else
    flag = 0;
  long counter = 0;
  int contador = 0;
  int giro = 0;
  digitalWrite(giroPin, giro); // 
  while (flag == 1)
  {
    digitalWrite(enable, 0); // 
    for (int i = 0; i < 1; i++)
    {
      counter++;
      digitalWrite(digPin, HIGH); // asigna el valor HIGH al pin 
      delayMicroseconds(base);     // 
      digitalWrite(digPin, LOW); // asigna el valor LOW al pin
      pot = analogRead(sensorPin);
      delayMicroseconds(pot*5);     // espera medio segundo
      if ( digitalRead(finCarrera) == 0)
      {
         contador++;
         if (contador == 5)
         {
            digitalWrite(giroPin, 1); // 
            for ( int i = 0; i <= counter; i++)
           {
              digitalWrite(digPin, HIGH); // asigna el valor HIGH al pin 
              delayMicroseconds(base);     // 
              digitalWrite(digPin, LOW); // asigna el valor LOW al pin
              pot = analogRead(sensorPin); 
              delayMicroseconds(pot*5);     // espera medio segundo 
           }
          flag = 0; 
          break;
         }
      }
      else 
        contador = 0;
    }
  }
}

void ServicioBoton() 
{
  if ( millis() > T0  + 250)
  {   
    if (flag == 0)
      flag = 1;
     //else
      //flag = 0;
     T0 = millis();
  }
   
}

int boton_pulsado()
{
  //------------ Check the button
  int boton_p;
  boton_p = analogRead( encendido );
  if ( boton_p <= 50)
    boton_tiempo++;
  else 
    boton_tiempo = 0;

  if (boton_tiempo >= 10)
  {
   // flag = 1;
    boton_tiempo = 0;
    return 1;
  }
  return 0;
}
