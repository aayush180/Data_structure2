#include<iostream>
#include<stdio.h>
using namespace std;

struct matrix{
    int A[10];
    int n;
};

void set(struct matrix *m,int i,int j,int x){
     if(i == j){
        m->A[i-1]=x;
     }
}

int Get(struct matrix m,int i,int j){
    if(i == j){
        return m.A[i-1];
    }
    else{
        return 0;
    }
}

void Display(struct matrix m){
     int i,j;

     for(i=0;i<m.n;i++){
         for(j=0;j<m.n;j++){
             if(i==j){
               printf("%d ",m.A[i]);
             }
             else{
                 printf("0 ");
             }
            }
         printf("\n");
        }
}



int main(){
    struct matrix m;
    m.n=4;

    set(&m,1,1,2);set(&m,2,2,3);set(&m,3,3,5);set(&m,4,4,7);
    Get(m,2,2);
    Display(m);
}