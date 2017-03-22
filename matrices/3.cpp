#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3d A;
   A << 4, -2, 1, 3, 6, -4, 2, 1, 8;
   Vector3d b1;
   b1 << 12 , -25 ,32 ;
   Vector3d b2;
   b2 << 4 , -10 ,22 ;
   Vector3d b3;
   b3 << 20 , -30 ,40 ;

   cout << "la solucion es:\n" << A.partialPivLu().solve(b1) << endl;
   cout << "la solucion es:\n" << A.partialPivLu().solve(b2) << endl;
   cout << "la solucion es:\n" << A.partialPivLu().solve(b3) << endl;






}
