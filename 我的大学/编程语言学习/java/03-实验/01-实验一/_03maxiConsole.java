public class _03maxiConsole {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        System.out.print("Input the first number you want to compare: ");
        int number1 = input.nextInt();
        System.out.print("Input the second number you want to compare: ");
        int number2 = input.nextInt();
        if (number2 > number1) {
            number1 += number2;
            number2  = number1 - number2;
            number1 -= number2;
        }
        System.out.println("The maximum is " + number1);
    }
}
