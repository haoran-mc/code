#include <cstdio>
void print(int idx) {
    if (idx == 0)
        printf("0\n");
    else if (idx == 1)
        printf("2\n");
    else if (idx == 2)
        printf("4\n");
    else
        printf("2\n");
}
int main()
{
    int room[4];
    for (int i = 0; i < 4; ++i)
        scanf("%d", &room[i]);
    int ext;
    scanf("%d", &ext);
    int idx;
    scanf("%d", &idx);
    if (ext >= room[idx-1])
        print(idx-1);
    else
        printf("0\n");
    return 0;
}
