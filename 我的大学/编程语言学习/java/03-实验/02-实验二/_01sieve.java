/*
 * 双骰子游戏的规则是：掷两个骰子，每个骰子有六个面，分别表示值1，2，...，6。检查这两个骰子的和，
 * 1. 如果和为2、3或12，你就输了；如果和是7或11，你就赢了；
 * 2. 如果和是其他数字（例如：4、5、6、8、9或10），就确定了一个点，继续掷骰子，直到掷出一个7或者掷出和刚才相同的点数，
 *         3. 如果掷出的是7，你就输了。
 *         4. 如果掷出的点数和前一次掷出的点数相同，你就赢了。
 * 程序扮演一个独立玩家，编写该程序并运行10000次，显示赢得游戏的次数。
 */

public class _01sieve {
    public static void main(String[] args) {
        int cnt = 10000;
        int win = 0;
        while (cnt-- != 0) {
            int sieve1 = (int)(6 * Math.random() + 1);
            int sieve2 = (int)(6 * Math.random() + 1);
            int sum = sieve1 + sieve2;
            if (sum == 7 || sum == 11) {
                ++win;
                continue;
            }
            int rem = sum;
            while (true) {
                sieve1 = (int)(6 * Math.random() + 1);
                sieve2 = (int)(6 * Math.random() + 1);
                sum = sieve1 + sieve2;
                if (sum == 7)
                    break;
                else if (sum == rem) {
                    ++win;
                    break;
                }
                else
                    rem = sum;
            }
        }
        System.out.println("The times you win is : " + win);
    }
}
