#pragma once

// Used the pargmatic preprocessor to ensure this header file is include once to avoid redundancies

#define UART0_Base 0x101F1000 
#define UART1_Base 0x101F2000  // The memory maps of each UART hardware perpheral
#define UART2_Base 0x101F3000
#define UARTFR_Base 0x018  //The offset of the FIFO flags for each all three UART peripherial 


#define UART0_A (*(volatile uint32_t*)0x101F1000)
#define UART1_A (*(volatile uint32_t*)0x101F2000) //Actually pointing to the UART memory address using pointers and dereferncing.
#define UART2_A (*(volatile uint32_t*)0x101F3000)
#define UARTFR_A (*(volatile uint32_t*)(UART0_Base + UARTFR_Base))

//Intializing all the functions that are going to be implemented in the UART_Driver.c code
void UAR_T(const char* input);
void test(void);
bool flagcheck_R(void);
bool flagcheck_T(void);
