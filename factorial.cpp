#include<iostream>
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}


int main(){
	cout << factorial(1) << factorial(2) << factorial(3) << factorial(4) << factorial(5) << endl;



}
