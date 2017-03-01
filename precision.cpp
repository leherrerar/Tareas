#include<iostream>
#include<cstdio>
using namespace std;


const int N=50;

    
int main(){
  float eps=1;
  float one;
  for (int i=1; i<N ;i=i+1){
    eps=eps/2.0;
    one=1.0 + eps;
    cout<<i<<" " <<one<<" "<< eps<<endl;
  }



}
