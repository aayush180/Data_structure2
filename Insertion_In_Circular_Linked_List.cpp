#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head;

void CreateNode(int A[],int n)
{
    struct Node *t,*last;
    
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data =A[0];
    head->next =head;
    last=head;

    for(int i=1; i<n; i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data =A[i];
        t->next =last->next;
        last->next =t;
        last=t;
    }
}
int Length(struct Node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void Insert(struct Node *p,int index,int data)
{
    struct Node *t;
   if(index < 0 || index > Length(p))
   {
       return;
   }
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=data;

        if(head==NULL){
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next != head)
            {
                p->next=t;
                t->next=head;
                head=t;
            }
        }
    }
    else{
         for(int i=0;i<index-1;i++)
               {
                    p=p->next;
                }
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data =data;
                t->next=p->next;
                p->next=t;
        }
}

void Display(struct Node *p)
{
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!= head);
}

int main(){
    int A[]={1,3,5,7,9};
    CreateNode(A,5);
    
    Insert(head,2,10);
    Display(head);

}