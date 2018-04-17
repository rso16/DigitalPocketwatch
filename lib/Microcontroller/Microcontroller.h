#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

//includes
#include <stdint.h>


//defines
#define FAILED      0
#define SUCCES      1

#define NOPARITY    0
#define EVENPARITY  1
#define ODDPARITY   2

#define NORMALSPEED 0
#define DOUBLESPEED 1

class Microcontroller
{
  private:

  public:
     virtual void     setDPM(uint8_t pin, uint8_t value)  = 0;  // Set pin mode value = 0 or 1 for the digital pins
     virtual void     setAPM(uint8_t pin, uint8_t value)  = 0;  // Set pin mode value = 0 or 1 for the analog pins
     virtual void     DW(uint8_t pin, uint8_t value)      = 0;  // Digital write(dw) value = 0 or 1
     virtual uint8_t  DR(uint8_t pin)                     = 0;  // Digital read
     virtual void     AW(uint8_t pin, uint8_t value)      = 0;  // Same as dw but with analog pin
     virtual uint16_t AR(uint8_t pin)                     = 0;  // Analog Read
     virtual uint8_t  getPinStat(uint8_t pin)             = 0;  // Returns the status of the pin (HIGH or LOW)
     virtual void     toggleDP(uint8_t pin)               = 0;  // Toggles the a Digital pin (HIGH becomes LOW and vise versa)

     virtual uint8_t getBit(uint8_t data, uint8_t index) = 0;   //Gets the bit for the data (a byte) at the index

     virtual void    sendI2CStart()            = 0; // Sends a start signal on the I2C Bus
     virtual void    sendI2CStop()             = 0; // Sends a stop signal on the I2C Bus
     virtual void    sendI2CAddr(uint8_t addr) = 0; // Sends the the slave address (with the write or read bit)
     virtual void    sendI2CData(uint8_t data) = 0; // sends the data

     virtual void UARTInit(uint8_t dataBits, uint8_t parityBit, uint8_t stopBits, uint32_t baud, uint8_t speed, uint8_t RT) = 0; //fuction to initialize the UART, takes the amount of data bits (5,6,6,8 or 9 bits), no, even or an odd parity bit, the amound of stop bits (1 or 2) and the baudrate 
     virtual void UARTBegin(long int baud)   = 0; //function to begin the UART with the defaul settings and a baudrate.
     virtual void UARTSend(uint16_t data)    = 0; //Sends data (intended for the 9 bit option) 
     virtual void UARTSend(uint8_t data)     = 0; //Sends a byte
     virtual uint8_t UARTRead()              = 0; //Reads a byte
};

#endif
