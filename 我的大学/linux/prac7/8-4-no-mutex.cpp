#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int lock_var;   // 两个线程都能修改的共享变量，访问变量必须互斥

void* pthread1(void *arg);
void* pthread2(void *arg);

void* pthread1(void *arg) {   // 第一个线程执行代码
    for (int i = 0; i < 2; i ++ ) {
        lock_var ++ ;
        printf("pthread1: 第%d次循环，第1次打印 lock_var=%d\n", i, lock_var);
        sleep(1);
        printf("pthread1: 第%d次循环，第2次打印 lock_var=%d\n", i, lock_var);
        // 已经完成了临界区的处理，解除对临界区的锁定
        sleep(1);
    }
    return 0;
}

void* pthread2(void *arg) {   // 第二个线程执行代码
    for (int i = 0; i < 5; i ++ ) {
        sleep(1);
        lock_var ++ ;
        printf("pthread2: 第%d次循环，第1次打印 lock_var=%d\n", i, lock_var);
        // 已经完成了临界区的处理，解除对临界区的锁定
        sleep(1);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    pthread_t id1, id2;
    int ret;
    ret = pthread_create(&id1, NULL, pthread1, NULL);   // 创建第1个线程
    if (ret != 0)
        printf("pthread cread1\n");
    ret = pthread_create(&id2, NULL, pthread2, NULL);   // 创建第2个线程
    if (ret != 0)
        printf("pthread cread2\n");
    pthread_join(id1, NULL);   // 等待第1个线程结束
    pthread_join(id2, NULL);   // 等待第2个线程结束
    exit(0);
}
