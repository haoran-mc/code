#include <cstdio>
int main() {
    puts("This is Zhang");
    printf("\033[;32mLi:%s\033[0m\n", "我说这不是我");
    printf("\033[;32mLi:%s\033[0m\n", "这确实不是我");
    puts("今天天气好！");
    return 0;
}
