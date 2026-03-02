#include <cstring>
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
int check(stack& k,char m[],int &y)
{
	y = 0;
	int i,t=0,j=0;
	char str,real,rea;
	for(i=0;i<(int)strlen(m);i++)
	{
		str = m[i];
		if (str == '{' || str == '[' || str == '(') {
			Pushstack(k, str);//将所有的左括号入栈
			j++;
		}
		else if (str == ')' ) {
			gettop(k, &real);
			if (real == '(')
				Popstack(k, &rea);
			else
				y = 1;
			t++;
		}
		else if (str == ']') {
			gettop(k, &real);
			if (real == '[')
				Popstack(k, &rea);
			else
				y = 1;
			t++;
		}
		else if (str == '}') {
			gettop(k, &real);
			if (real == '{')
				Popstack(k, &rea);
			else
				y = 1;
			t++;
		}
	}
	if (j > t)
		return 1;

	else if (j < t)
		return 0;
}

int main()
{
	char str[100] = "{}{}{[()()]}";
	stack l;
	int x,m;
	Initstack(l);
	m=check(l, str,x);
	if (x == 1) {
		if (m == 1)
			printf("左括号多于右括号\n");
		else if (m == 0)
			printf("右括号多于左括号\n");
		else
	 		printf("左右括号匹配不正确");
	}
	else
		printf("左右括号匹配正确");
	return 0;
}