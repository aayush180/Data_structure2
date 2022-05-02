


struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct queue*q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void Enqueue(struct queue*q,struct Node *x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node *Dequeue(struct queue*q){
    struct Node*x=NULL;

    if(q->rear==q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int IsEmptyqueue(struct queue*q)
{
    return q->rear==q->front;
}