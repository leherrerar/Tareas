#include<iostream>
#include<cstdio>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}



double serie(const double x, const double eps){
  double sum=x;
  double term=x;
  int n=1;
	

  while (abs(term/sum) > eps){  
    term=pow(-1,n-1)*pow(x,2*n-1)/factorial(2*n-1);
    sum=sum+term;
    n=n+1;
  }
  return sum;
}    


int main(){
  double x=0;
  double dx =0.05;
  double eps = pow(10,-8);
  double z;
  double a;
  double b;
  double error;
  //  cout<< serie(pi,100)<<endl;
  for (int i=1 ;i<=200;i=i+1){
    x=x+dx;
    if (x>15){
       z=trunc(x/(2*M_PI));
       a=sin(x);
       b=serie(x-2*M_PI*z,eps);
       error=abs((a-b)/a);
	}
    else{
       a=sin(x);
       b=serie(x,eps);
       error=abs((a-b)/a);
        }  
    cout <<i<<" "<< x<< " "<<b <<" "<< error << endl;
    cerr << x<< " " << a << endl; 
   //  cout << eps << endl;  
  }

  

}
