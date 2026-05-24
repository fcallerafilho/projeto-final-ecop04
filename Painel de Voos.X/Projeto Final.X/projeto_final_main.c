#include <pic18f4520.h>
#include "config.h"
#include "ssd.h"
#include "lcd.h"
#include "io.h"
#include "config.h"
#include "bits.h"
#include "keypad.h"

#define ON 0x0F
#define CLR 0x01

void main()
{
    unsigned int time = 0, value = 60, valor = 0, time2 = 0;
    float tempo;
    unsigned int tecla;
   
    TRISB = 0x00;
    PORTB = 0x00;
    
    kpInit();
    lcdCommand(ON);
    ssdInit(); 
    lcdInit();
    
    ssdDigit(6,2); 
    
    lcdData('V'); lcdData('o'); lcdData('o'); lcdData(' '); 
    lcdData('L'); lcdData('A'); lcdData('8'); lcdData('0'); lcdData('7'); lcdData('0');
    lcdCommand(0xC0);        
    lcdData('E'); lcdData('m'); lcdData('b'); lcdData('a'); lcdData('r'); lcdData('q'); lcdData('u'); lcdData('e');
    lcdData('I'); lcdData('m'); lcdData('e'); lcdData('d'); lcdData('i'); lcdData('a'); lcdData('t'); lcdData('o');
     
    
    for (;;)
    {   
        PORTB = 0xFF;
        
        
        for(time = 0; time < 250; time++); 
        
        if (value % 2 == 0)
        {
            PORTB = 0x00;
        }
        
        time2++;
        
        if(time2 >= 250) 
        {
            time2 = 0;
            value--;
            ssdDigit((value % 10),3);
            ssdDigit((value / 10) % 10,2);
        }
            
            if (value == 0)
            {   
                lcdCommand(CLR);
                PORTB = 0x00;
                for (tempo = 0; tempo < 450; tempo++)
                { 
                    lcdData('V'); lcdData('o'); lcdData('o'); lcdData(' '); 
                    lcdData('L'); lcdData('A'); lcdData('8'); lcdData('0'); lcdData('7'); lcdData('0');
                    lcdCommand(0xC0);        
                    lcdData('D'); lcdData('e'); lcdData('c'); lcdData('o'); lcdData('l'); lcdData('o'); lcdData('u'); 
                    lcdData(' '); lcdData(' '); lcdData(' '); lcdData(' '); lcdData(' '); lcdData(' '); lcdData(' ');
                    lcdData(' '); lcdData(' '); lcdData(' '); 
                    
               }
                
                value = 60;
                ssdDigit(6,2);
                
                lcdCommand(CLR);
                lcdData('V'); lcdData('o'); lcdData('o'); lcdData(' '); 
                lcdData('L'); lcdData('A'); lcdData('8'); lcdData('0'); lcdData('7'); lcdData('0');
                lcdCommand(0xC0);        
                lcdData('E'); lcdData('m'); lcdData('b'); lcdData('a'); lcdData('r'); lcdData('q'); lcdData('u'); lcdData('e');
                lcdData('I'); lcdData('n'); lcdData('i'); lcdData('c'); lcdData('i'); lcdData('a'); lcdData('d'); lcdData('o');
               
                   
            }  
        
        kpDebounce();
        if (kpRead() != tecla)
            {
                tecla = kpRead();
                if (bitTst(tecla, 2))
                {
                    lcdCommand(CLR);
                    lcdData('D'); lcdData('e'); lcdData('s'); lcdData('t'); lcdData('i'); lcdData('n'); lcdData('o'); lcdData(':'); lcdData(' '); 
                    lcdData('A'); lcdData('e'); lcdData('r'); lcdData('o'); lcdData('.'); 
                    lcdCommand(0xC0);
                    lcdData('I'); lcdData('n'); lcdData('t'); lcdData('.'); lcdData(' '); lcdData('F'); lcdData('r'); lcdData('a'); lcdData('n'); lcdData('k'); lcdData('f'); lcdData('u'); lcdData('r'); lcdData('t');
                }
                
                if (bitTst(tecla, 3))
                {
                    lcdCommand(CLR);
                    lcdData('V'); lcdData('o'); lcdData('o'); lcdData(' '); 
                    lcdData('L'); lcdData('A'); lcdData('8'); lcdData('0'); lcdData('7'); lcdData('0');
                    lcdCommand(0xC0);        
                    lcdData('E'); lcdData('m'); lcdData('b'); lcdData('a'); lcdData('r'); lcdData('q'); lcdData('u'); lcdData('e');
                    lcdData('I'); lcdData('n'); lcdData('i'); lcdData('c'); lcdData('i'); lcdData('a'); lcdData('d'); lcdData('o');
                }
                
                if (bitTst(tecla, 4))
                {
                    lcdCommand(CLR);
                    lcdData('A'); lcdData('e'); lcdData('r'); lcdData('o'); lcdData('n'); lcdData('a'); lcdData('v'); lcdData('e'); lcdData(':');
                    lcdCommand(0xC0);        
                    lcdData('B'); lcdData('o'); lcdData('e'); lcdData('i'); lcdData('n'); lcdData('g'); lcdData(' '); 
                    lcdData('7'); lcdData('7'); lcdData('7'); lcdData('-'); lcdData('3'); lcdData('0'); lcdData('0'); lcdData('E'); lcdData('R');
                }
                
                if (bitTst(tecla, 5))
                {
                    lcdCommand(CLR);
                    lcdData('M'); lcdData('a'); lcdData('t'); lcdData('r'); lcdData('i'); lcdData('c'); lcdData('u'); lcdData('l'); lcdData('a'); lcdData(':');
                    lcdCommand(0xC0);        
                    lcdData('P'); lcdData('T'); lcdData('-'); lcdData('M'); lcdData('U'); lcdData('A');  
                }
                
                if (bitTst(tecla, 6))
                {
                    lcdCommand(CLR);
                    lcdData('T'); lcdData('e'); lcdData('m'); lcdData('p'); lcdData('o'); lcdData(' '); 
                    lcdData('e'); lcdData('s'); lcdData('t'); lcdData('i');lcdData('m'); lcdData('a'); lcdData('d'); lcdData('o');
                    lcdCommand(0xC0);
                    lcdData('d'); lcdData('e'); lcdData(' '); lcdData('v'); lcdData('o'); lcdData('o'); lcdData(':'); lcdData('1'); lcdData('1'); lcdData('h'); 
                    lcdData('3'); lcdData('5'); lcdData('m'); lcdData('i'); lcdData('n');     
                }
            }
        
        ssdUpdate();
    }

}