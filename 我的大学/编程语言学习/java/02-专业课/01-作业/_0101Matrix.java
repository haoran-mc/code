import java.util.Scanner;

public class _0101Matrix {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[][] arr = new int[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                arr[i][j] = (int)(2 * Math.random());
        printMatrix(arr, n);
        findMaxRow(arr, n);
        findMaxColumn(arr, n);
        input.close();
    }

    //打印矩阵
    public static void printMatrix(int[][] arr, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                System.out.print(arr[i][j]);
            System.out.println();
        }
    }

    //找到最大的行
    public static void findMaxRow(int[][] arr, int n) {
        int maxi = 0;
        int cnt  = 0;
        int idx  = -1;
        for (int i = 0; i < n; ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j)
                cnt += arr[i][j];
            if (cnt > maxi) {
                maxi = cnt;
                idx = i;
            }
        }
        if (idx != -1)
            System.out.println("The largest row index: " + idx);
    }

    //找到最大的列
    public static void findMaxColumn(int[][] arr, int n) {
        int maxi = 0;
        int cnt  = 0;
        int idx  = -1;
        for (int i = 0; i < n; ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j)
                cnt += arr[j][i];
            if (cnt > maxi) {
                maxi = cnt;
                idx = i;
            }
        }
        if (idx != -1)
            System.out.println("The largest column index: " + idx);
    }
}
