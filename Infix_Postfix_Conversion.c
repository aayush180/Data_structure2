
#include<string.h>

struct Node{
    char data;
    struct Node* next;
}*top=NULL;

void push(char x){
    struct Node*t;
    t=(struct Node *)malloc(sizeof(struct Node));
    
    if(t==NULL){
      printf("Stack Is Full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    int x=-1;
    struct Node*t=top;

    if(top==NULL){
        printf("Stack Is Empty\n");
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



int pre(char x){
    if(x=='+'|| x=='-'){
        return 1;
    }
    else if (x=='*'||x=='/'){
        return 2;
    }
    else{
        return 0;
    }
}

char *InToPost(char *infix){
    int i=0, j=0;
    int len=strlen(infix);
    char *postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0'){
        if(Operand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;

}

int main(){
    char *infix="a+b*c-d/e";
    push('#');
    char *postfix=InToPost(infix);
    printf("%s ",postfix);

}