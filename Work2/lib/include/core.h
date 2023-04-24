#ifndef CORE_H
#define CORE_H

#define DEFAULT_POPULATION 1000
#define DEFAULT_DIMENSION 2
#define EXEC_NUMBER 51

#include "stdlib.h"
#include "time.h"

typedef struct {
    double lower_limit;
    double upper_limit;
} Config;

typedef struct {
    double* gens;
    double fitness;
} Individual;

typedef struct {
    Individual* individuals;
    int size;
} Population;

double random_uniform(double a, double b);
int* roulette(double* fitness, int individuals_number, int selectedNumber);
Individual* fittest_half(Population* pop, int maximum);

#endif