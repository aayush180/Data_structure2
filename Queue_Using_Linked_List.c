#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*front=NULL,*rear=NULL;

void Enqueue(int x){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Queue is Full\n");
    }
    else{
        t->data=x;
        t->next=NULL;

        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int Dequeue(){
    int x=-1;
    struct Node*t;

    if(front==NULL){
        printf("Queue is Empty\n");
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

void Display(){
    struct Node*p=front;
     while(p){
         printf("%d ",p->data);
         p=p->next;
        }
}

int main(){
    
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    printf("%d\n",Dequeue());
    
   
    Display();


}