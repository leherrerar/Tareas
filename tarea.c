/* mpi-V3.c */

#include "mpi.h"
#include <stdio.h>

/* Problem parameters */
double f(double x) {
  return x*x;
}

int i, v[12]={1,1,1,1,1,1,1,1,1,1,1,1};
int N=12;

int main(int argc, char **argv) 
{
  /* MPI Variables */
  int dest, noProcesses, processId, src, tag;
  MPI_Status status;

  /* problem variables */
  int i; 
  double suma, at, heigth, width, total, range, lower;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);
  MPI_Comm_rank(MPI_COMM_WORLD, &processId);

  /* Adjust problem size for sub-process */
  range = N / noProcesses;
  

  /* Calculate area for subproblem */ 
  suma = 0.0;
  for (i=range*processId; i <range*processId+range ; ++i) {
   
    suma = suma + v[i];
  }

  /* Collect info and print results */
  tag = 0;
  if (0 == processId) { /* Master */
    total = suma; 
    for (src = 1; src < noProcesses; ++src) {
      MPI_Recv(&suma, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, &status);
      total += suma;
    }
    fprintf(stderr, "The area from  to is : %25.16e\n",  total);
  }
  else { /* slaves only send */
    dest = 0; 
    MPI_Send(&suma, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }

  /* finish */
  MPI_Finalize();

  return 0;
}
