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
#define _XTAL_FREQ 4000000
int contador=0;
    
void main(){  
   TRISBbits.TRISB0=0;
   PORTBbits.RB0=0;
   T1CONbits.TMR1ON=1;
   T1CONbits.TMR1CS=0;
   T1CONbits.T1CKPS1=1;
   T1CONbits.T1CKPS0=1;
   
   TMR1=3035;   
   while(1){
      if(TMR1==65535){
          contador++;
          
          if(contador==1){
              PORTBbits.RB0=1;
              TMR1=3035;
          }
          if (contador==2){
              PORTBbits.RB0=0;
              contador=0;
              TMR1=3035;
          }
          
          
   }
      
   }
   return;
   }
   
         
   
   
   