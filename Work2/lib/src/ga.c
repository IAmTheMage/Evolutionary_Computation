#include "../include/ga.h"

Config config;

void create_configuration(double _lower_limit, double _upper_limit) {
    config.lower_limit = _lower_limit;
    config.upper_limit = _upper_limit;
}

Individual create_individuals(int number_of_gens) {
    Individual individual;
    individual.gens = (double*)(calloc(number_of_gens, sizeof(double)));
    for(int i = 0; i < number_of_gens; i++) {
        individual.gens[i] = random_uniform(config.lower_limit, config.upper_limit);
    }
    return individual;
}

Population create_population(int number_of_individuals, int number_of_gens, int _ll, int _ul) {
    Population pop;
    pop.individuals = (Individual*)(calloc(number_of_individuals, sizeof(Individual)));
    for(int i = 0; i < number_of_individuals; i++) {
        pop.individuals[i] = create_individuals(number_of_gens);
    }
    pop.size = number_of_individuals;
}
