#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barr;

void *serial(void *arg){
    printf("serial: Initialization started\n");
    sleep(2);
    printf("serial: Initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("serial:started\n");
}

void *ethernet(void *arg){
    printf("ethernet: Initialization started\n");
    sleep(10);
    printf("ethernet: Initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("ethernet:started\n");
}
void *lcd(void *arg){
    printf("lcd: Initialization started\n");
    sleep(7);
    printf("lcd: Initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("lcd:started\n");
}
void *adc(void *arg){
    printf("adc: Initialization started\n");
    sleep(4);
    printf("adc: Initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("adc:started\n");
}


int main(int argc, char const *argv[]){

    pthread_t s,e,l,a;
    pthread_barrier_init(&barr, NULL , 4);

    pthread_create(&s, NULL, serial, NULL);
    pthread_create(&e, NULL, ethernet, NULL);
    pthread_create(&l, NULL, lcd, NULL);
    pthread_create(&a, NULL, adc, NULL);

    pthread_join(s,NULL);
    pthread_join(e,NULL);
    pthread_join(l,NULL);
    pthread_join(a,NULL);

    pthread_barrier_destroy(&barr);
    return 0;

}