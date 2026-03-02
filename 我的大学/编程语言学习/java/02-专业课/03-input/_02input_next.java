import java.util.Scanner;

public class _02input_next {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("next方式接收：");
        if (input.hasNext()) {  // 判断是否还有输入
            String str1 = input.next();
            System.out.println("输入的数据为：" + str1);
        }
        input.close();
    }
}
