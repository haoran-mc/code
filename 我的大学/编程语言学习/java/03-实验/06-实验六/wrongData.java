package prac;


import java.awt.*; // Container, GridLayout
import java.awt.event.*; // ActionListener
import javax.swing.*;

public class wrongData extends JFrame {
    private JTextField dayNumberField, dayNameField;
    private int dayNumber;
    private String dayName;
    private JButton btnConfirm;
    private JPanel panel;

    public wrongData() {
        super("数字在1-7");
        Container container = getContentPane();
        container.setLayout(new GridLayout(2, 2));
        container.add(new JLabel("输入数字 ", SwingConstants.RIGHT));
        // 代码2 创建一个JTextField控件 dayNumberField
        dayNumberField = new JTextField(10);
        container.add(dayNumberField);
//        dayNumberField.addActionListener(this);
        container.add(new JLabel("星期几 ", SwingConstants.RIGHT));
        dayNameField = new JTextField(10);
        // 代码3 将控件dayNameField 加入到容器中
        container.add(dayNumberField);

        // 代码4 设置窗口的大小为 （425，100）
        setSize(425, 100);
        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent event) {
        dayNameField.setText("");
        try {
            dayNumber = Integer.parseInt(dayNumberField.getText());
            dayName = getDayName(dayNumber);
            // 代码5  在控件dayNameField中输出结果
            dayNameField.setText(dayName);
        } catch (BadDataException ex) {
            JOptionPane.showMessageDialog(wrongData.this, ex.toString(), "无效日期", JOptionPane.WARNING_MESSAGE);
        } catch (NumberFormatException ex) {
            System.out.println("I detected Exception " + ex.toString());
        }
    }

    public String getDayName(int dayNumber) throws BadDataException {
        // 代码6      此处加入switch 语句块以根据输入值dayNumber 判断星期几，
        //    并在default处Throw抛出BadDataException异常
        switch (dayNumber) {
            case 1:
                return "星期一";
            case 2:
                return "星期二";
            case 3:
                return "星期三";
            case 4:
                return "星期四";
            case 5:
                return "星期五";
            case 6:
                return "星期六";
            case 7:
                return "星期日";
            default:
                throw new BadDataException(dayNumber);
        }

    }

    public static void main(String args[]) {
        wrongData application = new wrongData();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

}

class BadDataException extends RuntimeException {
    public BadDataException() {
    }

    public BadDataException(int dayNumber) throws BadDataException {
        if (dayNumber < 1 || dayNumber > 7)
            throw new BadDataException();
    }

    public String toString() {
        return "转换数字必须在1至7之间!";
    }
}
