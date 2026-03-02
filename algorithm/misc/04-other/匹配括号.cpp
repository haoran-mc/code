    /*
     *for (循环每个字符) {
     *    if 是左括号 then
     *        进栈
     *    else
     *        if str是右圆括号
     *            if 栈顶是左圆括号
     *                匹配成功，pop栈顶
     *            else
     *                匹配失败，返回错误信息
     *        if str是右方括号
     *            if 栈顶是左方括号
     *                匹配成功，pop栈顶
     *            else
     *                匹配失败，返回错误信息
     *        if str是右花括号
     *            if 栈顶是左花括号
     *                匹配成功，pop栈顶
     *            else
     *                匹配失败，返回错误信息
     *}
     */
#include <iostream>
using namespace std;
#define OVERFLOW -99
#define STACKSIZE 10
#define Increasestack 10
typedef int elemtype;
typedef struct stack
{
    elemtype* base;
    elemtype* top;
    elemtype stacksize;//当前栈的大小
}stack;
/*栈的初始化*/
void Initstack(stack &k)
{
    k.base = (elemtype*)malloc(STACKSIZE * sizeof(elemtype));
    if (k.base == NULL) exit(OVERFLOW);
    k.top = k.base;
    k.stacksize= STACKSIZE;
}
void gettop(stack& k, char *m)
{
    if (k.top == k.base) exit(OVERFLOW);
    *m = *(k.top - 1);
}
void Pushstack(stack &k,elemtype e)
{
    elemtype* newbase;
    if (k.top - k.base == STACKSIZE)
    {
        newbase = (elemtype*)realloc(k.base, (STACKSIZE + Increasestack));
        if (newbase == NULL)  exit(OVERFLOW);
        k.base = newbase;
        k.top = newbase + STACKSIZE;
        k.stacksize = k.stacksize + STACKSIZE;
    }
    *(k.top) = e;
    k.top++;
}
void Popstack(stack& k,char *e)
{
    if (k.top == k.base) exit(OVERFLOW);
    *e = *(--k.top);//一开始top指向的是栈顶元素的上一个位置，所以--必须放在前面，先减一再赋值。
}
int check(stack& k,char m[])
{
    int i;
    char str,real,rea;
    for(i=0;i<20;i++)
    {
        str = m[i];
        if (str == '{' || str == '[' || str == '(')
        {
            Pushstack(k, str);//将所有的左括号入栈
        }
        else if (str == ')' || str == ']' ||str== '}')
        {
            gettop(k, &real);
            if (real == m[i])
            {
                Popstack(k, &rea);
                continue;
            }
            else
                return 0;
        }
        else
            continue;
    }
    return 1;
}
int main()
{
    char str[20] = "{[()()]}";
    stack l;
    int x;
    Initstack(l);
    x = check(l, str);
    if (x == 1)
        printf("左右括号匹配正确");
    else
        printf("左右括号匹配不正确");
}
