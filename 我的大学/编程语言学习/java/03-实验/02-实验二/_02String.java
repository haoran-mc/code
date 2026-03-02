// 链接
// https://blog.csdn.net/tjk123456/article/details/77868034

import javax.swing.JOptionPane;

public class _02String {
    public static void main(String[] args) {
        String textOld = JOptionPane.showInputDialog(null, "请输入文本");
        String wordOld = JOptionPane.showInputDialog(null, "请输入需要被替换的单词");
        String wordNew = JOptionPane.showInputDialog(null, "请输入替换的单词");
        String textNew = textOld.replace(wordOld, wordNew);
        JOptionPane.showMessageDialog(null, textNew, "替换结果：", JOptionPane.PLAIN_MESSAGE);
    }
}
