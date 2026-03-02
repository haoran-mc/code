package prac;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Data {
    public static void main(String[] args) {
        DataPanel dataPanel = new DataPanel();
    }
}

class DataPanel extends JFrame {
    private JTextField input = new JTextField();
    private JTextField output = new JTextField();
    private JPanel panel = new JPanel();
    private JButton btnConfirm = new JButton("确定");
    private JLabel lbInput = new JLabel("输入数字");
    private JLabel lbOutput = new JLabel("星期几");
    private int dayNumber;
    private String dayName;

    public DataPanel() {
        this.setTitle("日子数与星期几转换");
//        this.setLayout(null);
        this.setVisible(true);
        panel.setLayout(null);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        this.setBounds(1000, 500, 300, 200);
        lbInput.setBounds(20, 20, 50, 30);
        lbOutput.setBounds(20, 60, 50, 30);
        input.setBounds(80, 20, 180, 30);
        output.setBounds(80, 60, 180, 30);
        btnConfirm.setBounds(115, 105, 70, 35);

        panel.add(lbInput);
        panel.add(lbOutput);
        panel.add(input);
        panel.add(output);
        panel.add(btnConfirm);

        this.add(panel);

        btnConfirm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                output.setText("");
                try {
                    dayNumber = Integer.parseInt(input.getText());
                    dayName = getDayName(dayNumber);
                    // 代码5  在控件dayNameField中输出结果
                    output.setText(dayName);
                } catch (BadDataException ex) {
                    JOptionPane.showMessageDialog(DataPanel.this, ex.toString(), "无效日期", JOptionPane.WARNING_MESSAGE);
                } catch (NumberFormatException ex) {
                    System.out.println("I detected Exception " + ex.toString());
                }
            }
        });
    }

    public String getDayName(int dayNumber) throws BadDataException {
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
}
