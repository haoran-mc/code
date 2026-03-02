import javax.swing.JOptionPane;
public class _04maxiDialog {
    public static void main(String args[]) {
        String firstNumber;
        String secondNumber;
        double number1 = 0;
        double number2 = 0;

        firstNumber  = JOptionPane.showInputDialog(null, "输入数字1");
        secondNumber = JOptionPane.showInputDialog(null, "输入数字2");
        try {
            number1 = Double.parseDouble(firstNumber);
            number2 = Double.parseDouble(secondNumber);
            if (number2 > number1) {
                number1 += number2;
                number2  = number1 - number2;
                number1 -= number2;
            }
            JOptionPane.showMessageDialog(null, number1, "运行结果", JOptionPane.INFORMATION_MESSAGE);
        }
        catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(null, "你在输入对话框中没有输入整数值", "消息", JOptionPane.PLAIN_MESSAGE);
            System.exit(0);
        }
        System.exit(0);
    }
}
