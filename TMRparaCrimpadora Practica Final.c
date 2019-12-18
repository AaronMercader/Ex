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

int contador1=0,contador2=0,contador3=0;
int power;
int ready=0;
int x=2;//Tiempo ajustable piston
int y=2;//Tiempo ajustable Motor
//void ajusteVelP(){
  //  if((PORTBbits.RB1==1)&&(PORTCbits.RC3==1)){
    //       x--;
      //     PORTCbits.RC1=1;
      
        //   if(contador3==2){
 //         // PORTCbits.RC1=0;
               //   }
 //   }
 //       if((PORTBbits.RB2==1)&&(PORTCbits.RC3==1)){
  //         x++;
 //          PORTCbits.RC2=1;
 //          if(contador3==1){
 //          PORTCbits.RC2=0;
 //                 }
 //       }
 //   return;
                  
// }
//void ajusteVelM(){
    
  //  if((PORTBbits.RB1==1)&&(PORTCbits.RC3==0)){
    //       y--;
      //     PORTCbits.RC1=1;
      
        //   if(contador3==2){
        //   PORTCbits.RC1=0;
          //        }
   // }
     //   if((PORTBbits.RB2==1)&&(PORTCbits.RC3==0)){
       //    y++;
         //  PORTCbits.RC2=1;
    //       if(contador3==2){
    //       PORTCbits.RC2=0;
    //              }
    //    }
    //return;
 // } 

void main(){  
    ANSELH=0x00;
    
  // TRISBbits.TRISB0=1;//Activador de Sistema
  // TRISBbits.TRISB1=1;//DISMINUYE    -
  // TRISBbits.TRISB2=1;//AUMENTA      +
  // TRISBbits.TRISB3=1;//MODO ON/OFF (´p)
   
  // TRISBbits.TRISB4=0;//ELECTRO
  // TRISBbits.TRISB5=0;//MOTOR
   
   TRISCbits.TRISC0=0;//LED I/O
   TRISCbits.TRISC1=0;//PARPADEA SI HACE CAMBIO -  TRISCbits.TRISC2=0;//PARPADEA SI HACE CAMBIO +
  // TRISCbits.TRISC3=0;//LED ON: CONVEL PISTON. LED OFF: CONVEL MOTOR
   PORTCbits.RC0=0;
   PORTCbits.RC1=0;
   //PORTCbits.RC2=0;
   //PORTCbits.RC3=0;
   
   //PORTBbits.RB4=0;
   //PORTBbits.RB5=0;
   
   T1CONbits.TMR1ON=1;
   T1CONbits.TMR1CS=0;
   T1CONbits.T1CKPS1=1;
   T1CONbits.T1CKPS0=1;
   //int mode=0;
   //int sistema;
   int activamotor;
   TMR1=3035;
   while(1){    
       
    //   if(PORTBbits.RB0==1){
    //       power++;
          
    //   }
    //    if(power==1){
     //       PORTCbits.RC0=1;
     //      sistema=1;
     //   }
     //   if(power!=1){
     //         PORTCbits.RC0=0;
     //         sistema=0;
     //         power=0;
      //        return;
    //    }
   
       
     //  if(PORTBbits.RB3==1){
     //      mode++;
          
     //  }
     //   if(mode==1){
     //       PORTCbits.RC3=1;
            
     //   }
     //   if(mode!=1){
     //         PORTCbits.RC3=0;
     //         mode=0;
    //          return;
  //      }
   
       //while(sistema){
               
  //     ajusteVelM();
 //      ajusteVelP();
               if(TMR1==65535){
               contador1++;
             
               //contador3++;
               if(contador1==4){
               PORTCbits.RC0=1;//Electrovalvula
               activamotor=0;
               TMR1=3035;
                        }
               if(contador1==8){
               PORTCbits.RC0=0;
               activamotor=1;
             
               TMR1=3035;
               }
               if(activamotor==1){
               PORTCbits.RC1=1;//motor
               TMR1=3035;
                        }
               if(contador1==10){
               PORTCbits.RC1=0;
               contador1=0;
               TMR1=3035;
               }
               }
       }
   return;
   }

