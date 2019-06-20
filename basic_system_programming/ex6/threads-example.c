#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3

int param[NUM_THREADS] = {2, 3, 5};

void *do_work(void *);

int i;
pthread_t tid[NUM_THREADS];

int main(int argc, char *argv[]) {
    pthread_create(&tid[0], NULL, do_work, &param[0]);
    pthread_create(&tid[1], NULL, do_work, &param[1]);
    pthread_create(&tid[2], NULL, do_work, &param[2]);
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("all threads terminated\n");
    return (0);
}

void *do_work(void *arg) {
    int j, *sleep_time;
    sleep_time = arg;
    for (j = 0; j < 5; j++) {
        printf("Tread %ld:%d\n", (long)pthread_self(), j);
        sleep(*sleep_time);
    }
    return (NULL);
}
