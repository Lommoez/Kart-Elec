#if !defined(FILTER_H)
#define FILTER_H

#include <stdint.h>

#ifndef FILTER_SMOOTHING_ALPHA
#define FILTER_SMOOTHING_ALPHA 0.4f
#endif

typedef uint16_t adc_sample_t;

typedef struct Filter {
    int size;
    int window_size;
    int last_id;
    float trimed_mean;
    float trimed_filtered_mean;
    uint16_t* samples;
    uint16_t* samples_sorted;
} Filter;

void Filter_init(Filter *filter, int size, int window_size, adc_sample_t *array1, adc_sample_t *array2, adc_sample_t initial_value);
uint16_t Filter_push(Filter *filter, adc_sample_t value);

uint16_t Filter_getMedian(Filter *filter);
float Filter_getTrimedMean(Filter *filter);
float Filter_getTrimedFilteredMean(Filter *filter);

#endif //FILTER_H
