#include "delay.h"
#include <pic18f4520.h>
#include "config.h"

void tempo(unsigned char x)
{
    volatile unsigned char j, k, i;
    
    for (i = 0; i < x/2; i++) //cria atraso de 0,5 seg
    {
        for(j = 0; j < 41; j++) 
        {
            for(k = 0; k < 3; k++);
        }
    }
  
}