#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack* next;
}*top=NULL;

void push(int data){
    struct Stack*t;
    t=(struct Stack*)malloc(sizeof(struct Stack));

    if(t==NULL){
        printf("Stack Overflow\n");
    }
    else{
        t->data=data;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct Stack*t=top;

    if(top==NULL){
        printf("Stack is Empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int Operand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int Evolution(char *postfix){
    int x1,x2,r;

    for(int i=0;postfix[i]!='\0';i++){
        if(Operand(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2=pop();x1=pop();
            switch(postfix[i]){
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main(){
    char *postfix="234*+82/-";

    printf("Evolution is %d\n",Evolution(postfix));

}