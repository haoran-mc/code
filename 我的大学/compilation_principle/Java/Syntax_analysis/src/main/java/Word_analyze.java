import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

// 词法分析类
public class Word_analyze {
    public static char ch;
    public static String expression = "";
    public static ArrayList<String> expressions = new ArrayList<>();   // 所有表达式

    // 判断是否是字母
    static boolean isLetter(char letter) {
        return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
    }

    // 判断是否是数字
    static boolean isDigit(char digit) {
        return digit >= '0' && digit <= '9';
    }

    // 词法分析
    static boolean analyze(char[] chars) {
        for (int i = 0; i < chars.length; i++) {
            ch = chars[i];

            if (isLetter(ch)) {   // 遇到标识符
                while (isLetter(ch) || isDigit(ch)) {
                    ch = chars[++i];
                }
                expression = String.format("%s%c", expression, 'i');
                i--;
            } else if (isDigit(ch)) {   // 遇到数字
                while (isDigit(ch)) {
                    ch = chars[++i];
                }
                if (isLetter(ch)) {   // 标识符不能以数字开头，返回错误
                    return false;
                }
                expression = String.format("%s%c", expression, 'i');
                i--;
            } else if (ch == '(' || ch == ')' || ch == '+' || ch == '*') {
                expression = String.format("%s%c", expression, ch);
            } else if (ch == ';') {
                expressions.add(expression);
                expression = "";
            }
            // 不会关注空格符、回车符
        }
        return true;
    }

    public static String readFileContent(String fileName) {
        File file = new File(fileName);
        BufferedReader reader = null;
        StringBuilder bf = new StringBuilder();
        try {
            reader = new BufferedReader(new FileReader(file));
            String tempStr;
            while ((tempStr = reader.readLine()) != null) {
                bf.append(tempStr);
                bf.append("\n");
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
