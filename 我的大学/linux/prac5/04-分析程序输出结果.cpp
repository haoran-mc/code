#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int g = 0;
int main() {
    int s = 1;
    int* h = (int *)malloc(sizeof(int));
    *h = 3;
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork error\n");
        exit(1);
    }
    if (pid == 0) {
        g = 2;
        s++;
        (*h)++;
        printf("Child process: s=%d, h=%d\n", s, *h);
    }
    else if (pid > 0) {
        sleep(10);
        g = 9;
        printf("Parent process: s=%d, h=%d\n", s, *h);
    }
    printf("g=%d\n", g);
    free(h);
    return 0;
}
