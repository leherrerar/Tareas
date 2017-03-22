#include <iostream>
#include <armadillo>
#include <stdio.h>
#include <time.h>   //time


void solvesystem(const int & size);

int main()
{
  clock_t start, end;  //time
  double cpu_time_used;   //time
  start = clock();  //time
  srand48(0);
  const int N = 512;
  int step;
  for ( step = 1; step < N; ++step){
    solvesystem(step);
 end = clock();  //time
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  //time
  printf ("%g  \t %d \n", cpu_time_used, step); //time
    }
}

void solvesystem(const int & size) 
{
  // WARNING: ONLY ACTIVATE ONE SOLVE MODE AT A TIME

  arma::mat A (size,size);
  arma::vec b (size ,1);
  
for(int i =0; i <size  ;i++){
	b(i,0)=drand48();
	 for (int j =0 ; j<size; j++){
		A(i,j)= drand48();
	}
 }


  // Default solve 
  //arma::vec x = arma::solve(A, b); // normal solve

  // LU
  arma::mat P,L,U;
  arma::lu(L, U, P, A);
  arma::vec x = solve(trimatu(U), solve(trimatl(L), P*b) );

  // QR
  

  // Printing
 // std::cout << x << std::endl;
}
