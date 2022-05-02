

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void StackCreate(struct Stack *st,int size){
    st->size = size;
    st->top =-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node *));
}

void Pushstack(struct Stack *st,struct Node *x){
    if(st->top==st->size-1){
        printf("Stack is full\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *Popstack(struct Stack *st){
    struct Node *x;
    if(st->top==-1){
        printf("Stack is Empty\n");
    }
    else{
        x=st->S[st->top--];
    }
    return x;
}

int isFullStack(struct Stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmptyStack(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}