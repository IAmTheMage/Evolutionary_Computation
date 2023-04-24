#include "../include/core.h"

double random_uniform(double a, double b) {
    double random = a + (b-a) * ((double)rand() / RAND_MAX);
    return random;
}


int* roulette(double* fitness, int individuals_number, int selectedNumber) {
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

int compareMinimum(const void * a, const void * b) {
    Individual* individual1 = (Individual*)a;
    Individual* individual2 = (Individual*)b;
    if(individual1->fitness > individual2->fitness) return -1;
    return 1;
}

int compareMaximum(const void * a, const void * b) {
    Individual* individual1 = (Individual*)a;
    Individual* individual2 = (Individual*)b;
    if(individual1->fitness > individual2->fitness) return 1;
    return -1;
}

Individual* fittest_half(Population* pop, int maximum) {
    if(maximum < 0) {
        qsort(pop->individuals, pop->size, sizeof(Individual), compareMinimum);
        int __sizet = (int)(pop->size / 2);
        Individual* sorted_individuals = (Individual*)(calloc(__sizet, sizeof(Individual)));
        for(int i = 0; i < __sizet; i++) {
            sorted_individuals[i] = pop->individuals[i];
        }
        return sorted_individuals;
    }
    qsort(pop->individuals, pop->size, sizeof(Individual), compareMaximum);
    int __sizet = (int)(pop->size / 2);
    Individual* sorted_individuals = (Individual*)(calloc(__sizet, sizeof(Individual)));
    for(int i = 0; i < __sizet; i++) {
        sorted_individuals[i] = pop->individuals[i];
    }
    return sorted_individuals;
    
}