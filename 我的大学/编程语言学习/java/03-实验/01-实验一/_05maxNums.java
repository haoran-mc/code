public class _05maxNums {
    public static void main(String[] args ) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        System.out.println("Input numbers:");
        int num = input.nextInt();
        int max = 0;
        int cnt = 0;
        int f = 0;
        while (num != 0) {
            if (f == 0) {
                max = num;
                cnt = 1;
                f = 1;
            }
            if (num == max)
                ++cnt;
            if (num > max) {
                max = num;
                cnt = 1;
            }
            num = input.nextInt();
        }
        System.out.println("max is " + max);
        System.out.println("The count for the max number is " + cnt);
    }
}
