/* 
 * File:   inputFilter.h
 * Author: rianderous
 *
 * Created on March 29, 2020, 9:51 PM
 */

#ifndef INPUTFILTER_H
#define	INPUTFILTER_H

#ifdef	__cplusplus
extern "C" {
#endif

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 1000 Hz

fixed point precision: 8 bits

* 0 Hz - 50 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 150 Hz - 500 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#include <stdint.h>
#define INPUTFILTER_TAP_NUM 13
    

typedef struct {
  int8_t history[INPUTFILTER_TAP_NUM];
  unsigned int last_index;
} inputFilter;

void inputFilter_init(inputFilter* f);
void inputFilter_put(inputFilter* f, int8_t input);
int16_t inputFilter_get(inputFilter* f);


#ifdef	__cplusplus
}
#endif

#endif	/* INPUTFILTER_H */

