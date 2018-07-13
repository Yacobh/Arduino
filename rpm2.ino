// Variables referentes al calculo de rpm
volatile unsigned long contador = 0;  
volatile unsigned long To;
volatile unsigned long Tf;
unsigned long rpm;

//-----    FUNCIONES   ------------//
void calcula_rpm();


void setup() {
  Serial.begin(57600);
  attachInterrupt(0,interrupcion0,RISING);  // Interrupcion 0 (pin2) // LOW, CHANGE, RISING, FALLING
}

void loop() {
  delay(1000);
  calcula_rpm();
  Serial.println(rpm);
}


void interrupcion0()    
{
  if( contador == 0)
    To = millis();
  else
    Tf = millis();
  contador++;           // Se incrementa en uno el contador
}

void calcula_rpm()
{
  if (contador != 0)  
    rpm =((contador-1)*(60000))/(Tf-To);
  else 
    rpm = 0;
   Serial.print("          RPM ");
   Serial.println(rpm);
  contador = 0;  
  
  //detachInterrupt(0);
  /*
    if (contador <= 0 )
    {
      rpm = 0;        
    }
    else
    {
      detachInterrupt(0);
      rpm =((contador-1)*(60000))/(Tf-To);
      contador = 0;
      Serial.print("          RPM ");
      Serial.println(rpm);
      attachInterrupt(0,interrupcion0,RISING);
    }
     
    */  
}
