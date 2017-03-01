#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;





float s1(const int N){
  float sum=0;
  for (int n=1; n<=2*N ;n=n+1){  
    sum=sum+pow(-1,n)*n/(n+1.0);
  }
  return sum;
}

float s2(const int N){
  float sum1=0;
  float sum2=0;
  for (int n=1; n<=N ;n=n+1){  
    sum1=sum1+((2.0*n)/(2.0*n+1));
    sum2=sum2+((2*n-1)/(2.0*n));
  }
  
  
  return sum1-sum2;
}

float s3(const int N){
  float sum=0;
  for (int n=1; n<=N ;n=n+1){  
    sum=sum+(1.0/(2*n*(2*n+1.)));
  }
  return sum;
}    

  
/*
double g(const int N){
  double sum=0;
  for (int n=N; n >= 1 ; n--){  
    sum=sum+(1.0/(n*n));
  }
  return sum;
} 
*/

int main(){
  for (int i=1 ;i<=10000;i=i+1){
    //printf("%i \t  %5.10e \t %5.10e \t %5.10e \n",i, s1(i),s2(i),s3(i)); 
    double result=s3(i);
    double errors1=fabs((result-s1(i)))/(result);
    double errors2=fabs((result-s2(i)))/(result);
     printf("%i \t  %5.15e \t %5.15e \n", i ,errors1 ,errors2); 
    
    
     }
  

}
