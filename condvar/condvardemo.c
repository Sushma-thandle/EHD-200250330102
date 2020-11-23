#include<stdio.h>
#include<pthread.h>

int flag=0;
pthread_mutex_t m1;
pthread_cond_t cv1;

void *thread_1(void *data){
    printf("T1:grabbing mutex\n");
    pthread_mutex_lock(&m1);
    printf("T1:before bl\n");
    while(flag!=1){
        printf("T1:entering conditional wait\n");
        pthread_cond_wait(&cv1,&m1);
        printf("T1:exiting conditional wait\n");
    }
           ;
    printf("T1:after bl\n");
    pthread_mutex_unlock(&m1);
    printf("T1:releasing mutex\n");
}

void *thread_2(void *data){
    printf("T2:grabbing mutex\n");
    printf("T2:before setting flag\n");
    pthread_mutex_lock(&m1);
    flag=1;
    printf("T2:after setting flag\n");
    pthread_mutex_unlock(&m1);
    pthread_cond_signal(&cv1);
    printf("T2:signaling cv\n");
    printf("T2:releasing mutex\n");
}

int main(int argc,char const *argv[]){
    pthread_t t1,t2;
    pthread_mutex_init(&m1,NULL);
    pthread_cond_init(&cv1,NULL);

    pthread_create(&t1, NULL, thread_1, NULL);
    pthread_create(&t2, NULL, thread_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&m1);
    pthread_cond_destroy(&cv1);

    return 0;
}