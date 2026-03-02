//为什么比我的快呢？
//我的代码是先循环输入，然后循环找到挖掘机的数量，然后双重循环计算学校总分数
//最终循环找到得分最高的学校
//这个代码构造了结构体，在输入时就完成了输入，找到挖掘机数量，计算总分三个步骤

#include<iostream>
#include<algorithm>
using namespace std;

struct school{
    int name   = 0;
    int score = 0;
};

// bool cmp(school A, school B) {
//     return A.score < B.score;
// }
int main() {
    int N;
    int sch;
    int score;
    int name_max = 0;
    scanf("%d", &N);

    school sum[N];

    while (N--) {
        scanf("%d%d", &sch, &score);

        if (name_max < sch) {
            name_max = sch;
        }

        sum[sch].name = sch;
        sum[sch].score += score;
    }

    //这里不如循环找到得分最高的学校
    //快速排序复杂度 O(nlogn), 循环复杂度 O(n)
    // sort(sum, sum+name_max+1, cmp);
    int score_max = 1;
    for (int i = 1; i <= name_max; i++) {
        if (sum[i].score > sum[score_max].score) {
            score_max = i;
        }
    }
    printf("%d %d", sum[score_max].name, sum[score_max].score);
    // printf("%d %d", sum[name_max].name, sum[name_max].score);
    return 0;

}
