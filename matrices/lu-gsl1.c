// gcc -lgsl -lgslcblas lu-gsl.c

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>

#include <time.h>   //time
     


void init(double Adata[], double bdata[], const int n);
void solve(const int n);

int main ()
{
  clock_t start, end;  //time
  double cpu_time_used;   //time
  start = clock();  //time
  srand48(0);

  const int N = 512;


  int step;
  for (step = 1; step < N; ++step) {
    solve(step); //
  end = clock();  //time
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  //time
  printf ("%g  \t %d \n", cpu_time_used, step); //time

  }

  
 
  return 0;
}


void init(double Adata[], double bdata[], const int n)
{
  int ii, jj;
  for (ii = 0; ii < n; ++ii) {
    bdata[ii] = drand48();      
    for (jj = 0; jj < n; ++jj) {
      Adata[ii*n + jj] = drand48();      
    }
  }
}

void solve(const int n)
{
  double *Adata, *bdata;
  Adata = malloc(n*n*sizeof(double));
  bdata = malloc(n*sizeof(double));

  init(Adata, bdata, n);

  gsl_matrix_view m = gsl_matrix_view_array (Adata, n, n);
  gsl_vector_view b = gsl_vector_view_array (bdata, n);
 // printf ("m = \n"); //
 // gsl_matrix_fprintf (stdout, m, "%g"); //

  gsl_vector *x = gsl_vector_alloc (n);
  int s;
  gsl_permutation * p = gsl_permutation_alloc (n);

  // lu
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);

  // printing
  //printf ("x = \n");
  //gsl_vector_fprintf (stdout, x, "%g");

  // resource release
  gsl_permutation_free (p);
  gsl_vector_free (x);

  free(Adata);
  free(bdata);

}
