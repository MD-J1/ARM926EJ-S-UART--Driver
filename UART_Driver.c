#include <stdint.h>
#include <stdbool.h>
#include "intials.h"

//The UART_I function that takes the input as characters since C does not have the string data type.

//we point to this input/function paramters using pointers and make it a const so we point to the same adderess to recieve the full input
void UART_I(const char* input){

while(*input){
UART0_A = (uint32_t)*input;
input++;}

}

//The flagcheck function to tell us if the RXFE Receive FIFO empty.
bool flagcheck_R(void){
int BitMask = (1 << 4); //BitMask because the reciver fifo flag is the 4th bit and this bitmask will make the 4th bit a one out of thirty two bits since the ARM926EJ-S has a thirty bit architecture 

while(UARTFR_A){//Using the preprocesser i defined in the intials header file
if(UARTFR_A & BitMask){ //Using the AND logic to ensure the reciever fifo bit is identical to the bitmask
return true;}

else{
return false;}

}
}


// The flagcheck_T function has the same purpose as the flagcheck_R function the only difference is that this function is meant for checking if the transmit FIFO bit is empty so we can know when to transmit
bool flagcheck_T(void){
int BitMask = (1 << 7); // Bit mask to check if the 7 bit is empty 
while(UARTFR_A){

if(UARTFR_A & BitMask){
return true;}

else{
return false;}

}
}


void test(void){
bool Transmit = flagcheck_T();
bool Recieve = flagcheck_R();

if(Transmit == true && Recieve == true){
UART_I("D++");
while(1){}
}
}



