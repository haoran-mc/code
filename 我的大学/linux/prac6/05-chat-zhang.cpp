#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char str1[5000];
    char str2[5000];
    int no1, no2;
} str;

int main()
{
    int shm_id, i;
    key_t key;
    str *p_map = (str *)malloc(sizeof(str));
    char* name = (char *)"/dev/shm/myshm00";
    key = ftok(name, 0);
    shm_id = shmget(key, 4096, IPC_CREAT);
    if (shm_id == -1)
    {
        perror("获取共享内存ID出错");
        return 0;
    }
    (*p_map).no1 = 0;
    (*p_map).no2 = 0;
    p_map = (str*)shmat(shm_id, NULL, 0);
    printf("This is Zhang.\n");
    fgets((*p_map).str2, sizeof((*p_map).str2), stdin);
    (*p_map).no1 = 1;
    while (1)
    {
        if((*p_map).no2 == 1)
        {
            printf("Li:%s\n", (*p_map).str1);
            (*p_map).str1[0] = '\0';
            (*p_map).no2 = 0;
        }
        else
            continue;
        if ((*p_map).no1 == 0)
        {
            fgets((*p_map).str2, sizeof((*p_map).str2), stdin);
            (*p_map).no1 = 1;
        }
    }
    if (shmdt(p_map) == -1)
    {
        perror("解除映射出错");
    }
    return 0;
}
