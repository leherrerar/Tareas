#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;





double serie(const double x, const double eps){
  double sum=1;
  double term=1;
  int n=1;
	

  while (abs(term/sum) > eps){  
    term=(-1)*x/n*term;
    sum=sum+term;
    n=n+1;
  }
  return sum;
}    


int main(){
  double x=0;
  double dx =0.05;
  double eps = pow(10,-8);
  //  cout<< serie(pi,100)<<endl;
  for (int i=1 ;i<=300;i=i+1){
    x=x+dx;
    double a=exp(-x);
    double b=serie(x,eps);
    double error=abs((a-b)/a);

    cout <<i<<" "<< x<< " "<<b <<" "<< error << endl;
    cerr << x<< " " << a << endl; 
   //  cout << eps << endl;  
  }

  

}
