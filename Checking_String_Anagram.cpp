#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
  char A[]={"decimal"};
  char B[]={"medical"};
  int i,h[26];

  for(i=0;A[i]!='\0';i++){
      h[A[i]-97] +=1;
  }
  for(i=0;B[i]!='\0';i++){
      h[B[i]-97] -=1;
  
  if((h[A[i]-97])<0){
      printf("Not Anagram");
  }
  }
  if(B[i]!='\0'){
      printf("Not Anagram");
  }


}