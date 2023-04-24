#include "core.h"
#include "stdlib.h"

#ifndef GA_H
#define GA_H



void create_configuration(double _lower_limit, double _upper_limit);

Individual create_individuals(int number_of_gens);

Population create_population(int number_of_individuals, int number_of_gens, int _ll, int _ul);

#endif