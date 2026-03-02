#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
//挂起的话另一边检测不到，而且重连回去还可以接受到挂起期间对方发来的消息。关闭的话就无了，对面也会知道你挂了
int main() {
    int i, rfd, wfd;
    int len=0;
    char str[32];
    fd_set write_fd, read_fd;
    struct timeval net_timer;
    mkfifo("fifo1", S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH);
    mkfifo("fifo2", S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH);
    wfd=open("fifo1", O_WRONLY);
    rfd=open("fifo2", O_RDONLY);
    if((wfd<0)||(rfd<0)) {
        return 0;
    }
    printf("This is Zhang\n");
    while(1) {
        sleep(5);
        FD_ZERO(&read_fd);
        FD_SET(rfd, &read_fd);
        FD_SET(fileno(stdin), &read_fd);
        net_timer.tv_sec=5;
        net_timer.tv_usec=0;
        memset(str, 0, sizeof(str));
        if((i=select(rfd+1, &read_fd, NULL, NULL, &net_timer))<=0) {
            continue;
        }
        if(FD_ISSET(rfd, &read_fd)) {
            read(rfd, str, sizeof(str));
            printf("---------------------------------------\n");
            printf("Li: %s\n", str);
        }
        if(FD_ISSET(fileno(stdin), &read_fd)) {
            printf("---------------------------------------\n");
            fgets(str, sizeof(str), stdin);
            len=write(wfd, str, strlen(str));
        }
    }
    close(rfd);
    close(wfd);
}
