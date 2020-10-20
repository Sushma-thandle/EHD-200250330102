#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char const *argv[]){
    pid_t id;
    pid_t parent_id;
    id = getpid();
    parent_id = getppid();
    printf("pid:%d\n",id);
    printf("ppid:%d\n",parent_id);
    return 0;
}