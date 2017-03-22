#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3d A;
   A << -2, 2, -3, 2, 1, -6, -1, -2, 0;
   Matrix3d B;
   B << -2, 3, -3, 6, 1, -9, -1, -2, 0;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the matrix B:\n" << B << endl;
   EigenSolver<Matrix3d> eigensolverB(B);
   EigenSolver<Matrix3d> eigensolverA(A);
   //SelfAdjointEigenSolver<Matrix3d> eigensolverB(B);
   //SelfAdjointEigenSolver<Matrix3d> eigensolverA(A);
  // cout << SelfAdjointEigenSolver<Matrix3d> eigensolver(A) << endl;
  // if (eigensolver.info() != Success) abort();
   cout << "The eigenvalues of A are:\n" << eigensolverA.eigenvalues() << endl;
   cout << "Here's a matrix whose columns are eigenvectors of A \n"
    << "corresponding to these eigenvalues:\n" 
    << eigensolverA.eigenvectors() << endl;

cout << "The eigenvalues of B are:\n" << eigensolverB.eigenvalues() << endl;
   cout << "Here's a matrix whose columns are eigenvectors of B \n"
    << "corresponding to these eigenvalues:\n" 
    << eigensolverB.eigenvectors() << endl;
cout << "The firts eigenvalues of B are:\n" << eigensolverB.eigenvalues().row(0) << endl;
cout << 2*eigensolverB.eigenvalues().row(0).real() << endl ;

cout << "Here's the first eigenvectors of A \n"
    << eigensolverA.eigenvectors().col(0).real() << endl;


}



