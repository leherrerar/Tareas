#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main(){
Matrix3d A;
   A << -2, 2, -3, 2, 1, -6, -1, -2, 0;

cout << A.eigenvalues() << endl;

}
