
#include <p18f2553.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include <usart.h>

#pragma config PLLDIV=2             // 8 MHz ???
#pragma config CPUDIV=OSC1_PLL2     // 96 MHz
#pragma config USBDIV=2             // 48 MHz
#pragma config FOSC=HS
#pragma config PWRT=ON
#pragma config BOR=OFF
#pragma config BORV=2
#pragma config VREGEN=ON
#pragma config WDT=ON
#pragma config MCLRE=ON
#pragma config LPT1OSC=OFF
#pragma config PBADEN=OFF
#pragma config STVREN=OFF
#pragma config LVP=OFF
#pragma config XINST=OFF
#pragma config DEBUG=OFF
#pragma config CP0=OFF,CP1=OFF,CP2=OFF,CP3=OFF,CPB=OFF,CPD=OFF
#pragma config WRT0=OFF,WRT1=OFF,WRT2=OFF,WRT3=OFF,WRTB=OFF,WRTC=OFF,WRTD=OFF
#pragma config EBTR0=OFF,EBTR1=OFF,EBTR2=OFF,EBTR3=OFF,EBTRB=OFF

int main(void){
    //char han[] = "\r\nOFF"; // \r -> ???\n -> ??
    char cmnd; 
    char on[]  = "\r\nON";
    char off[] = "\r\nOFF";
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF &
                USART_ASYNCH_MODE & USART_EIGHT_BIT &
                USART_CONT_RX & USART_BRGH_LOW, 12);
    while(1){
        while(!DataRdyUSART());
        
        cmnd = ReadUSART();
    
        if(cmnd == '0'){
            LATBbits.LATB5 = 1;
            putsUSART(off);
        }
    
        
        }
    }
}