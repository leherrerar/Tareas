#include <iostream>
#include <Eigen/Dense>
#include <stdio.h>
#include <time.h>   //time

void solvesystem(const int  size);

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

void solvesystem(const int  size)
{
 // Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
 //Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);
 //  int X = size;
  Eigen::MatrixXd A(size, size);
// std::cout << "el tamano de M es:\n" << A.rows() << "x" << A.cols() << std::endl;
 // A << drand48();
  Eigen::MatrixXd b(size, 1);
//std::cout << "el tamano de b es:\n" << b.rows() << "x" << b.cols() << std::endl;
 // b << drand48();

for(int i =0; i <size  ;i++){
	b(i,0)=drand48();
	 for (int j =0 ; j<size; j++){
		A(i,j)= drand48();
	}
 }

//std::cout << "La Matris A es:\n" << A << std::endl;
//std::cout << "el vector b es:\n" << b << std::endl;

 Eigen::MatrixXd x = A.fullPivLu().solve(b);
 double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm
//std::cout << "La Matris X es:\n" << x << std::endl;
//std::cout << "The relative error is:\n" << relative_error << std::endl;
}
