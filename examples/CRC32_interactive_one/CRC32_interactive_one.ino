/* CRC32_interactive_one.ino
 * 
 * This sketch demonstrates when to use CRC checksum 
 * by playing a beuatiful game with you
 * 
 * khaled ahmed abdelgalil
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_CRC32.h>
/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/
//global object that contains functions of crc
Arduino_CRC32 g_crc32;
//global variable to store in it reading byte
char g_incomingByte; 
//global variable to store result of CRC in it
uint32_t g_crc32_res;
//global variable to store your guess
uint32_t g_guess=0;
//global variable used for some operations
uint32_t g_mul=1;
/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

//put at setup section the code to be executed once
void setup()
{
  Serial.begin(9600);
  

  
  char const str[] = "Hi";
  g_crc32_res = g_crc32.calc((uint8_t const *)str, strlen(str));

  Serial.println("Try to guess the word  and give us its CRC if you succeded we will tell you  what's the purpose of CRC,");
  Serial.println("the word is said when you meet someone and it begins with capital letter");
 Serial.println("HINT:You can use CRC32.ino to get CRC of your guessed word");
 //Serial.println(g_crc32_res);
}

void loop()
{
  
  if(Serial.available() > 0) {
      g_incomingByte = Serial.read();
       Serial.write(g_incomingByte);
   //if pressed enter   
  if((int)g_incomingByte==13)
  {
   /* Serial.println("guess:");
    Serial.println(guess);*/
    
    if(g_guess==g_crc32_res)
    {
      Serial.println("Congrutlations you guessed correct,Now we can tell you:CRC is used for error detection,");
      Serial.println("if two devices want to exchange information between themselves,");
      Serial.println("sender will send message and CRC(say c1) calculated to reciever,");
      Serial.println("at reciever :reciever will take message and recalculate CRC (say c2),");
      Serial.println("and then compare c1 with c2 if they are equal the message is correct"); 
      Serial.println("and no error happened during transimission");

    }
   else Serial.println("Sorry,you can try again");
   g_guess=0;
  
   }  
   else  {g_guess=g_guess*10+((int)g_incomingByte-48); }
  }
}
