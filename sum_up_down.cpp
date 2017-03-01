#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;
const int N = 200000;


float sumaup(int N){
   float sum=0;	
   for (int n=1; n<=N;n++){
	sum=sum+(1.0/n);
    }
   return sum;
}



float sumadown( int N){
	float sum=0;	
	for (int n=N; n>=1;n--){
		sum=sum+(1.0/n);
	}
	return sum;
}



int main(){
	for (int i =1; i<=100; i++){
	float error = fabs(sumaup(i)-sumadown(i));	
	printf("%i \t %5.10e  \n", i,error );
  }

}
