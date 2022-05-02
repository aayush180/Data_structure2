#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Count(struct Node *p){
    int count=0;
    while(p != NULL){
        count++; 
        p=p->next;
    }
    return count;
}

// Recersive Function For Counting Nodes 
int Rcount(struct Node *p){
    if(p != NULL){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}


int main(){
    int A[]={3,5,7,9,11,13};
    Create(A,6);
    printf("%d ",Count(first));
}