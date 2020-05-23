/* 
 * File:   pin.h
 * Author: rianderous
 *
 * Created on March 14, 2020, 2:13 PM
 */

#ifndef PIN_H
#define	PIN_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>



    typedef struct {
        bool rising_edge;
        bool falling_edge;
        uint16_t status;
        bool isHigh;
        bool isLow;
        uint8_t cnt;


    } debouncedPin;


    //    pin * (pins[]) = (&PM1, &PM2, &PM3, &PM4, &PM5, &PM6, &PM7, &PM8, &PM9, &PM10);

    /**
     * @summary This method implements a debouncing routine and detects high, 
     * low state and rising/falling edges on a single IO pin..
     * @param p the Pin structure to be processed
     * @param current the current status of the pin (High=true, low = false)
     */
    void processPin(debouncedPin * p, bool current);

void initPin(debouncedPin * p);

#ifdef	__cplusplus
}
#endif

#endif	/* PIN_H */

