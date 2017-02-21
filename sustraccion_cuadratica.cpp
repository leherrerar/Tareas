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


double solucion1(double a,double b,double c){
	double x = (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
	return x;
}

double solucion2(double a,double b,double c){
	double x = (-b - sqrt(pow(b,2)-4*a*c))/(2*a);
	return x;
}

double solucion3(double a,double b,double c){
	double x = c/(solucion1(a,b,c));
	return x;
}







int main(){
	for (int n=0 ; n<=50 ;n=n+1){
		c=exp(-n);
		printf( "%i \t %5.16e \t %5.16e \t %5.16e \n",n,  solucion1(a,b,c), solucion2(a,b,c),solucion3(a,b,c));
	}

}
/*  for (int i=1 ;i<=10000;i=i+1){
    //printf("%i \t  %5.10e \t %5.10e \t %5.10e \n",i, s1(i),s2(i),s3(i)); 
    double result=s3(i);
    double errors1=fabs((result-s1(i)))/(result);
    double errors2=fabs((result-s2(i)))/(result);
     printf("%i \t  %5.15e \t %5.15e \n", i ,errors1 ,errors2); 
    
    
     }
  
*/




