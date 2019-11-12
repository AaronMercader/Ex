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
#include <eeprom_routines.h>
#include <stdint.h>
#include <htc.h>
#define _XTAL_FREQ 4000000
//PORTCbits.RC0 //Verde Clave Correcta
//PORTCbits.RC1 //Rojo Clave Incorrecta
//PORTCbits.RC2 //Amarillo Cambia NIP
//PORTCbits.RC3//Azul Cambio con Exito
int cmil,ccen,mil;
int cen,dec,uni;
int val;
int Contra=1111;
int check=0;
int askpass=0;



unsigned char donde;
unsigned char valor;
void eeprom_escribir(donde, valor){
while(EECON1bits.WR==1);
   
    EEADR=donde;
    EEDATA=valor;
    EECON1bits.EEPGD=0;//Se pone a 0 para programar en la EEPROM
    EECON1bits.WREN=1;
    INTCONbits.GIE=0;
    EECON2=0x55;
    EECON2=0xAA;
    EECON1bits.WR=1;
    INTCONbits.GIE=1;
    EECON1bits.WREN=0;
while(EECON1bits.WR==1);
}
unsigned char eeprom_leer(donde){
    EEADR=donde;
    EECON1bits.EEPGD=0;
    EECON1bits.RD=1;
    return EEDATA;
}




void teclado(){
    int gohead;
    gohead=0;
   
    while (gohead==0){
        PORTBbits.RB0=1;
        PORTBbits.RB1=1;
        PORTBbits.RB2=1;
        PORTBbits.RB3=0;//FILA 1
        if(PORTBbits.RB7==0){
                val=1;
            if(val==1)gohead=1;
        }
        
        if(PORTBbits.RB6==0){
                val=4;
            if(val==4)gohead=1;
        }
        if(PORTBbits.RB5==0){
                val=7;
            if(val==7)gohead=1;
        }
        if(PORTBbits.RB4==0){
                val=13;
            if(val==13)gohead=1;
        }
        PORTBbits.RB0=1;
        PORTBbits.RB1=1;
        PORTBbits.RB2=0;
        PORTBbits.RB3=1;//FILA 2
          if(PORTBbits.RB7==0){
                val=2;
            if(val==2)gohead=1;
        }
        
        if(PORTBbits.RB6==0){
                val=5;
            if(val==5)gohead=1;
        }
        if(PORTBbits.RB5==0){
                val=8;
            if(val==8)gohead=1;
        }
        if(PORTBbits.RB4==0){
                val=0;
            if(val==0)gohead=1;
        }
        PORTBbits.RB0=1;
        PORTBbits.RB1=0;
        PORTBbits.RB2=1;
        PORTBbits.RB3=1;//FILA 3
        if(PORTBbits.RB7==0){
                val=3;
            if(val==3)gohead=1;
        }
        
        if(PORTBbits.RB6==0){
                val=6;
            if(val==6)gohead=1;
        }
        if(PORTBbits.RB5==0){
                val=9;
            if(val==9)gohead=1;
        }
        if(PORTBbits.RB4==0){
                val=14;
            if(val==14)gohead=1;
        }
        PORTBbits.RB0=0;
        PORTBbits.RB1=1;
        PORTBbits.RB2=1;
        PORTBbits.RB3=1;//FILA 4
        if(PORTBbits.RB7==0){
                val=10;
            if(val==10)gohead=1;
        }
        
        if(PORTBbits.RB6==0){
                val=11;
            if(val==11)gohead=1;
        }
        if(PORTBbits.RB5==0){
                val=12;
            if(val==12)gohead=1;
        }
        if(PORTBbits.RB4==0){
                val=16;
            if(val==16)gohead=1;
        }
        
    }while(gohead==1){
        return;
    }
    }
