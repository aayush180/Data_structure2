#include<iostream>
#include<stdio.h>
using namespace std;

bool CheckPalindrome(){
    char A[]={"NITIN"};
    int i,j;

    for(j=0;A[j]!='\0';j++){
    }
    j=j-1;

    for(i=0;i<j;i++,j--){
        if(A[i]==A[j]){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    if(CheckPalindrome()){
        printf("Is Palindrome");
    }
    else{
        printf("Is not Palindrome");
    }
}