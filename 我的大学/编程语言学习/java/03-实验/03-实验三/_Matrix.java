import java.util.Scanner;

public class _Matrix {
    final static int maxn = 10000 + 5;
    static int[][] matrix = new int[maxn][maxn];

    public static void main(String[] args) {
        int n;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of rows in the square matrix: ");
        n = input.nextInt();
        System.out.println("Enter the matrix row by row: ");

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = input.nextInt();

        int max_size = 0;
        int i_idx = 0;
        int j_idx = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    int lineSize = 0;
                    int _j = j;
                    while (matrix[i][_j++] == 1)
                        ++lineSize;
                    for (int k = i; k < i + lineSize; ++k) {
                        if (matrix[k][j] == 0)
                            lineSize = k - i;
                        int size = 1;
                        _j = j;
                        while (matrix[k][_j++] == 1)
                            ++size;
                        lineSize = Math.min(lineSize, size);
                    }
                    if (lineSize > max_size) {
                        max_size = lineSize;
                        i_idx = i;
                        j_idx = j;
                    }
                }
            }
        System.out.println("The maximum square submatrix is at (" + i_idx + ", " + j_idx + ") with size "  +  max_size);
    }
}
