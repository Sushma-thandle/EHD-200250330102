#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void *argv[]){
    printf("thread\n");
}

int main(int argc,char const *argv[]){
    pthread_t tid;
    printf("before thread creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    sleep(1);
    printf("after sleep creation\n");
    return 0;
}