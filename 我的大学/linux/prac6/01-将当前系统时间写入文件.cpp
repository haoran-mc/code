#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

void init(){
    pid_t child1, child2;
    child1 = fork();
    if (child1 > 0)
        exit(0);
    else if (child1 < 0) {
        perror("创建子进程失败");
        exit(1);
    }
    setsid();
    chdir("/tmp");
    umask(0);
    for (int i = 0; i < NOFILE; i++) {
        close(i);
    }
    return;
}

int main() {
    init();
    while (1) {
        printf("--\n");
        sleep(5);
        FILE* fp = fopen("6-9.log", "a+");
        if (fp >= 0) {
            time_t t = time(0);
            fprintf(fp, "log:%s", asctime(localtime(&t)));
            fclose(fp);
        }
    }
    return 0;
}
