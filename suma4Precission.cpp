#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;





double serie(const double x, const double eps){
  double sum=x;
  double term=x;
  int n=1;
	

  while (abs(term/sum) > eps){  
    term=(-1)*x*x/((2*n+1)*(2*n))*term;
    sum=sum+term;
    n=n+1;
  }
  return sum;
}    


int main(){
  double x=0;
  double dx =0.05;
  double eps = pow(10,-20);
  //  cout<< serie(pi,100)<<endl;
  for (int i=1 ;i<=500;i=i+1){
    x=x+dx;
    double a=sin(x);
    double b=serie(x,eps);
    double error=abs((a-b)/a);

    cout <<i<<" "<< x<< " "<<b <<" "<< error << endl;
    cerr << x<< " " << a << endl; 
   //  cout << eps << endl;  
  }

  

}
