import java.util.Scanner;

public class _01input {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = input.nextInt();
        System.out.println("The number is " + num);
    }
}
