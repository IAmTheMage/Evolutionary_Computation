#define DEFAULT_POPULATION 1000
#define DEFAULT_DIMENSION 2
#define EXEC_NUMBER 51

#include "stdlib.h"
#include "time.h"

double random_uniform(double a, double b) {
    double random = a + (b-a) * ((double)rand() / RAND_MAX);
    return random;
}


int* roulette(double* fitness, int size, int individuals_number, int selectedNumber) {
    double sum = 0.f;
    int* selected = (int*)calloc(selectedNumber, sizeof(int));
    for(int i = 0; i < individuals_number; i++) {
        sum += fitness[i];
    }
    for(int i = 0; i < selectedNumber; i++) {
        double random_number = random_uniform(0, sum);
        double acummulated = 0;
        for(int j = 0; j < individuals_number; j++) {
            acummulated += fitness[j];
            if(acummulated > random_number) {
                selected[i] = j;
                break;
            }
        }
    }
    return selected;
}