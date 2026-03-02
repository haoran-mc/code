#include <stdio.h>
#include <unistd.h>

int main() {
    int ret;
    ret = fork();
    printf("A\n");
    ret = fork();
    printf("B\n");
    return 0;
}
