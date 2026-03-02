import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Stack;

public class OPGAnalyze {
    public static char ch;   //实验一ch
    public static ArrayList<String> expressions = new ArrayList<>();//所有表达式
    public static String in;
    public static OPGAnalyze opgAnalyze = new OPGAnalyze();

    private Stack<Character> stack = new Stack<Character>(); //符号栈
    private int[][] opgMatrix;  //优先矩阵
    OPGConstruct opgCon;  //构造优先矩阵
    Grammar grammar;  //定义文法

    public OPGAnalyze() {
        grammar = new Grammar();//文法
        opgCon = new OPGConstruct();//优先矩阵
        this.opgMatrix = opgCon.getOPGMatrix();//算符优先矩阵
    }

    public static void main(String[] args) {
        String ex = Word_analyze.readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C++/Semantic_analysis/expression.txt");
        ex = ex.replaceAll("\\s*", "");//删除字符串中所有空格
        Word_analyze.analyze(ex.toCharArray());//词法分析阶段
        opgAnalyze.opgCon.printFirstVt();
        opgAnalyze.opgCon.printLastVt();
        opgAnalyze.opgCon.printOPGMatrix();
        for (String expression : expressions) {
            opgAnalyze.Analyse(expression);
        }
    }

    public void Analyse(String str) {
        str = str + "#";
        char[] chs = str.toCharArray();
        if (opgAnalyze.isRightStr(chs)) {
            System.out.print("\n......................................................\n" + str + ":\n");
            System.out.println(".......................归约过程.......................\n");
            System.out.println("步骤  符号栈  当前符号  移进或归约\n");
            opgAnalyze.checkStr(chs);
        } else {
            System.out.println("出现非本文法内的终结符，不识别.......1");
        }
    }

    //检查是否是本文法规定内的终结符
    public boolean isRightStr(char[] ch) {
        boolean flag = true;
        for (char c : ch) {
            if (grammar.isVt(c) == -1) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    //分析串
    public void checkStr(char[] chs) {
        stack.clear();
        int k = 1, j = 1, i = 0;//k指向栈顶，j指向第一个终结符，i控制读字符
        char ch, top;
        stack.push('#');

        char pt1 = stack.peek();//临时
        int pn1 = stack.size();//临时
        int pnum = 1;
        System.out.print("(" + pnum + ")    ");
        System.out.print("#       ");
        while (i < chs.length) {
            ch = chs[i];//读入一个字符a
            pnum = printReduction(ch, pt1, pn1, pnum);
            top = stack.peek();

            if (grammar.isVt(top) != -1) {//j指向第一个终结符
                j = k;
            } else {
                j = k - 1;
            }
            int X = grammar.isVt(getch(j));
            int Y = grammar.isVt(ch);
            //对于S[j]>a不成立情况
            if ((X != -1) && (Y != -1) && (opgMatrix[X][Y] != 3)) {
                if (opgMatrix[X][Y] != 2) {//对于S[j]<a不成立情况
                    if (opgMatrix[X][Y] != 1) {//对于S[j]=a不成立情况
                        System.out.println("出现不存在的优先关系，不识别.......1");
                        break;
                    } else {
                        int Z = grammar.isVt('#');
                        if (opgMatrix[X][Z] == 1) {//对于S[j]=#情况
                            if (getch(2) == 'W' && getch(1) == '#') {//正常结束
                                System.out.println("分析成功！");
                                break;
                            } else {
                                System.out.println("没有正常结束，不识别.......2");
                                break;
                            }
                        }
                    }
                }
                k = k + 1;
                i = i + 1;
                stack.push(ch);
                System.out.print("移进    \n");
            }
            //对于S[j]>a成立情况
            if ((X != -1) && (Y != -1) && (opgMatrix[X][Y] == 3)) {
                char q = getch(j);
                int M = grammar.isVt(getch(j));
                int N = grammar.isVt(q);
                do {//寻找归约串

                    q = getch(j);
                    M = grammar.isVt(getch(j));
                    N = grammar.isVt(q);
                    if (j > 1 && (grammar.isVt(getch(j - 1)) != -1)) {
                        j = j - 1;
                    } else {
                        if (j > 2) {
                            j = j - 2;
                        }
                    }
                    M = grammar.isVt(getch(j));
                } while ((opgMatrix[M][N] != 2) && (opgMatrix[M][N] != 0));

                if (opgMatrix[M][N] == 2) {//归约
                    int temp = k - j;
                    for (int t = 0; t < temp; t++) {
                        stack.pop();
                    }
                    k = j + 1;
                    stack.push('W');
                    System.out.print("归约    \n");
                } else if (opgMatrix[M][N] == 0) {//不存在的优先关系

                    System.out.println("识别失败！该语句不可被该文法识别！");
                    break;
                }
            }
        }
    }

    //打印归约过程
    public int printReduction(char ch, char pt1, int pn1, int pnum) {
        char pt = stack.peek();
        int pn = stack.size();
        if (pt1 != pt || pn1 != pn) {
            pnum++;
            System.out.print("(" + pnum + ")    ");
            Enumeration<Character> en = stack.elements();
            while (en.hasMoreElements()) {
                System.out.print(en.nextElement());
            }
            for (int q = 0; q < 8 - pn; q++) {
                System.out.print(" ");
            }
        }
        System.out.print(ch + "         ");
        return pnum;
    }

    // 获取栈中第i个元素
    public char getch(int i) {
        return stack.get(i - 1);
    }
}