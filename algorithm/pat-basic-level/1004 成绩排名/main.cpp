#include <cstdio>
#include <cstring>

char max_name[15];
char max_id[15];
int max_score = -1;

char end_name[15];
char end_id[15];
int min_score = 101;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    while (n--) {
        char name[15], id[15];
        int score = 0;
        scanf("%s %s %d", name, id, &score);
        if (score > max_score) {
            strcpy(max_name, name);
            strcpy(max_id, id);
            max_score = score;
        }
        if (score < min_score) {
            strcpy(end_name, name);
            strcpy(end_id, id);
            min_score = score;
        }
    }
    printf("%s %s\n", max_name, max_id);
    printf("%s %s", end_name, end_id);
    return 0;
}
