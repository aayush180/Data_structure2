#include<iostream>
#include<stdio.h>
using namespace std;

int Element(int *A,int n){
   int lastduplicate=0;
   
   for(int i=0;i<n;i++){
      if(A[i]== A[i+1] && A[i] !=lastduplicate){
         printf("Element is %d ",A[i]);
         lastduplicate=A[i];
      }
   }
}

int main(){
     int A []={5,1,4,1,1};
     int n=5;
     
     printf("%d ",Element(A,n));
}