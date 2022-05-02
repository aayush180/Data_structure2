#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

void CreateNode(int A[],int n)
{
    struct Node*t,*last;

    head =(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void Display(struct Node*h)
{
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h != head);
}
//Recersive Function For Displaying Circular Linked List
void RDisplay(struct Node*h){
   static int flag=0;
    if(h != head || flag==0){
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
}

int main(){
    int A[]={1,3,5,7,9};
    CreateNode(A,5);
    Display(head);
}