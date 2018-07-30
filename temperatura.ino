
#include <i2cmaster.h>

void setup()
{
  Serial.begin(9600);
  Serial.println("Setup...");
  
  // Setup I2CBus
  i2c_init(); //Initialise then,
  PORTC = (1 << PORTC4) | (1 << PORTC5); //enable pullups
}

void loop()
{
  float temperature1 = readDevice(0x5A);   // addresses from the scanner
  float temperature2 = readDevice(0x55);  
  //float temperature3 = readDevice(0x53);
  //float temperature4 = readDevice(0x54);

  // Print Data To Screen...
  Serial.println("Temperature Readings (*c):");
  Serial.print("> A1(5A): ");
  Serial.println(temperature1);
  Serial.print("> A2(55): ");
  Serial.println(temperature2);
  //Serial.print("> A3(53): ");
  //Serial.println(temperature3);
  //Serial.print("> A4(54): ");
  //Serial.println(temperature4);

  delay(2000); 
}

/////////////////////////////////////////////////////////
//
// helper functions
//

float readDevice(int address)
{
  int dev = address << 1;
  int data_low = 0;
  int data_high = 0;
  int pec = 0;

  // RAW READ
  i2c_start_wait(dev + I2C_WRITE);

  i2c_write(0x07);

  i2c_rep_start(dev + I2C_READ);
  
  data_low = i2c_readAck(); //Read 1 byte and then send ack
  data_high = i2c_readAck(); //Read 1 byte and then send ack
  pec = i2c_readNak();
  i2c_stop();
  
  //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
  double tempFactor = 0.02; // 0.02 degrees per LSB (measurement resolution of the MLX90614)
  double tempData = 0x0000; // zero out the data
  int frac; // data past the decimal point
    
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  tempData = (double)(((data_high & 0x007F) << 8) + data_low);
  tempData = (tempData * tempFactor)-0.01;

  //Process tempData
  float objTemp = tempData - 273.15;
  delay(500);
  return objTemp;

}
