#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
char buf[1000];
char temp[1000];
int p, n;
int fdsrc, fddes;

int main () {
    printf("输入文件内容，以回车结尾\n");
    int n = read(STDIN_FILENO, buf, 1000);
    if (n < 0) {
        printf("read STDIN_FILENO\n");
        exit(1);
    }

    printf("你输入的信息是:\n");
    write(STDOUT_FILENO, buf, n);
    printf("\n");

    // 创建文件
    if ((fdsrc = open("testfile.txt", O_CREAT|O_RDWR)) < 0) {
        /*选项O_TRUNC 表示文件存在时清空*/
        perror("打开文件 testfile.txt 出错\n");
        exit(1);
    } else {
        printf("创建文件 testfile.txt，文件描述符为：%d\n", fdsrc);
    }
    write(fdsrc, buf, n);
    if (close(fdsrc) < 0) {
        printf("关闭文件 testfile.txt 出错\n");
        exit(1);
    }
    printf("内容存入 testfile.txt\n");

    // 复制文件
    if ((fddes = open("file2.txt", O_CREAT|O_RDWR)) < 0) {
        /*选项O_TRUNC 表示文件存在时清空*/
        printf("打开文件 file2.txt 出错\n");
        exit(1);
    } else {
        printf("创建文件 file2.txt，文件描述符为：%d\n", fddes);
    }

    if ((fdsrc = open("testfile.txt", O_CREAT|O_RDWR)) < 0) {
        /*选项O_TRUNC 表示文件存在时清空*/
        perror("打开文件 testfile.txt 出错\n");
        exit(1);
    } else {
        printf("打开文件 testfile.txt，文件描述符为：%d\n", fdsrc);
    }
    read(fdsrc, temp, n);
    write(fddes, temp, n);

    if (close(fdsrc) < 0) {
        printf("关闭文件 testfile.txt 出错\n");
        exit(1);
    }

    if (close(fddes) < 0) {
        printf("关闭文件 file2.txt 出错\n");
        exit(1);
    }
    printf("内容已复制到 file2.txt\n");
    return 0;
}
