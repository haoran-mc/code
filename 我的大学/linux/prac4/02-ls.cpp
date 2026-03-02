#include <sys/sysmacros.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

#define PERMISSION_NONE 0
#define PERMISSION_a 1
#define PERMISSION_l 2
#define PERMISSION_R 4

//全局变量判断是否进行显示详细信息，是否进行递归操作
int per_a = 0;
int per_r = 0;
//用于判断是初次递归还是初次之后的递归，用于生成空行
int flag_R = 0;

void print_Dir(char* );
void print_file(char *, char *);
void print_A_Dir(char *);
void display(int, char*);
void sort(char**, int);
int color(char*);

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("usage:cmd + path\n");
        return 1;
    }
    char path[1024];
    char permiss[32];
    int flag = PERMISSION_NONE;
    struct stat st;
    int k = 0, num = 0;
    //提取ls后面-的个数
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            for(int j = 1; j < strlen(argv[i]); j++) {
                permiss[k++] = argv[i][j];    
            }
            num++;
        } 
    }
    for(int i = 0; i < k; i++) {
        switch(permiss[i]) {
            case 'a' : flag |= PERMISSION_a; per_a = 1; break;
            case 'l' : flag |= PERMISSION_l; break;
            case 'R' : flag |= PERMISSION_R; per_r = 1; break;
            default: printf("perssion: invalid option -%c\n", permiss[i]); exit(1);
        }
    }
    if(num + 1 == argc) {
        strcpy(path, ".");
        path[1] = '\0';
        display(flag, path);
    } else {
        for(int i = 1; i < argc; i++) {
            if(argv[i][0] == '-') {
                continue;
            } else {
                strcpy(path, argv[i]);
                path[strlen(argv[i])] = '\0';
                display(flag, path);
            }
        }
        
    }
    putchar(10);
    return 0;
}

//产看目录文件名（含递归）
void print_Dir(char *dirname) {
    char pathname[1024];
    DIR* dir;
    struct dirent *dp;
    struct stat st;
    char* name[1000] = {};
    int num = 0;

    //用于存放文件名称，后续进行字典序排序,一个文件夹最多存放201个文件，每个文件字符个数为最多为201
    char **sort_name = (char**)malloc(sizeof(char*) * 400);
    int n = 0;

    if(!(dir = opendir(dirname))) {
        perror("opendir:");
        exit(1);
    }
    //判断全局变量是否为1, 
    if(per_r) {
        if(flag_R) {
            printf("\n\n");
            printf("\033[37m%s:\n", dirname);
        } else  {
            printf("\033[37m%s:\n", dirname);
        }
    }
    if(per_a) {
        printf("\033[%dm.   ",color("."));
        printf("\033[%dm..   ", color(".."));
    }
    while(dp = readdir(dir)) {
        if(!strcmp(dp->d_name ,".") || !strcmp(dp->d_name ,"..")) {
            continue;
        }
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        if(stat(pathname, &st) < 0) {
            perror("stat");
            exit(1);
        }
        if(S_ISDIR(st.st_mode)) {
            name[num] = (char *)malloc(sizeof(char) * 1024);
            strcpy(name[num], pathname);
            num++;
        }
        sort_name[n] = (char*)malloc(sizeof(char) * 200);
        sprintf(sort_name[n], "%s", dp->d_name);
        n++;
        //printf("%s\t", dp->d_name);
    }
    sort(sort_name, n);
    for(int i = 0; i < n; i++) {
        sprintf(pathname, "%s/%s", dirname, sort_name[i]);
        printf("\033[%dm%s   ",color(pathname), sort_name[i]);
    }
    closedir(dir);
    //全局变量确定是否递归
    if(per_r) {
        flag_R = 1;
        for(int i = 0; i < num; i++) {
            print_Dir(name[i]);
        }
    }
}

