# 1 "pin.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/Applications/microchip/xc8/v2.05/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "pin.c" 2
# 1 "./pin.h" 1
# 14 "./pin.h"
# 1 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 1 3



# 1 "/Applications/microchip/xc8/v2.05/pic/include/c99/musl_xc8.h" 1 3
# 5 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 2 3
# 22 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 1 3
# 135 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 150 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 3
typedef long intptr_t;
# 166 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 196 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 237 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 155 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.05/pic/include/c99/bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 156 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdint.h" 2 3
# 15 "./pin.h" 2
# 1 "/Applications/microchip/xc8/v2.05/pic/include/c99/stdbool.h" 1 3
# 16 "./pin.h" 2



    typedef struct {
        _Bool rising_edge;
        _Bool falling_edge;
        uint16_t status;
        _Bool isHigh;
        _Bool isLow;
        uint8_t cnt;


    } debouncedPin;
# 39 "./pin.h"
    void processPin(debouncedPin * p, _Bool current);

void initPin(debouncedPin * p);
# 2 "pin.c" 2
# 31 "pin.c"
uint8_t countBits(uint32_t in);

void processPin(debouncedPin* p, _Bool current) {
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
