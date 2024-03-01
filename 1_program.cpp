#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 16

static long num_steps = 1000000000;
double step;

int main(int argv, char* argc[])
{
	double time;
	time = omp_get_wtime();
	omp_set_num_threads(NUM_THREADS);
	double A[100][100]; int n;
	int i;
	int j;
	double s;
	double s1;
	n = 100;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			A[i - 1][j - 1] = 0.1e1 / (double)(i + j);
#pragma omp parallel sections
	{
#pragma omp section
		{
			s = 0.0e0;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					s = s + A[i - 1][j - 1];
			printf("%f\n", s);
			printf("Time: %lf\n", omp_get_wtime() - time);
		}
#pragma omp section
		{
			s1 = 0.0e0;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					s1 = s1 + A[i - 1][j - 1] * A[i - 1][j - 1];
			printf("%f\n", s1);
		}
	}
	printf("Time: %lf\n", omp_get_wtime() - time);

}
