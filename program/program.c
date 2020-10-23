#include<stdio.h>

int add(int a,int b){
    int sum=0;
    sum=a+b;
    return sum;
}

int main(int argc,char const *argv[]){
    printf("program\n");
    printf("add:%d\n",add(10,20));
    return 0;
}