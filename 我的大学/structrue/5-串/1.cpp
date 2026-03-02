#include <cstdio>
#include <cstring>
int main()
{
    char hi[20] = "hello ";
    char *name  = "haoran"; //课程里说这样可以，但C++不建议大家这样做

    printf("%s\n", strcat(hi, name));
    return 0;
}
