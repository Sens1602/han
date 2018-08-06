
/* 
 * File:   adc.c
 * Author: admin
 *
 * Created on 2018/06/01, 13:12
 */

#include <p18f2553.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include <usart.h>
#include <adc.h>

#pragma config PLLDIV=5             // 8 MHz 
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

char AdcRes[11] = {'t', 'o', 'p', 6, 6, 6, 6, 6, 6, 6, 6};
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
    
    //????? 32     20MHz,     12    8MHz
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF &
                USART_ASYNCH_MODE & USART_EIGHT_BIT &
                USART_CONT_RX & USART_BRGH_LOW, 12);
    while(1)
    {
    LATBbits.LATB5 ^= 1;
    Delay10KTCYx(20);
    
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[3] =  ADRESH;
    AdcRes[4] = ADRESL;   
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] =  ADRESH;
    AdcRes[6] = ADRESL;
    
    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] =  ADRESH;
    AdcRes[8] = ADRESL;
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] =  ADRESH;
    AdcRes[10] = ADRESL;
    
    //putrsUSART("waseda");

    
    WriteUSART(AdcRes[0]);
    while(BusyUSART());
    WriteUSART(AdcRes[1]);
    while(BusyUSART());
    WriteUSART(AdcRes[2]);
    while(BusyUSART());
    WriteUSART(AdcRes[3]);
    while(BusyUSART());
    WriteUSART(AdcRes[4]);
    while(BusyUSART());
    WriteUSART(AdcRes[5]);
    while(BusyUSART());
    WriteUSART(AdcRes[6]);
    while(BusyUSART());
    WriteUSART(AdcRes[7]);
    while(BusyUSART());
    WriteUSART(AdcRes[8]);
    while(BusyUSART());
    WriteUSART(AdcRes[9]);
    while(BusyUSART());
    WriteUSART(AdcRes[10]);
    while(BusyUSART());
   
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
    
        
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    
        
   SetChanADC(ADC_CH8);
    ConvertADC();
    while(BusyADC()); 
   AdcRes[3] = ADRESH;//??8???
   AdcRes[4] = ADRESL;//??8???
    
    SetChanADC(ADC_CH9);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[5] = ADRESH;//??8???
    AdcRes[6] = ADRESL;//??8???

    SetChanADC(ADC_CH10);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[7] = ADRESH;//??8???
    AdcRes[8] = ADRESL;//??8???
    
    SetChanADC(ADC_CH11);
    ConvertADC();
    while(BusyADC()); 
    AdcRes[9] = ADRESH;//??8???
    AdcRes[10] = ADRESL;//??8???
    
    

    outbuf[18] = (char)(AdcRes[3] / 10.0);
    outbuf[19] = (char)(AdcRes[4] / 10.0);
    outbuf[20] = (char)(AdcRes[5] / 10.0);
    outbuf[21] = (char)(AdcRes[6] / 10.0);
    outbuf[22] = (char)(AdcRes[7] / 10.0);
    outbuf[23] = (char)(AdcRes[8] / 10.0);
    outbuf[24] = (char)(AdcRes[9] / 10.0);
    outbuf[25] = (char)(AdcRes[10] / 10.0);
     }
    }
