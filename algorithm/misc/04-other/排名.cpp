#include<cstdio>
#include<cstring>
int main()
{
	int n;  /*考生数*/
    int m;  /*考题数*/
    int g;  /*分数线*/
	char c[100][100];    /*考生ID*/

	while(scanf("%d", &n) && n != 0) {
        scanf("%d%d", &m, &g);
        int t[n] = {0};  /*bool t[n] = {false};//判断是否过界*/
        int M[m] = {0};  /*题目分值*/
        int b[n][m] = {0};
        int shu[n];
        for(int i = 1; i <= m; i++)
            scanf("%d", &M[i]);        /*题目分值*/

        for(int j = 1; j <= n; j++) {  /*考生答题信息*/
            scanf("%s", c[j]);
            scanf("%d", &shu[j]);      /*过题数目*/
            for(int k = 1; k <= shu[j]; k++)
                scanf("%d", &b[j][k]); /*第j个考生b[j][k]题通过*/
        }

        int sum1 = 0;         //总分
        int sum2 = 0;         //及格人数
        int sum3[n] = {0};    //及格人数分数
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= shu[j]; i++)
                sum1 += M[b[j][i]];  //计算每位学生的总分

            if (sum1 >= g) {  //判断是否过线
                sum2 += 1;    //计算过线人数
                t[j] = j;     //为过线学生登记一个“编号”  //******bool t[n] = {false};  t[j] = true;
            }
            sum3[j] = sum1;   //登记每一位学生分数
            sum1 = 0;
        }

        printf("%d\n", sum2); //输出过线人数
        int x;
        int z;
        char y[100];
        for(int i = 1; i <= n-1; i++) {
            if(sum3[i] < sum3[i+1]) {
                x = sum3[i];
                sum3[i] = sum3[i+1];
                sum3[i+1] = x; //交换分数
                strcpy(y, c[i]);
                strcpy(c[i], c[i+1]);
                strcpy(c[i+1], y); //交换学号
                z = t[i];
                t[i] = t[i+1];
                t[i+1] = z; //交换“编号”
            }
        } //按照分数排名完成

        for (int i = 1; i <= n-1; i++) {
            if (strcmp(c[i], c[i+1])>0) {
                x = sum3[i];
                sum3[i] = sum3[i+1];
                sum3[i+1] = x;
                strcpy(y, c[i]);
                strcpy(c[i], c[i+1]);
                strcpy(c[i+1], y);
                z = t[i];
                t[i] = t[i+1];
                t[i+1] = z;
            }
        }  //分数一样的按照考号升序排列完成
        for(int i = 1; i <= n; i++)
            if(t[i] != 0)
                printf("%s %d\n", c[i], sum3[i]);
    }
    return 0;
}
