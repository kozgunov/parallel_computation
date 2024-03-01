#include <iostream>
#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 16

static long num_steps = 1000000000;
double step;

void main()
{
    int i;
    double x, pi, time, sum = 0.0;
    time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);
    
    step = 1.0 / (double)num_steps;

#pragma omp parallel for private(x) reduction(+:sum)
    
    for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
    pi = step * sum;
    printf("Time: %lf\n", omp_get_wtime() - time);
    printf("Result: %1.10f\n", pi);

}
