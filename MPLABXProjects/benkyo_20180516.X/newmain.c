/* 
 * File:   benq.c
 * Author: admin
 *
 * Created on May 16, 2018, 3:36 PM
 */

#include <p18f2553.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include <usart.h>
#include <adc.h>

#pragma config PLLDIV=2             // 8 MHz 
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

char AdcRes[2] = {'w', 'a'};
char text[] = "wasedaaaaa!!!!!!!";
void main(void)
{
    char cmnd = '0';
    int flag = 0;
    TRISA = 0;
    TRISB = 0;
    //TRISB= 0b00011110;
    TRISC = 0;
    OpenADC(ADC_FOSC_64 & ADC_RIGHT_JUST & ADC_20_TAD, ADC_CH8
            & ADC_INT_OFF & ADC_REF_VDD_VSS, 0b00011001);
    
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF &
                USART_ASYNCH_MODE & USART_EIGHT_BIT &
                USART_CONT_RX & USART_BRGH_LOW, 12);
    while(1)
    {
        if(DataRdyUSART())
        {
            cmnd=ReadUSART();
            if(cmnd == '0')
            {
                flag = 0;
            }
            if(cmnd == '1')
            {
                flag = 1;
            }
            if(cmnd == '2')
            {
                flag = 2;
            }
            if(cmnd == '3')
            {
                flag = 3;
            }
            if(cmnd =='4')
            {
                flag =4;
              
            }
        }
    LATBbits.LATB5 = 0;
    Delay10KTCYx(10*(flag+1));
    LATBbits.LATB5 = 1;
    Delay10KTCYx(10*(flag+1));
    /*
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[0] =  ADRESH;
    AdcRes[1] = ADRESL;
    putsUSART(AdcRes);    
    */
    }
}
