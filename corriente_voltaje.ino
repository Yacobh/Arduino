const int pinCorriente = A0; 
const int pinVoltaje = A1; 

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float lecturaCorriente;
  float lecturaVoltaje;
  float corriente;
  float voltaje;
  float corriente_promedio = 0;
  float voltaje_promedio = 0;
  
  
  
  //----------------------------------------------------------
  int muestras = 8000;
  for( int i = 0; i < muestras; i++)
  {
    //--//
    lecturaVoltaje = analogRead(pinVoltaje);
    lecturaCorriente = analogRead(pinCorriente);
    
    //--//
    voltaje = (lecturaVoltaje/1023)*5;
    corriente = (lecturaCorriente/1023)*10.41 ;
    
    //--//
    corriente_promedio = corriente_promedio + corriente;
    voltaje_promedio = voltaje_promedio + voltaje;
  }
  voltaje = voltaje_promedio*100/(muestras);
  corriente = corriente_promedio/muestras;
  //-----------------------------------------------------------
  
  Serial.print("Voltaje " );
  Serial.print(voltaje);
  Serial.println(" v");
  Serial.print("Corriente " );
  Serial.print(corriente);
  Serial.println(" A");
  

  //delay(5000);
}
