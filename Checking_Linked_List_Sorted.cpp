#include<stdio.h>
#include<stdlib.H>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n){
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=0;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

bool IsSorted(struct Node *p){
    int x=INT_MIN;
    
    while(p != NULL)
    {
        if(p->data < x){
            return false;
        }
        else{
            x=p->data;
            p=p->next;
        }
    }
    return true;  
}

int main(){
    int A[]={3,5,7,9,11};
    Create(A,5);
    if(IsSorted(first)){
        printf("IS Sorted ");
    }
    else{
        printf("Not Sorted ");
    }
}