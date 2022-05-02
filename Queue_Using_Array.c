#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue* q,int size){
    q->size = size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

//Insertion In The Queue
void Enqueue(struct Queue* q,int x){
    if(q->rear==q->size-1){
        printf("Queue Is Full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }

}

//Deletion In Queue
int Dequeue(struct Queue* q){
    int x=-1;

    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main(){
    struct Queue q;
    Create(&q,5);

    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Enqueue(&q,50);
    

    Display(q);

    printf("%d\n",Dequeue(&q));

    Display(q);


}