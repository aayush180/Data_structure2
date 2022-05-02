#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int x,int y){
  int temp=x;
  x=y;
  y=temp;
}
void permu(char s[],int k){
    static int A[10]={0};
    static char res[10];
    int i;
    if(s[k]=='\0'){
        res[k] = '\0';
        printf("%s ",res);
    }
    else{
        for( i=0;s[i]!='\0';i++){
            if(A[i]== 0)
            {
                res[k]=s[i];
                A[i]=1;
                permu(s,k+1);
                A[i]=0;
            }
        }
    }
}

void permu2(char s[],int l,int h){
    int i;
    int temp;
    if(l == h){
        printf("%s ",s);
    }
    else{
        for(i=l;l<=h;i++)
        {
           temp=s[l];
           s[l]=s[i];
           s[i]=temp;
           permu2(s,l+1,h);
            temp=s[l];
           s[l]=s[i];
           s[i]=temp;
        }
    }
}
int main(){
    char s[]={"ABC"};
    permu2(s,0,2);
}