void pedirClave(){
    int gohead1=0;
    while(gohead1==0){
     PORTCbits.RC3=1;
       
    teclado();
    if(val==13){
        check=1;
         PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
        gohead1=1;
        return;
    }
    else{
        mil=val*1000;
        
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
    }
    
    
    teclado();
    if(val==13){
        check=1;
         PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
        gohead1=1;
        return;
    }
    else{
       cen=val*100;
       /*if(cen==800)TRAMPILLA
           PORTCbits.RC0=1;
           __delay_us(5000000);
           PORTCbits.RC0=0;*/
       
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0; 
    }
    
    teclado();
    if(val==13){
        check=1;
         PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
        gohead1=1;
               
             return;
    }
    else{
        dec=val*10;
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
    }
    
    teclado();
    if(val==13){
        check=1;
         PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
      gohead1=1;
              return;
    }
    else{
        uni=val;
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
        gohead1=1;
     return;
     
    }
    while(gohead1==1){
        check=1;
        PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
        __delay_us(1000000);
        PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
       
        return;
    }
    }
}
void cambiarClave(){
    
    check=0;
    int clave=0;
    PORTCbits.RC0=0;
    PORTCbits.RC3=0;
    __delay_us(1000000);
    PORTCbits.RC0=1;
    PORTCbits.RC3=1;
    __delay_us(500000);
    PORTCbits.RC0=0;
    PORTCbits.RC3=0;
    __delay_us(500000);
    PORTCbits.RC0=1;
    PORTCbits.RC3=1;
   
    pedirClave();
     __delay_us(500000);
    PORTCbits.RC0=0;
    PORTCbits.RC3=0;
     __delay_us(500000);
    PORTCbits.RC0=1;
    PORTCbits.RC3=1;
     __delay_us(1000000);
    PORTCbits.RC3=0;
     __delay_us(1000000);
    PORTCbits.RC3=1;
    clave=mil+cen+dec+uni;
    
    
   
    if(clave==Contra){
        PORTCbits.RC2=1;
        PORTCbits.RC3=1;
        PORTCbits.RC0=0;
        __delay_us(1000000);
        PORTCbits.RC2=0;
        
        teclado();
        if(val==13){
            return;
        }
        else{
            cmil=val;
            
            eeprom_escribir(1,cmil);//PORQUE PONERLO COMO LOS OTROS NO LEÍA EL VALOR COMO TAL
            PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
        
        }
        teclado();
        if(val==13){
            return;
        }
        else{
        ccen=val;
        eeprom_escribir(2,ccen);//corrección
       
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0; 
        }
        teclado();
        if(val==13){
            return;
        }
        else{
        dec=val*10;
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
        }
        
        teclado();
        if(val==13){
            return;
        }
        else{
        uni=val;
        PORTCbits.RC2=1;
        __delay_us(1000000);
        PORTCbits.RC2=0;
        }
        mil=cmil*1000;//SSÓLO ASÍ
        cen=ccen*100;
        clave=mil+cen+dec+uni;
        
      
      //creo que si no lo leía era por uncorchete de más...
      
      eeprom_escribir(3,dec);
      eeprom_escribir(4,uni);
      eeprom_escribir(5,12);
      
      Contra=clave;
        return;
        }
    
    else{//CLAVE INCORRECTA PARA CAMBIAR DE CLAVE
        PORTCbits.RC0=0;
        PORTCbits.RC1=1;
        PORTCbits.RC2=0;
        PORTCbits.RC3=0;
        __delay_us(2000000);
        PORTCbits.RC1=0;
        __delay_us(100000);
        return;
        }
    return;
}
void main(void){ 

    int che;
    int clave;
    ANSELHbits.ANS8=0;
    ANSELHbits.ANS9=0;
    ANSELHbits.ANS10=0;
    ANSELHbits.ANS11=0;
    ANSELHbits.ANS12=0;
    ANSELHbits.ANS13=0;
       
    OPTION_REGbits.nRBPU=0;//Activador de pullups del puerto B
    TRISBbits.TRISB4=1;
    TRISBbits.TRISB5=1;
    TRISBbits.TRISB6=1;
    TRISBbits.TRISB7=1;//RB4 A RB7 ENTRADA DIGITAL FILA
    TRISB&=~(15<<0); // RB0 A RB3 SALIDA DIGITAL COLUMNA
    PORTBbits.RB0=1; 
    PORTBbits.RB1=1;
    PORTBbits.RB2=1;
    PORTBbits.RB3=1;//RB0 A RB3 PONEMOS EN 1111
  
    INTCON=0; //limpia registro en intcon
    INTCONbits.GIE=0;//Habilitación de las interrupciones globales
    INTCONbits.RBIE=1;//Interrupciones del RB4 AL RB7
    INTCONbits.RBIF=0; //Bandera de Interrupción de RB4 AL RB7
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    TRISC&=~(15<<0); //RC0 al RC3 Definidos como salidas Digitales para PRENDER leds
    PORTCbits.RC0=0;
    PORTCbits.RC1=0;//Poner a 0000
    PORTCbits.RC2=0;
    PORTCbits.RC3=0;
   
    
   
      askpass= eeprom_leer(5);
    if(askpass!=12){
        Contra=1111;
        PORTCbits.RC0=1;
        __delay_us(1000000);
        PORTCbits.RC0=0;
        __delay_us(1000000);
    }
    else
    {
        cmil= eeprom_leer(1);
        ccen= eeprom_leer(2);
        dec= eeprom_leer(3);
        uni= eeprom_leer(4);
        mil=cmil*1000;
        cen=ccen*100;
        clave=mil+cen+dec+uni;
        Contra=clave;
        
        /*
        if(mil==7000){
            PORTCbits.RC0=1;
            __delay_us(5000000);
        }
        if(cen==800){
            PORTCbits.RC1=1;
            __delay_us(5000000);
        }
        if(dec==90){
            PORTCbits.RC2=1;
            __delay_us(5000000);
        }
        if(uni==4){
            PORTCbits.RC3=1;
            __delay_us(5000000);
        }*/
        
        
        
        
    }
    while(1){
        PORTCbits.RC0=1;
        PORTCbits.RC1=1;
        PORTCbits.RC2=1;
        PORTCbits.RC3=1;
        __delay_us(500000);
         PORTCbits.RC0=0;
        PORTCbits.RC1=0;
        PORTCbits.RC2=0;
        PORTCbits.RC3=0;
        __delay_us(500000);
          PORTCbits.RC0=1;
        PORTCbits.RC1=1;
        PORTCbits.RC2=1;
        PORTCbits.RC3=1;
        __delay_us(1000000);
         PORTCbits.RC0=0;
        PORTCbits.RC1=0;
        PORTCbits.RC2=0;
        PORTCbits.RC3=0;
        
      
     
        pedirClave();
        che=check;//HERE IS
        if(che==1){
            cambiarClave();
            return;
        }
        else{
         PORTCbits.RC3=0;
         __delay_us(500000);
         PORTCbits.RC3=1;
          __delay_us(500000);
         PORTCbits.RC3=0;
            
         clave= mil+cen+dec+uni; 
         
        if(clave==Contra){
               PORTCbits.RC0=1;
                __delay_us(3000000);
               PORTCbits.RC0=0;
               __delay_us(1000000);
            }
            else
            {
               PORTCbits.RC1=1;
                __delay_us(2000000);
               PORTCbits.RC1=0; 
               __delay_us(1000000);
               return;
            }
    }
return;
    }
      
    }
