#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;

//typedef float real;

double a=1.0;
double b=1.0;
double c=0.1;
double x;


float log1p(float x){
  if (x+1==1){
    return x;
  }
  else {
    return (x*log(1+x))/((1+x)-1);
  } 

}




int main(){
  for(int n=1;n<=30;n=n+1){
    float A=2.055476;
    float B=2.055476;
    float C=2.055476;
    float x=0.235895415845524155144656586;
    A=A*pow(1+x,n);
    B=B*exp(n*log(1+x));
    C=C*exp(n*log1p(x));
    printf("%i \t %5.10e\t %5.10e \t %5.10e \n", n,A,B,C );
  }
// printf("%5.10e \n",  log1p(0.000000000000001));
  
  // pintf( "%i \t %5.16e \t %5.16e \t %5.16e \n",n,  solucion1(a,b,c), solucion2(a,b,c),solucion3(a,b,c));
	

}
