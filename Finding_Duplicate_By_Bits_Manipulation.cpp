#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    char A[]={"finding"};
    long int h=0,x=0;
    int i;
    for (i=0;A[i]!='\0';i++)
    {
        x=(x<<A[i])-97; 
        x=1;
    }
     if(x && h >0){
            printf("%c ",A[i]);
        }
        else{
            h=x||h;
        }
    

}