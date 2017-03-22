#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   MatrixXd A(100,100);
   VectorXd b(100);
   const int size=100 ;
   for(int i =0; i <size  ;i++){
	b(i)=(1.0/(1.0+i));
	 for (int j =0 ; j<size; j++){
		A(i,j)= (1.0/(i+j+1.0));
	}
    }
    cout << "la solucion es:\n" << A.partialPivLu().solve(b) << endl;
  // cout << "la matriz A:\n" << A << endl;
  // cout << "el vector b es:\n" << b << endl;
  cout << A.partialPivLu().solve(b) << endl;
  ArrayXd a = A.partialPivLu().solve(b).array();
  cout << (a +1).sqrt() << endl;
}
