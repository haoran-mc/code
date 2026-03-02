class Solution {
public:
    /**
     *
     * @param a long长整型 木棒的长度
     * @return int整型
     */
    int stick(long long a) {
        long long Fibo[85];
        Fibo[0] = 1;
        Fibo[1] = 1;
        for (int i = 2; i < 85; ++i)
            Fibo[i] = Fibo[i-1] + Fibo[i-2];

        long long sum[85];
        sum[0] = Fibo[0];
        for (int i = 1; i < 85; ++i)
            sum[i] = sum[i-1] + Fibo[i];

        int sticks = 0;
        for (int i = 0; i < 85 && !sticks; ++i) {
            if (a == sum[i]) {
                sticks = i+1; break;
            }
            if (a < sum[i]) {
                sticks = i; break;
            }
        }
        return sticks;
    }
};
