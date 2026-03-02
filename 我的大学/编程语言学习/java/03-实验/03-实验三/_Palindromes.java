/*
 * 如果一个整数其顺序和逆序数值相同，如121，则称为回文数。找出99999以内的所有正整数，使得其满足自身，自身的平方，自身的三次方均是回文数。
 * 在该程序中要求使用以下方法：
 * //return the reversal of an integer, i.e. reverse(456) returns 654
 * public static long reverse(long number)
 *
 * //return true if number is Palindrome
 * public static boolean isPalindrome(long  number)
 */

public class _Palindromes {
    public static long reverse(long number) {
        long reverseNumber = 0;
        while (number != 0) {
            long lastBase = number % 10;
            reverseNumber = 10 * reverseNumber + lastBase;
            number /= 10;
        }
        return reverseNumber;
    }


    public static boolean isPalindrome(long number) {
        if (number == reverse(number))
            return true;
        else
            return false;
    }


    public static void main(String[] args) {
        for (int i = 1; i < 100000; ++i) {
            if (isPalindrome(i) && isPalindrome(i * i) && isPalindrome(i * i * i))
                System.out.println(i);
        }
    }
}
