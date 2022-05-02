#include<iostream>
#include<stdio.h>
using namespace std;

int CountVowels(){
    char A[]={"How Are You"};
    int i;
    int count=0;

    for( i=0;A[i] != '\0';i++){
        if(A[i] == 'a' || A[i] == 'e'|| A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U' ){
         count++;
        }
    }
    return count;
}
// For Counting The Characters In The String
int CountConsonent(){
    char B[]={"How Are You"};
    int i;
    int Ccount=0;

    for(i=0;B[i] != '\0';i++){
        if((B[i] >=65 && B[i] <=90) || (B[i] >=97 && B[i] <=122)){
            Ccount++;
        }
    }
    return Ccount;
}

// For Counting Words And Spaces In The String
int CountWordsSpaces(){

    char C[]={"How Are You Today"};
    int i;
    int scount=0;
    int wcount=0;

    for(int i=0;C[i] != '\0';i++){

        if(C[i] == ' ' && C[i-1] != ' '){
            scount++;
            wcount++;
        }
    }
    printf(" Space Are %d ",scount);
    printf("\n");
    printf(" Words Are %d ",wcount+1);
}

int main(){
    cout<<CountWordsSpaces();

}