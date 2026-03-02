/*
 * 方法原型：JOptionPane.showInputDialog(null, text, title, value)
 * JOptionPane类可显示可包含文本、按钮等的消息框。
 * JOptionPane.showInputDialog方法返回用户输入的字符串。
 * 显示在输入对话框中的标题、消息及图标等由传递给该方法的参数确定
 * 参数text是要在输入对话框中显示的字符串，参数title是要在输入对话框的标题栏中显示的字符串,参数value为要显示的图标，值为JOptionPane类常量
 * 第1个参数的值为null表示对话框显示在屏幕中央。
 * 下面给大家看一个例子：
 */

import javax.swing.JOptionPane;
public class _02JOptionPane {
    public static void main( String args[] ) {
        String firstNumber;
        String secondNumber;
        int number1 = 0;
        int number2 = 0;
        int product = 0;

        firstNumber  = JOptionPane.showInputDialog(null, "输入乘数");
        secondNumber = JOptionPane.showInputDialog(null, "输入被乘数");
        try {
            number1 = Integer.parseInt(firstNumber);
            number2 = Integer.parseInt(secondNumber);
            product = number1 * number2;
            // JOptionPane.showMessageDialog(null, number1 + " * " + number2 + " = " + product, "运行结果", JOptionPane.PLAIN_MESSAGE);
            JOptionPane.showMessageDialog(null, number1 + " * " + number2 + " = " + product, "运行结果", JOptionPane.INFORMATION_MESSAGE);
        }
        catch(NumberFormatException ex) {
            JOptionPane.showMessageDialog(null, "你在输入对话框中没有输入整数值", "消息", JOptionPane.PLAIN_MESSAGE);
            System.exit( 0 );
        }
        product = number1 * number2;
        System.exit( 0 );
    }
}
