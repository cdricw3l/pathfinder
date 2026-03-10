#ifndef COST_AND_PERF_H
#define COST_AND_PERF_H

#ifndef X
    #define X 3
#endif

#ifndef Y
    #define Y 4
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc/malloc.h>

void    memory_2D_cost(void);
void	memory_1D_cost(void);
time_t	perf_1D_cost(void);

#endif