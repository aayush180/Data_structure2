#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node* next;
}*top=NULL;

void push(char x){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Stack Is Full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct Node*t;

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

void Display(){
    struct Node*p=top;

    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

//Checking the poped character and exp[i]ie closing brackets is matched or not 
int match(char a,char b){
   if(a=='(' && b==')'){
       return 1;
   }
   else if(a=='[' && b==']'){
    return 1;
   }
   else if(a=='{'&& b=='}'){
       return 1;
   }
   else{
       return 0;
   }
}

int MultiBalanced(char *exp){
    char poped_ch;
   for(int i=0;exp[i]!='\0';i++)
   {
       if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
           push(exp[i]);
       }
       else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
       {
           if(top==NULL){
               return 0;          //For This Condition (( )))
           }
           else
           {
              poped_ch=pop();
              if(!match(poped_ch,exp[i])){
                  return 0;
              }
              
           }
       }
   }
   if(top==NULL){
       return 1;
   }
   else{
       return 0;
   }
}

int main(){
    char *exp="{(a+b)+[a-c}}";

    if(MultiBalanced(exp)){
        printf("IS Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }

}