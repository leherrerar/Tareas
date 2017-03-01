#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;





double serie(const double x,const double N){
  double sum=x;
  double term=x;

  for (int n=1; n<= N ;n=n+1){  
    term=(-1)*x*x/((2*n+1)*(2*n))*term;
    sum=sum+term;
  }
  return sum;
}    


int main(){
  double x=0;
  double dx =0.05;
  const int Nmax=5;
  //  cout<< serie(pi,100)<<endl;
  for (int i=1 ;i<=80;i=i+1){
    x=x+dx;
    double a=sin(x);
    double b=serie(x,Nmax);
    double error=abs((a-b)/a);

    cout << x<< " " << error << endl;
    cerr << x<< " " << a << endl;   
  }

  

}