//打印详细目录文件信息 与 递归打印目录目录详细信息
void print_A_Dir(char *dirname) {
    char pathname[1024];
    DIR* dir;
    struct dirent *dp;
    struct stat st;
    char *name[1000] = {};
    int num = 0;
    //用于存放目录信息
    char **sort_name = (char**)malloc(sizeof(char*) * 300);
    int n = 0;

    if(!(dir = opendir(dirname))) {
        perror("opendir:");
        exit(1);
    }
    //判断递归当前递归打印为第几次
    if(per_r) { 
        if(flag_R) {
            printf("\n");
            printf("%s:\n", dirname);
        } else {
            printf("%s:\n", dirname);
        }
    }
    if(per_a) {    
        print_file(".", ".");
        print_file("..", "..");
    }
    while(dp = readdir(dir)) {
        //字符串本质是字符首地址，所以字符串比较，需要比较用strcmp,相同返回0。
        if(!strcmp(dp->d_name ,".") || !strcmp(dp->d_name ,"..")) {
            continue;
        }
        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        //用于判断是否存在目录文件
        if(stat(pathname, &st) < 0) {
            perror("stat");
            exit(1);
        }
        //若存在目录文件，将其保存至递归数组中
        if(S_ISDIR(st.st_mode)) {
            name[num] = (char *)malloc(sizeof(char) * 1024);
            strcpy(name[num], pathname);
            num++;
        }
        sort_name[n] = (char*)malloc(sizeof(char) * 200);
        sprintf(sort_name[n], "%s", dp->d_name);
        n++;
    }
    //将本目录文件名排序打印输出
    sort(sort_name, n);
    for(int i = 0; i < n; i++) {    
        sprintf(pathname, "%s/%s", dirname, sort_name[i]);
        print_file(pathname, sort_name[i]);
    }
    closedir(dir);
    //全局变量per_r判断是否进行递归
    if(per_r) {
        flag_R = 1;
        for(int i = 0; i < num; i++) {
            print_A_Dir(name[i]);
        }
    }
}

//打印常规文件详细信息
void print_file(char *filename, char *dpname) {

    //以下默认字体为白色
    printf("\033[37m");

    struct stat st;
    struct passwd psd1;
    struct group grp1;
    struct passwd* psd = &psd1;
    struct group* grp = &grp1;
    char buf_time[100];
    char buf1_time[100];

    if(stat(filename, &st) < 0) {
        perror("stat");
        exit(1);
    }
    //查看文件类型
    switch (st.st_mode & S_IFMT) {
       case S_IFBLK:  printf("b");        break;
       case S_IFCHR:  printf("c");        break;
       case S_IFDIR:  printf("d");        break;
       case S_IFIFO:  printf("f");        break;
       case S_IFLNK:  printf("l");        break;
       case S_IFREG:  printf("-");        break;
       case S_IFSOCK: printf("s");        break;
       default:       printf(" ");        break;
    }

    if(st.st_mode & S_IRUSR) {
        printf("r");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IWUSR) {
        printf("w");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IXUSR) {
        printf("x");
    } else {
        printf("-");
    }
    
    if(st.st_mode & S_IRGRP) {
        printf("r");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IWGRP) {
        printf("w");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IXGRP) {
        printf("x");
    } else {
        printf("-");
    }

    if(st.st_mode & S_IROTH) {
        printf("r");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IWOTH) {
        printf("w");
    } else {
        printf("-");
    }
    if(st.st_mode & S_IXOTH) {
        printf("x");
    } else {
        printf("-");
    }
    psd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    printf(" %ld ", (long)st.st_nlink);    //打印文件的链接数
    printf("%-8s ", psd->pw_name);
    printf("%-8s ", grp->gr_name);
    printf("%ld\t", (long)st.st_size);
    strcpy(buf_time, ctime(&st.st_mtime));
    buf_time[strlen(buf_time) - 1] = '\0';  //去掉换行符
    for(int i = 4; i < 16; i++) {
        buf1_time[i - 4] = buf_time[i];
    }
    buf1_time[12] = '\0';
    printf(" %s ", buf1_time);
    //显示文件名称
    printf("\033[%dm%s\n", color(filename), dpname);
}

void display(int flag, char* path) {
    struct stat st;
    if(stat(path, &st) < 0) {
        perror("stat");
        exit(1);
    }
    if(flag & PERMISSION_l) {
        if(S_ISDIR(st.st_mode)) {
            print_A_Dir(path);
        } else {
            print_file(path, path);
        }    
    } else {
        print_Dir(path);
    } 

}
//文件名字典序排序
void sort(char **a, int n ) {
    char temp[201];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(a[i],a[j]) > 0) {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
}
//加入字体颜色
int color(char* path) {
    struct stat st;
    stat(path, &st);
    if(S_ISDIR(st.st_mode)) {
        return 34;
    } else if(S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR)) {
        return 32;
    }
    return 37;
}
