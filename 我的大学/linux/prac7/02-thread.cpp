#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

pthread_mutex_t mutex;
int x, y;

void* pthread(void* arg) {
    printf("\n");
    for (int i = 0; i < 30; i++) {
        pthread_mutex_lock(&mutex);
        printf("%d ", x + y);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    exit(0);
}

int main() {
    // srand(time(NULL));
    pthread_t id;
    pthread_mutex_init(&mutex, NULL);
    int ret = pthread_create(&id, NULL, pthread, NULL);
    if (ret != 0) {
        printf("create thread1 error\n");
    }
    while (1) {
        pthread_mutex_lock(&mutex);
        x = rand() % 50;
        y = rand() % 50;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return 0;
}
