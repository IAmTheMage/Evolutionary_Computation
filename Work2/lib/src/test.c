#include "../include/core.h"
#include "stdio.h"

int main(int argc, char** argv) {
    printf("Digite o numero de individuos\n");
    int individuals_number = 0, selected_number = 0;
    scanf("%d", &individuals_number);
    printf("Digite o numero de selecionados\n");
    scanf("%d", &selected_number);
    srand(time(0));
    double* fitness = (double*)(calloc(individuals_number, sizeof(double)));
    for(int i = 0; i < individuals_number; i++) {
        fitness[i] = random_uniform(0.0, 10.0);
    }
    int* selected = (int*)(calloc(selected_number, sizeof(int)));
    selected = roulette(fitness, individuals_number, individuals_number, selected_number);
    for(int i = 0; i < selected_number; i++) {
        printf("%d ", selected[i]);
    }
    return 0;
}