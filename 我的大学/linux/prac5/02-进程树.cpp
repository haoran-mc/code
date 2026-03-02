#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, i = -1, j;
    for (i = 0; i < 2; i++) {
        ret = fork();
        if (ret == 0)
            break;
    }
    if (ret == 0) {
        for (j = 0; j < i; j++) {
            ret = fork();
            if (ret == 0)
                break;
        }
    }
    sleep(10);
    printf("Process %d is exiting now \r\n", getpid());
    return 0;
}
