 /* as long as the NMEA signal does not exceed 5v (RS232 can be up to +13V to 13v) 
  * a connector can be lead from the TX port of the NMEA device to the RX port on the ESP32
  * in this case it is GPIO16 
  * 
  * when the serial is openned up , it is inverted since RS232 is the basically the inversion of TTL
  * this was much easier than putting a MAX3232 in between. If the signal on your NMEA device is > 5v (check with a multimeter) then do 
  * use this as it might damage your ESP32
  * 
  * It might be nice if the 
  */
 
 #include <nmea.h>  
 #include<HardwareSerial.h>

#define RXD2 16
#define TXD2 17
   
 HardwareSerial nmeaSerial(2);  
 NMEA nmeaDecoder(ALL);   
   
 void setup()  
 {  
  Serial.begin(115200);  
  nmeaSerial.begin(4800, SERIAL_8N1, RXD2, TXD2, true);  
 }  
   
 void loop()  
 {  
   if (nmeaSerial.available() > 0 ) {  
     if (nmeaDecoder.decode(nmeaSerial.read())) {  // if we get a valid NMEA sentence  
       Serial.println(nmeaDecoder.sentence());  
       char* t0 = nmeaDecoder.term(0);  
       char* t1 = nmeaDecoder.term(1);  
       char* t2 = nmeaDecoder.term(2);  
       char* t3 = nmeaDecoder.term(3);  
       char* t4 = nmeaDecoder.term(4);  
       char* t5 = nmeaDecoder.term(5);  
       char* t6 = nmeaDecoder.term(6);  
       char* t7 = nmeaDecoder.term(7);  
       char* t8 = nmeaDecoder.term(8);  
       char* t9 = nmeaDecoder.term(9);  
       char* t10 = nmeaDecoder.term(10);
       char* t11 = nmeaDecoder.term(11);    
       Serial.print("Term 0: ");  
       Serial.println(t0);  
       Serial.print("Term 1: ");  
       Serial.println(t1);  
       Serial.print("Term 2: ");  
       Serial.println(t2);  
       Serial.print("Term 3: ");  
       Serial.println(t3);  
       Serial.print("Term 4: ");  
       Serial.println(t4);  
       Serial.print("Term 5: ");  
       Serial.println(t5);  
       Serial.print("Term 6: ");  
       Serial.println(t6);  
       Serial.print("Term 7: ");  
       Serial.println(t7);  
       Serial.print("Term 8: ");  
       Serial.println(t8);  
       Serial.print("Term 9: ");  
       Serial.println(t9);  
       Serial.print("Term 10: ");  
       Serial.println(t10); 
       Serial.print("Term 11: ");  
       Serial.println(t11);            
       Serial.println("--------");  
     }  
   }  
 } 
