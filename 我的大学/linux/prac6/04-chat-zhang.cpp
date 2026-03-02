#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
struct massage {
    long type;
    char text[80];
};
struct massage buf;

int msgid;

void *recive(void *p) {
    struct massage buf2;
    while (1) {
        sleep(8);
        bzero(&buf2,sizeof(buf2));
        msgrcv(msgid,&buf2,sizeof(buf2),100,0);//阻塞等待mytype为100的值
        printf("\033[;32mLi:%s\033[0m",buf2.text);//加个颜色，不用管
        fflush(stdout);
    }
    return 0;
}

int main() {
    key_t key=ftok("/mnt/c/Users/haora/haoran/Code/Professional_course/Linux/prac6/04-chat.txt", 300);
    msgid=msgget(key, IPC_CREAT|0666);

    pthread_t pid;
    pthread_create(&pid, NULL, recive, NULL);//创建一个线程运行接收函数
    while(1) {
        bzero(&buf,sizeof(buf));
        buf.type = 200;
        fgets(buf.text,sizeof(buf.text),stdin);

        msgsnd(msgid,&buf,sizeof(buf),0);
    }
    msgctl(msgid, IPC_RMID, 0);
    return 0;
}
