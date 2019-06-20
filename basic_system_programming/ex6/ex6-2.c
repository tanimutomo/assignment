#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define NUM_THREADS 4
#define NUM_MAX 1000

void *do_calc(void *);
pthread_t tid[NUM_THREADS];
pthread_mutex_t mutex;
int param;
int sum;

int main() {
    int i;
    sum = 0;
    param = 0;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&tid[i], NULL, do_calc, &param);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("Sum %d\n", sum);
    return 0;
}

void *do_calc(void *arg) {
    int i;
    usleep(random() % 10000);
    for (i = 1; i < NUM_MAX; i++) {
        usleep(random() % 5000);
        pthread_mutex_lock(&mutex);
        sum = sum + i;
        pthread_mutex_unlock(&mutex);
        usleep(random() % 5000);
    }
    pthread_exit(NULL);
}

