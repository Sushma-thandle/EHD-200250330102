#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int count=0;

void *thread(void *argv[]){
    count++;
    printf("thread\n");
}

int main(int argc,char const *argv[]){
    pthread_t tid;
    count++;
    printf("before thread creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    return 0;
}