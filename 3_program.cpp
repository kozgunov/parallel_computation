#include <stdio.h>
#include <math.h>
#include "omp.h"

int main(int argc, char* argv[])
{
    double time;
    time = omp_get_wtime();
    double x;
    double eps;
    double i;
    int n;
    double s;
    double s1;
    double P12;
    double P6;
    double PP;
    x = 0.39e0;
    eps = 0.1e-5;
    n = 14;
    printf("Time: %lf\n", omp_get_wtime() - time);

#pragma omp parallel sections 
    {
#pragma omp section
        {
            s = 0.1e1;
            for (i = 0.10e1; i <= (double)n / 0.2e1; i
                += 0.10e1)
                s = (double)(s * (0.1e1 - 0.4e1 * x * x *
                    pow(0.3141592654e1, -0.2e1) * pow(0.2e1 * i -
                        0.1e1, -0.2e1)));
            P6 = s;
            printf("Time: %lf\n", omp_get_wtime() - time);
        }
#pragma omp section
        {
            s1 = 0.1e1;
            for (i = (double)n / 0.2e1; i <= (double)
                n; i += 0.10e1)
                s1 = (double)(s1 * (0.1e1 - 0.4e1 * x * x *
                    pow(0.3141592654e1, -0.2e1) * pow(0.2e1 * i -
                        0.1e1, -0.2e1)));
            P12 = s1;
            printf("Time: %lf\n", omp_get_wtime() - time);
        }
    }
    PP = s * s1;
    printf("%f\n", PP);

}
