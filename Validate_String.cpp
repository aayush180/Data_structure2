#include<iostream>
#include<stdio.h>
using namespace std;

int Valid(char *name)
{
char *name[]={"Anil123"};
int i;

for(i=0;name[i] != '\0';i++)
{
    if(!(name[i] >=65 && name[i]<= 90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
    {
        return 0;
    }
    else{
        return 1;
    }
}
}


int main(){
     char *name={"Anil123"};

     if(Valid(name)){
         printf("Is Valid");
     }
     else{
         printf("Invalid");
     }
}