#include "pin.h"
#include <stdbool.h>
#include <stdint.h>



/*uint8_t maxConsecutiveBits(uint32_t in, bool one){
    uint8_t c;
    uint32_t v = in;
    if(!one) v=~v;
    for(c= 0; v; c++){
        v = (v & (v <<1));
    }
    return c; 
}*/
/*
 * File:   countOnes.c
 * Author: rianderous
 *
 * Created on March 28, 2020, 10:01 AM
 */


#include <stdint.h>
/**
 * @summary counts the number of bits set/cleared in an integer
 * @param in the integer to check
 * @param one TRUE = count '1', false count '0'
 * @return the number of bits set/cleared in in
 */
uint8_t countBits(uint32_t in);

void processPin(debouncedPin* p, bool current) {
    p->status = p->status * 2;
    if(current) p->status +=1;
    
    p->falling_edge = (p->isHigh && p->status!=0xFFFF); 
    p->rising_edge = (p->isLow && p->status == 0XFFFF);
    
    p->isHigh = p->status == 0XFFFF;
    p->isLow = !p->isHigh;
}

void initPin(debouncedPin * p){
    p->status = 0xFFFF;
}



