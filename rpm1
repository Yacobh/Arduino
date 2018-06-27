 volatile long half_revolutions;
 unsigned long rpm;
 unsigned long timeold;
 //  pin de control del laser
int laser = 12; 
 void setup()
 {
   Serial.begin(9600);
   attachInterrupt(0, rpm_fun, RISING);
   half_revolutions = 0;
   rpm = 0;
   timeold = 0;
   
  pinMode(laser, OUTPUT);
  digitalWrite(laser,1);
    delay(10000);
 }
 void loop()
 {
  delay(1000);
  //digitalWrite(laser,0);
   if (half_revolutions >= 20) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm = (60000/(millis() - timeold))*(half_revolutions);
     timeold = millis();
     half_revolutions = 0;
     Serial.print("           ");
     Serial.println(rpm,DEC);
   }
   
   
 }
 void rpm_fun()
 {
  
   half_revolutions++;
   //Serial.println(half_revolutions,DEC);
   //Each rotation, this interrupt function is run twice
 }
//-----------------------------------------------
