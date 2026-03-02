public class Grammar {
    private char vn[] = {'S', 'E', 'T', 'F'};  //非终结符
    private char vt[] = {'+', '*', 'i', '(', ')', '#'};    //终结符
    private String strForm[] = {"S→#E#", "E→E+T", "E→T", "T→T*F", "T→F", "F→(E)", "F→i"};//文法的产生式

    //判断一个字符是否是Vt中的字母,是返回其在Vt中位置，否则返回-1
    public int isVt(char ch) {
        int temp = 0, i;
        for (i = 0; i < vt.length; i++) {
            if (ch == vt[i]) {
                temp = i;
                break;
            }
        }
        if (i >= vt.length) {
            return -1;
        } else return temp;
    }

    //判断一个字符是否是Vn中的字母,是返回其在Vn中位置，否则返回-1
    public int isVn(char ch) {
        int temp = 0, i;
        for (i = 0; i < vn.length; i++) {
            if (ch == vn[i]) {
                temp = i;
                break;
            }
        }
        if (i >= vn.length) {
            return -1;
        } else return temp;
    }

    //返回终结符的个数
    public int lengthVt() {
        return vt.length;
    }

    //返回非终结符的个数
    public int lengthVn() {
        return vn.length;
    }

    //返回文法产生式
    public String[] getForm() {
        return strForm;
    }

    //返回Vt中第i个字符
    public char getVt(int i) {
        char ch = ' ';
        if (i >= 0 && i < vt.length) {
            ch = vt[i];
        }
        return ch;
    }

    //返回Vn中第i个字符
    public char getVn(int i) {
        char ch = ' ';
        if (i >= 0 && i < vn.length) {
            ch = vn[i];
        }
        return ch;
    }
}