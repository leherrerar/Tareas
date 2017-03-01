#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;
const int N = 5000;


double sumaup(int N){
   double sum=0;	
   for (int n=1; n<=N;n++){
	sum=sum+(1.0/n);
    }
   return sum;
}



double sumadown( int N){
	double sum=0;	
	for (int n=N; n>=1;n--){
		sum=sum+(1.0/n);
	}
	return sum;
}



int main(){
	double gamma = sumadown(N)- log(N+(1.0/2.0));	
	printf(" %2.16e  \n", gamma );
  

}
