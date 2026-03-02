import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Word_analyze {//词法分析函数
    public static char ch;

    static boolean isKey(String str) {
        String Keys = readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C/Lexical_analysis/keyword.txt");
        String[] KeyWord = Keys.split(",");
        for (int i = 0; i < KeyWord.length; i++) {
            if (KeyWord[i].equals(str))
                return true;
        }
        return false;
    }//判断是否是关键字

    static boolean isLetter(char letter) {
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
            return true;
        else
            return false;
    }//判断是否是字母

    static boolean isDigit(char digit) {
        if (digit >= '0' && digit <= '9')
            return true;
        else
            return false;
    }//判断是否是数字

    static void analyze(char[] chars) {//词法分析
        String judge = "";
        for (int i = 0; i < chars.length; i++) {
            ch = chars[i];
            judge = "";
            if (isLetter(ch)) {
                boolean flag = false;   //判定是不是关键字
                while (isLetter(ch) || isDigit(ch)) {
                    judge += ch;
                    ch = chars[++i];
                    if (isKey(judge)) {
                        System.out.println("<" + judge + ",->");
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    System.out.println("<0," + judge + ">");
                }
                i--;    //退格
            } else if (isDigit(ch)) {
                if (ch == '0') {
                    if (chars[i + 1] == 'x') {
                        judge = "0x";
                        i += 2;
                        ch = chars[i];
                        while (isDigit(ch) || ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f') {
                            judge = judge + ch;
                            ch = chars[++i];
                        }
                        System.out.println("<3," + judge + ">");
                        i--;
                    }//十六进制数
                    else {
                        while (isDigit(ch)) {
                            judge = judge + ch;
                            ch = chars[++i];
                        }
                        System.out.println("<2," + judge + ">");
                        i--;
                    }//八进制数
                } else {
                    while (isDigit(ch)) {
                        judge = judge + ch;
                        ch = chars[++i];
                    }
                    System.out.println("<1," + judge + ">");
                    i--;
                }
            } else switch (ch) {//运算符和界符
                case '+':
                    System.out.println("<+,->");
                    break;
                case '-':
                    System.out.println("<-,->");
                    break;
                case '*':
                    System.out.println("<*,->");
                    break;
                case '/':
                    System.out.println("</,->");
                    break;
                case '(':
                    System.out.println("<(,->");
                    break;
                case ')':
                    System.out.println("<),->");
                    break;
                case ';':
                    System.out.println("<;,->");
                    break;
                case '=': {
                    ch = chars[++i];
                    if (ch == '=') System.out.println("<==,->");
                    else {
                        System.out.println("<=,->");
                        i--;
                    }               //判定连等号
                }
                break;
                case '>': {
                    ch = chars[++i];
                    if (ch == '=') System.out.println("<>=,->");
                    else {
                        System.out.println("<>,->");
                        i--;
                    }               //判定大于等于/大于
                }
                break;
                case '<': {
                    ch = chars[++i];
                    if (ch == '=') System.out.println("<<=,->>");
                    else {
                        System.out.println("<<,->>");
                        i--;
                    }
                }
                break;
                default: {
                    System.out.println("该词法识别不出 " + ch + " 此字符");
                }
            }                   //判定小于等于/小于
        }
    }

    public static void main(String[] args) {//主函数
        String program = readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C/Lexical_analysis/program.c");
        program = program.replaceAll("\\s*", "");//删除字符串中所有空格
        analyze(program.toCharArray());
    }

    // 实验中利用了一个文件读取函数读取文件中的内容（在之后多次实验也有利用到）：
    public static String readFileContent(String fileName) {
        File file = new File(fileName);
        BufferedReader reader = null;
        StringBuffer bf = new StringBuffer();
        try {
            reader = new BufferedReader(new FileReader(file));
            String tempStr;
            while ((tempStr = reader.readLine()) != null) {
                bf.append(tempStr);
            }
            reader.close();
            return bf.toString();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }
        }
        return bf.toString();
    }
}
