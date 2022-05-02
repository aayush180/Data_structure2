#include<iostream>
#include<stdio.h>
using namespace std;
//                                                      i=0  1  2  3  4  5   6
// Reverse String By Using Second Character Array   ex->A[p][y][t][h][o][n][\0]
//                                                  ex->B[n][o][h][t][y][p][\0] 
//                                                      j=0  1  2  3  4  5   6 
int ReveStr(){
    char A[]={"Python"};
    char B[7];
    int i,j;

    for( i=0;A[i]!='\0';i++){
    }
    i=i-1;

    for(int j=0;i>=0;i--,j++){
       B[j]=A[i];
    }
    B[j]='\0';
    printf("%s ",B);
    
}

int main(){
    printf("%s ",ReveStr());
}