#include<stdio.h>
#include<stdlib.h>

void Insert(int A[],int n){
    int temp,i=n;
    temp=A[i];

    while(i>1 && temp >A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int Delete(int A[],int n){
    int x,i,j,temp;
    int val=A[1];
    x=A[n];
    A[1]=A[n];
    i=1;j=2*i;
    A[n]=val;

    while(j < n-1){
        if(A[j+1] > A[j]){
            j=j+1;
        }
        if(A[i] < A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
    }
    return val;
}

int main(){
    int i;
    int A[]={0,10,20,30,25,5,40,35};

    for( i=2;i<=7;i++){
        Insert(A,i);
    }
    printf("After Insert \n");
       for(i=1;i<=7;i++){
        printf("%d ",A[i]);
    }
    
     
    for(int i=7;i>=1;i--){
        Delete(A,i);
    }
    printf("\nAfter Deletion \n");
    for(i=1;i<=7;i++){
        printf("%d ",A[i]);
    }

}