#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void fun_ctrl_c(int);

int main() {
    signal(SIGINT, fun_ctrl_c);
    int i;
    while (1) {
        printf("This is main %d\n", i);
        i++;
        sleep(2);
    }
    return 0;
}

void fun_ctrl_c(int zero) {
    static int count = 0;
    count++;
    printf("You have pressed 'Ctrl+c' %d times\n", count);
    printf("You can write code here\n");
    if (count < 2)
        signal(SIGINT, fun_ctrl_c);
    else
        signal(SIGINT, SIG_DFL);
}
