#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip> 
using namespace std;

//typedef float real;




double matris1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
double matris2[3][3]={{1,2,3},{4,5,6},{7,8,9}};



int main(){

  double  matris3[3][3];
  for (int i=0 ; i<=2 ;i++){
    for (int j=0 ; j<=2 ;j++){
      double suma=0;
      for(int k=0 ; k<=2; k++){
	suma=suma+matris1[i][k]*matris2[k][j];	
	}
	matris3[i][j]=suma;	 
      printf("| %f |",matris3[i][j]);
    }
    printf("\n");
  }
  

 
// printf("%5.10e \n",  log1p(0.000000000000001));
  
  // pintf( "%i \t %5.16e \t %5.16e \t %5.16e \n",n,  solucion1(a,b,c), solucion2(a,b,c),solucion3(a,b,c));
	

}
