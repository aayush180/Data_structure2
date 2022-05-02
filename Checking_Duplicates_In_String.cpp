#include<iostream>
#include<stdio.h>
using namespace std;


int main(){  
   char A[]={"NASCARS"};
    for(int i=0;A[i]!='\0';i++)
    {
        int count=1;
        if(A[i]!=-1)
        {
        for(int j=i+1;A[j]!='\0';j++)
        {
           if(A[i]==A[j]){
               count++;
               A[j]=-1;
           }
        }
        if(count > 1)
        {
            printf("%c %d\n",A[i],count);
        }
        }
    }
}