#include <cstdio>
int main() {
    printf("\033[;32mZhang:%s\033[0m\n", "This is Zhang");
    puts("我说这不是我");
    puts("这确实不是我");
    printf("\033[;32mZhang:%s\033[0m\n", "今天天气真好！");
    return 0;
}
