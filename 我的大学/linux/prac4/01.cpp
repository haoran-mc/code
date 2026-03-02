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
    write(STDOUT_FILENO, buf, n);
    printf("\n");
    // 创建 testfile.txt
    fdsrc = open("testfile.txt", O_CREAT|O_RDWR);
    write(fdsrc, buf, n);
    close(fdsrc);
    // 创建 file2.txt
    fddes = open("file2.txt", O_CREAT|O_RDWR);
    // 打开 testfile.txt
    fdsrc = open("testfile.txt", O_CREAT|O_RDWR);
    read(fdsrc, temp, n);
    write(fddes, temp, n);
    close(fdsrc);
    close(fddes);
    return 0;
}
