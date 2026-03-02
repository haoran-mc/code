#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void fun_ctrl_z(int);
int main() {
	signal(SIGTSTP, fun_ctrl_z);
	printf("主程序：程序进入一个无限循环！\n");
	while(1) {
		printf("这是一个无限循环（要退出请按<Ctrl>+Z键）！\n");
		sleep(3);
	}
	exit(0);
}

void fun_ctrl_z(int zero) {
	printf("你按了<Ctrl>+Z键");
	signal(SIGTSTP, SIG_DFL);
}
