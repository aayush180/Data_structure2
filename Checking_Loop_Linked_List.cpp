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

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

bool IsLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do{
    p=p->next;
    q=q->next;
    q=q?q->next:q;
    }while(p != NULL && q != NULL && p!=q);
    if(p == q){
        return true;
    }
    else{
        return false;
    }


}

int main()
{
    struct Node*t1,*t2;
    int A[]={1,3,5,7,9};
    Create(A,5);
   
 
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    if(IsLoop(first)){
        printf("IS Looped ");
    }
    else{
        printf("Not Looped ");
    }
}