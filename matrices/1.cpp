#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3d A;
   A << 4.0 ,-2.0 , 1.0,
        3.0 , 6.0 , -4.0,
        2.0 , 1.0 , 8 ;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "la inversa de A es:\n" << A.inverse() << endl;
   cout << "El Determinarnte de A:\n" << A.determinant() << endl;
   Matrix3d I = A.inverse() ;
   double D=A.determinant();
   cout << " I*A:\n" << I*A << endl;
   cout << " A*I:\n" << A*I << endl;
   cout << "la adjunta de A es:\n" << D*I.transpose() << endl;
}


/*
   VectorXf b = VectorXf::Random(3);
   cout << "Here is the right hand side b:\n" << b << endl;
   cout << "The least-squares solution is:\n"
        << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b) << endl;

*/
