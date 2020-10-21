#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int count=0;

int main(int argc,char const *argv[]){
    pid_t id;
    printf("before fork\n");
    id= fork();
    if(0==id){
        sleep(1);
        printf("count in child %d\n",count);
    }
    else{
        count++;
        printf("count in parent %d\n",count);
    }
    return 0;
}