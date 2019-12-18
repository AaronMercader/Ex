//
// * File:   CodeLedGreen.c
 //* Author: Aarón Mercader
// *
 //* Created on 21 de octubre de 2019, 10:57 PM
// */

#include <pic16f887.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic.h>
#include <xc.h>
#include "config.h"
#include <stdint.h>
#include <htc.h>
#define _XTAL_FREQ 8000000;

int contador=0;
int adc1=0,adc2=0,adc3=0;
int i,j,k;

void main(void){
    
    TRISAbits.TRISA0=1;
    TRISAbits.TRISA1=1;
    TRISAbits.TRISA2=1;
    ANSEL= 0b11111111;
    ANSELbits.ANS0=1;
    ANSELbits.ANS1=1;
    ANSELbits.ANS2=1;
    
    PORTAbits.RA0=0;
    PORTAbits.RA1=0;
    PORTAbits.RA2=0;
    
    OPTION_REGbits.T0CS=0;
    OPTION_REGbits.PSA=0x00;
    TMR0=0x07;
    TMR0IF=0;
    //CONFIGURACIÓN DE ADC//
    ADCON0bits.ADCS1=1;
    ADCON0bits.ADCS0=0;  //Clock FOSC/32
    
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    
    ADCON1bits.ADFM=1; //J-Der
    ADCON0bits.ADON=1;//ADC
    
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.T0IE=1;
    
    
    while(1){
     
    for(i=0; i<=10;i++){
        ADCON0bits.CHS3=0;
        ADCON0bits.CHS2=0;
        ADCON0bits.CHS1=0;
        ADCON0bits.CHS0=0;
        
        ADCON0bits.GO=1; //Inicialización de conversión
        
        while(ADCON0bits.nDONE==1){
            continue;
        }
        adc1=ADRESL+(ADRESH<<8);
        i=11;
        }
        
        
    for(i=11;i<=20;i++){
        ADCON0bits.CHS3=0;
        ADCON0bits.CHS2=0;
        ADCON0bits.CHS1=0;
        ADCON0bits.CHS0=1;
        
        ADCON0bits.GO=1; //Inicialización de conversión
        
        while(ADCON0bits.nDONE==1){
            continue;
        }
        adc2=ADRESL+(ADRESH<<8);
        i=21;
        }
    
    for(i=21;i<=30;i++){
        ADCON0bits.CHS3=0;
        ADCON0bits.CHS2=0;
        ADCON0bits.CHS1=1;
        ADCON0bits.CHS0=0;
        
        ADCON0bits.GO=1; //Inicialización de conversión
        
        while(ADCON0bits.nDONE==1){
            continue;
        }
        adc3=ADRESL+(ADRESH<<8);
        i=0;
        }
    
    }
      
    
}