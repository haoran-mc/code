/*
 * [> Return true if the card number is valid <]
 * public static boolean isValid(long number)
 * [> Get the result from Step 2 <]
 * public static int sumOfDoubleEvenPlace(long number)
 * [> Return this number if it is a single digit, otherwise, return the sum of the two digits <]
 * public static int getDigit(int number)
 * [> Return sum of odd place digits in number <]
 * public static int sumOfOddPlace(long number)
 * [> Return true if the number d is a prefix for number <]
 * public static boolean prefixMatched(long number, int d)
 * [> Return the number of digits in d <]
 * public static int getSize(long d)
 * [> Return the first k number of digits from number. If the number of digits in number is less than k, return number. <]
 * public static long getPrefix(long number, int k)
 */
import java.util.Scanner;

public class _01card {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long card = input.nextLong();
        // long card = 4388576018402626L;
        // long card = 4388576018410707L;
        // long card = 4388576018402626L;
        boolean flag = isValid(card);
        if (!flag) {
            System.out.println(card + " is invalid");
            return ;
        }

        flag = sumOfDoubleEvenPlace(card);
        if (!flag) {
            System.out.println(card + " is invalid");
            return ;
        }
        System.out.println(card + " is valid");
    }

    public static boolean isValid(long number) {
        String str = String.valueOf(number);
        if (str.charAt(0) == '4' || str.charAt(0) == '5' || str.charAt(0) == '6' || (str.charAt(0) == '3' && str.charAt(0) == '7'))
            return true;
        return false;
    }

    public static boolean sumOfDoubleEvenPlace(long number) {
        String str = String.valueOf(number);
        if (!(13 <= str.length() && str.length() <= 16))
            return false;
        int endAdd = str.length() - 2;
        //偶数位
        int sumEven = 0;
        for (int i = endAdd; i >= 0; i -= 2) {
            int num = Integer.parseInt(str.substring(i, i+1));
            num *= 2;
            if (num >= 10) {
                sumEven += num % 10;
                num /= 10;
                sumEven += num % 10;
            }
            else
                sumEven += num;
        }
        //奇数位
        int sumOdd = 0;
        // System.out.println(str.charAt(str.length()-1));
        for (int i = endAdd+1; i >= 0; i -= 2) {
            int num = Integer.parseInt(str.substring(i, i+1));
            /*
             * num *= 2;
             * if (num >= 10) {
             *     sumOdd += num % 10;
             *     num /= 10;
             *     sumOdd += num % 10;
             * }
             * else
             */
            sumOdd += num;
        }

        int sum = sumEven + sumOdd;
        if (sum % 10 != 0)
            return false;
        return true;
    }
}
