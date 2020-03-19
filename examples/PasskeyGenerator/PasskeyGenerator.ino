/* PasskeyGenerator.ino

   This sketch demonstrates how to use the Arduino_CRC32
   library to calculate a CRC-32 checksum using a simple example of Random passkey suggester.

  Written by Abhijeet Kadam
*/

/**************************************************************************************
   INCLUDE
 **************************************************************************************/

#include <Arduino_CRC32.h>

/**************************************************************************************
   GLOBAL VARIABLES
**************************************************************************************/

Arduino_CRC32 crc32;

char str1;

char const ex_msg[] = "My_PassKey";         //your message here

long randNumber;
uint32_t crc_code;
uint32_t final_passkey;
/**************************************************************************************
   SETUP/LOOP
 **************************************************************************************/
 
void setup()
{
  Serial.begin(9600);
 crc_code = crc32.calc((uint8_t const *)ex_msg, strlen(ex_msg));        // CRC code generation
Serial.println("Welcome to Random passkey suggester enter y to continue..");
  Serial.println("NOTE: you can change your message in passkey_generator.ino");
}
void loop()
{
  if (Serial.available() > 0)
  {
    str1 = Serial.read();              // read the incoming:
    if (str1 == 'y' || str1 == 'Y')
    {
      Serial.print("Your message : ");
      Serial.println(ex_msg);
      Serial.print("Your passkey suggestion : ");
     final_passkey = crc_code * random(30, 4000) - random(5000); // passkey generation
    Serial.println(final_passkey);
      Serial.println("Enter y for new passkey suggestion");
      Serial.println();
   }
  }
}
