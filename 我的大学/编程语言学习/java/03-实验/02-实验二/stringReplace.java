import java.util.Scanner;

public class stringReplace {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入文本：");
        String textOld = input.nextLine();

        System.out.print("请输入需要被替换的单词：");
        String wordOld = input.nextLine();

        System.out.print("请输入替换的单词：");
        String wordNew = input.nextLine();

        String textNew = textOld.replace(wordOld, wordNew);
        System.out.println("替换结果：" + textNew);
        input.close();
    }
}
