#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;
const int N = 5000;


double lebesgue(int N){
   double sum=0;
   double a=1.0/(2*N+1);		
   for (int n=N; n>=1;n--){
	sum=sum+((1.0/n)*tan((M_PI*n)/(2.0*N+1)));
    }
   return a+((2.0*sum)/M_PI);
}

bool ineq(double p,int n){
	if (0 <= 4/pow(M_PI,2)*log(2*n+1)+1-p & 4/pow(M_PI,2)*log(2*n+1)+1-p <= 0.0106 ){
	return true; 
	}
	else {
	return false; 
	}
}


int main(){
	for (int i=1 ; i<=100 ; i++){	
	printf("%i \t %3.16e  \t %s \n",i, lebesgue(i) , ineq(lebesgue(i),i) ? "true":"false" );
  
	}

}
