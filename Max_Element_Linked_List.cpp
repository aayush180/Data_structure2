#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void Create(int A[],int n)
{
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int MaxEle(struct Node *p)
{
    int max=INT32_MIN;
    while(p != NULL){
        if(p->data > max){
            max=p->data;
        }
        p=p->next;
    }
    return(max);
}

//Recersive Function For Linked List
int Rmax(struct Node *p){
    int max=0;
    if(p == NULL){
        return(0);
    }
    max=Rmax(p->next);
    if(max > p->data){
        return max;
    }
    else{
        return p->data;
    }
}


int main(){

    int A[]={5,7,3,12,2};
    Create(A,5);
    printf("%d ",Rmax(first));
}