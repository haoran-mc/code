import java.util.ArrayList;

public class Recursive_descent_analysis {
    static String expression;   // 输入的表达式
    static Character sym;   // 当前的符号
    static int index;   // 当前指针
    static boolean hasErr;   // 出错判断

    public static void main(String[] main) {
        String ex = Word_analyze.readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C/Syntax_analysis/expression.txt");
        // ex = ex.replaceAll("\\s*", "");   // 删除字符串中所有空格
        if (!Word_analyze.analyze(ex.toCharArray()))   // 词法分析阶段
            System.out.println("词法分析失败！");
        else {
            for (int i = 0; i < Word_analyze.expressions.size(); i++) {
                System.out.print("(" + (i + 1) + ")输出：");
                expression = Word_analyze.expressions.get(i);
                expression = String.format("%s#", expression);
                index = -1;
                hasErr = false;

                advance();
                E();

                if (hasErr) {
                    error();
                } else if (sym == '#') {
                    correct();
                } else {
                    error();
                }
            }
        }
    }

    // E()
    public static void E() {
        T();
        C();
    }

    // E'()
    public static void C() {
        if (sym == '+') {
            advance();
            T();
            C();
        }
    }

    // T()
    public static void T() {
        F();
        G();
    }

    // T'()
    public static void G() {
        if (sym == '*') {
            advance();
            F();
            G();
        }
    }

    // F()
    public static void F() {
        if (sym == 'i')
            advance();
        else {
            if (sym == '(') {
                advance();
                E();
                if (sym == ')') {
                    advance();
                } else {
                    hasErr = true;
                }
            } else {
                hasErr = true;
            }
        }
    }

    //把指针向前进一步
    public static void advance() {
        index++;
        sym = expression.charAt(index);
    }

    //出错处理
    public static void error() {
        System.out.println("错误");
    }

    public static void correct() {
        System.out.println("正确");
    }
}