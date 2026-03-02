#include <iostream>
using namespace std;
int panduan(char* strbegin)
{
	int signal=1;
	char* strend;
	char *adress;
	adress = strbegin;
	while (*strbegin != '\0')
	{
		strbegin++;
	}
	strend = strbegin;
	strbegin = adress;
	while (strbegin < strend)
	{
		if (*strbegin != *strend)
		{
			signal = 0;
		}
		strbegin++;
		strend--;
	}
	return signal;
}
int main()
{
	int x;
	char str[20] = "level";
	x = panduan(str);
	if (x == 1)
	{
		printf("字符串%s是回文串", str);
	}
	else
		printf("字符串%s不是回文串", str);
}
