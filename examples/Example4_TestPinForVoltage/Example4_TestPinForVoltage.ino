/*
  This example shows how to test a pin for a specific voltage.

  Here's the function:
  verifyVoltage(pin to test, expected voltage (float), percent of variance allowed (default 10 = 10%), print debug true/(default)false)

  Pete Lewis, started on 11/3/2016
  Contributions by NES November 15th, 2016

  Select Mega2560 from the boards list
*/

#define STATUS_LED 13

#include "SparkFun_Flying_Jalapeno_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Jalapeno
FlyingJalapeno FJ(STATUS_LED, 3.3); //Blink status msgs on pin 13. Board has VCC jumper set to 3.3V.

void setup()
{
  Serial.begin(9600);
  Serial.println("Test pin for voltage example");

  FJ.setRegulatorVoltage1(5.0); //Set regulator1 to 5V
  FJ.setRegulatorVoltage2(3.3); //Set regulator2 to 3.3V

  if(FJ.testRegulator1() == false)
  {
    Serial.println("Whoa! Short on power rail 1");
    while(1);
  }

  if(FJ.testRegulator2() == false)
  {
    Serial.println("Whoa! Short on power rail 2");
    while(1);
  }

  //Now power up the target
  FJ.enableRegulator1();
  FJ.enableRegulator2();
}

void loop()
{
  boolean result1 = FJ.verifyVoltage(A6, 3.3); //Test to see if pin A6 is at 3.3V
  
  if(result1 == true)
  {
    Serial.println("Pin is at 3.3V!");
  }
  else
  {
    Serial.println("Pin is NOT at 3.3V!");
  }

  //This demonstrates the extended call to the function
  boolean result2 = FJ.verifyVoltage(A6, 3.3, 10, true); //A6, 3.3V, within 10%, and print debug statements
  
  if(result2 == true)
  {
    Serial.println("Pin is at 3.3V!");
  }
  else
  {
    Serial.println("Pin is NOT at 3.3V!");
  }

  delay(1000);  
}
  
