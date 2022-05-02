#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void CreateStack(struct stack *st){
    printf("Enter The Size : ");
    scanf("%d", &st->size);
    st->s=(int *)malloc(st->size*sizeof(int));
    st->top=-1;
}

void DisplaysStack(struct stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x){
    if(st->top == st->size-1){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st){
    int x=-1;
    if(st->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x=st->s[st->top--];
    }
    return x;
}

int peek(struct stack st,int pos){
    int x=-1;
    if(st.top-pos+1 < 0){
        printf("Invalid Stack Position\n");
    }
    else{
        x=st.s[st.top-pos+1];
    }
    return x;
}

int IsEmpty(struct stack st){
    if(st.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(struct stack st){
    if(st.top == st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int StackTop(struct stack st){
    if(st.top == -1){
        return -1;
    }
    else{
        return st.s[st.top];
    }

}


int main(){
    struct stack st;
    CreateStack(&st);

    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);



    printf("%d\n",peek(st,2));
    
    


   // DisplaysStack(st);
}