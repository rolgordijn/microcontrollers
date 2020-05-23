#include "inputFilter.h"
#include <stdint.h>

static int8_t filter_taps[INPUTFILTER_TAP_NUM] = {
  2,
  4,
  8,
  13,
  17,
  21,
  22,
  21,
  17,
  13,
  8,
  4,
  2
};

void inputFilter_init(inputFilter* f) {
  int i;
  for(i = 0; i < INPUTFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void inputFilter_put(inputFilter* f, int8_t input) {
  f->history[f->last_index++] = input;
  if(f->last_index == INPUTFILTER_TAP_NUM)
    f->last_index = 0;
}

int16_t inputFilter_get(inputFilter* f) {
  long long acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < INPUTFILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : INPUTFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[i];
  };
  return acc >> 8;
}
