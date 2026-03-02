import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Forecast_analysis {
    static List<String> noTerminal = new ArrayList<>();   // 非终结符集
    static List<String> terminal = new ArrayList<>();   // 终结符集
    static String[][] grammarRules;   // 语法规则存储
    static String[][] noLeftRecursiveGrammarRules;   // 消除左递归后语法规则存储
    static String[][] newGrammar;
    static String init;   // 文法开始符号
    static String[][] firstSet;   // FIRST集
    static String[][] followSet;   // FOLLOW集
    static int[][] analysis;   // LL(1)分析表
    static Scanner input = new Scanner(System.in);
    private static final int MAX_GRAMMAR = 570;

    public static void inputNoTerminalSymbols() {
        // 读入非终结符
        System.out.println("请输入非终结符: ");
        // String noTer = input.nextLine();
        String noTer = "ETFCG";
        for (int i = 0; i < noTer.length(); i++) {
            noTerminal.add(String.valueOf(noTer.charAt(i)));
        }
    }

    public static void inputTerminalSymbols() {
        terminal.add("#");
        System.out.println("请输入终结符: ");
        // String ter = input.nextLine();
        String ter = "()i+*-";
        for (int i = 0; i < ter.length(); i++) {
            terminal.add(String.valueOf(ter.charAt(i)));
        }
    }

    public static void inputGrammarRules() {
        System.out.println("请输入语法规则：");
        String grammar = input.nextLine();
        init = String.valueOf(grammar.charAt(0));
        do {
            divide(grammar);
            eliminate(grammar);
            grammar = input.nextLine();
        } while (!grammar.equals(""));
    }

    static void divide(String grammar) {
        int fla = grammar.indexOf("|");
        int flag = grammar.indexOf(">");
        String a = String.valueOf(grammar.charAt(0));
        if (fla != -1) {
            grammarRules[noTerminal.indexOf(a)][0] = grammar.substring(flag + 1, fla);
            grammarRules[noTerminal.indexOf(a)][1] = grammar.substring(fla + 1);
        } else {
            grammarRules[noTerminal.indexOf(a)][0] = grammar.substring(flag + 1);
        }
    }

    // 消除左递归
    static void eliminate(String grammar) {
        int fla = grammar.indexOf("|");
        int flag = grammar.indexOf(">");
        // 如果存在左递归
        if (grammar.charAt(0) == grammar.charAt(flag + 1)) {
            String a = String.valueOf(Character.toLowerCase(grammar.charAt(0)));
            noTerminal.add(a);
            if (!terminal.contains("-")) {
                terminal.add("-");
            }
            String s = "";
            for (int i = flag; i < grammar.length(); i++) {
                s = String.valueOf(grammar.charAt(i));
                flag = terminal.indexOf(s);
                if (flag != -1) {
                    flag = grammar.indexOf(s);
                    break;
                }
            }
            s = s + grammar.substring(flag + 1, fla) + a;
            noLeftRecursiveGrammarRules[noTerminal.indexOf(a)][0] = s;
            noLeftRecursiveGrammarRules[noTerminal.indexOf(a)][1] = "-";
            noLeftRecursiveGrammarRules[noTerminal.indexOf(String.valueOf(grammar.charAt(0)))][0] = grammar.substring(fla + 1) + a;
        } else {
            noLeftRecursiveGrammarRules[noTerminal.indexOf(String.valueOf(grammar.charAt(0)))][0] = grammarRules[noTerminal.indexOf(String.valueOf(grammar.charAt(0)))][0];
            noLeftRecursiveGrammarRules[noTerminal.indexOf(String.valueOf(grammar.charAt(0)))][1] = grammarRules[noTerminal.indexOf(String.valueOf(grammar.charAt(0)))][1];
        }
    }

    static void output(String[][] array) {
        int k = 0;
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                if (array[i][j] != null) {
                    newGrammar[k][0] = String.valueOf(k + 1);
                    newGrammar[k][1] = noTerminal.get(i);
                    newGrammar[k][2] = array[i][j];
                    System.out.println(newGrammar[k][0] + "     " + newGrammar[k][1] + "     " + newGrammar[k][2]);
                    k++;
                }
            }
        }
    }

    static void first(String noTer) {
        int flag = noTerminal.indexOf(noTer);
        for (int i = 0; i < 2; i++) {
            if (noLeftRecursiveGrammarRules[flag][i] != null) {
                String str = noLeftRecursiveGrammarRules[flag][i];
                String initials = String.valueOf(str.charAt(0));
                if (noTerminal.contains(initials)) {
                    first(initials);
                    for (int j = 0; j < terminal.size(); j++) {
                        int temp = noTerminal.indexOf(initials);
                        if (firstSet[temp][j] != null) {
                            firstSet[flag][j] = firstSet[temp][j];
                        }
                    }
                } else {
                    firstSet[flag][terminal.indexOf(initials)] = String.valueOf(str.charAt(0));
                }
            }
        }
    }

    static void follow(String noTer) {
        for (int i = 0; i < noTerminal.size(); i++) {
            for (int j = 0; j < 2; j++) {
                if (noLeftRecursiveGrammarRules[i][j] != null) {
                    String str = noLeftRecursiveGrammarRules[i][j];
                    //文法开始符号
                    if (noTer.equals(init)) {
                        followSet[noTerminal.indexOf(init)][terminal.indexOf("#")] = "#";
                    }
                    int index = str.indexOf(noTer);
                    //noTer不在最后位置
                    if (index != -1 && index != str.length() - 1) {
                        String ch = String.valueOf(str.charAt(index + 1));
                        //ch是非终结符
                        if (noTerminal.contains(ch)) {
                            for (int k = 0; k < terminal.size(); k++) {
                                if (firstSet[noTerminal.indexOf(ch)][k] != null && !firstSet[noTerminal.indexOf(ch)][k].equals("-")) {
                                    followSet[noTerminal.indexOf(noTer)][k] = firstSet[noTerminal.indexOf(ch)][k];
                                    for (int l = 0; l < terminal.size(); l++) {
                                        if (followSet[i][l] != null) {
                                            followSet[noTerminal.indexOf(noTer)][l] = followSet[i][l];
                                        }
                                    }
                                }
                            }
                        } else {
                            //ch不是非终结符
                            followSet[noTerminal.indexOf(noTer)][terminal.indexOf(ch)] = ch;
                        }
                    } else if (index > 0 && index == str.length() - 1) {
                        //noTer在最后位置，防止死循环
                        if (!noTerminal.get(i).equals(noTer)) {
                            follow(noTerminal.get(i));
                            for (int k = 0; k < terminal.size(); k++) {
                                if (followSet[i][k] != null) {
                                    followSet[noTerminal.indexOf(noTer)][k] = followSet[i][k];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    static void table() {
        int index = 0;
        for (int i = 0; i < noTerminal.size(); i++) {
            int num = 0, temp = 0;
            int[] flag = new int[terminal.size()];
            for (int j = index; j < newGrammar.length; j++) {
                if (newGrammar[index][1].equals(newGrammar[j][1])) {
                    flag[temp] = Integer.parseInt(newGrammar[j][0]);
                    num++;
                    temp++;
                }
            }
            index += num;
            if (num == 1) {
                for (int j = 0; j < firstSet[i].length; j++) {
                    if (firstSet[i][j] != null) {
                        analysis[i][j] = flag[0];
                    }
                }
            } else {
                temp = 0;
                for (int j = 0; j < firstSet[i].length; j++) {
                    if (firstSet[i][j] != null) {
                        if (!firstSet[i][j].equals("-")) {
                            analysis[i][j] = flag[temp];
                            temp++;
                        } else {
                            for (int f = 0; f < followSet[i].length; f++) {
                                if (followSet[i][f] != null) {
                                    analysis[i][f] = flag[temp];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    static void analysisStack(String test) {
        List<String> stack = new ArrayList<>();
        stack.add("#");
        stack.add("E");
        String outStack = test + "#";
        while (true) {
            String inStack = "";
            for (String value : stack) {
                inStack = String.format("%s%s", inStack, value);
            }
            System.out.println(String.format("%-10s", inStack) + String.format("%-10s", outStack));
            String NT = stack.get(stack.size() - 1);
            String T = String.valueOf(outStack.charAt(0));
            if (NT.equals(T) && NT.equals("#")) {
                System.out.println("分析成功");
                break;
            } else if (NT.equals(T)) {
                stack.remove(stack.size() - 1);
                outStack = outStack.substring(1);
            } else {
                if (!noTerminal.contains(NT) || !terminal.contains(T)) {
                    System.out.println("ERROR: 分析出错");
                    break;
                }
                if (analysis[noTerminal.indexOf(NT)][terminal.indexOf(T)] > 0) {
                    int num = analysis[noTerminal.indexOf(NT)][terminal.indexOf(T)];
                    String s = newGrammar[num - 1][2];
                    stack.remove(stack.size() - 1);
                    for (int i = s.length() - 1; i >= 0; i--) {
                        if (!s.equals("-")) {
                            stack.add(String.valueOf(s.charAt(i)));
                        }
                    }
                } else {
                    System.out.println("ERROR: 分析出错");
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        String ex = Word_analyze.readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C/Syntax_analysis/expression.txt");
        ex = ex.replaceAll("\\s*", "");    // 删除字符串中所有空格
        Word_analyze.analyze(ex.toCharArray());   // 词法分析阶段

        inputNoTerminalSymbols();   // 输入非终结符
        inputTerminalSymbols();   // 输入终结符

        // 初始化
        grammarRules = new String[MAX_GRAMMAR][2];
        noLeftRecursiveGrammarRules = new String[MAX_GRAMMAR * 2][2];
        newGrammar = new String[noTerminal.size() * 5][3];

        inputGrammarRules();   // 输入语法规则

        System.out.println(grammarRules);

        for (int k = 0; k < Word_analyze.expressions.size(); k++) {
            String test = Word_analyze.expressions.get(k);
            //输出信息
            System.out.println("------------------基本信息-----------------------");
            System.out.println("产生式：");
            output(grammarRules);
            System.out.println("终结符：");
            for (String s : terminal) {
                System.out.print(s + "     ");
            }
            System.out.println();
            System.out.println("非终结符：");
            for (String s : noTerminal) {
                System.out.print(s + "     ");
            }
            System.out.println();
            System.out.println("读取测试：");
            System.out.println(test);
            System.out.println("-------------------消除左递归---------------------");
            System.out.println("产生式：");
            output(noLeftRecursiveGrammarRules);
            System.out.println("----------------FIRST集和FOLLOW集-----------------");
            firstSet = new String[noTerminal.size()][terminal.size()];
            for (int i = 0; i < noTerminal.size(); i++) {
                first(noTerminal.get(i));
                System.out.print("FIRST(" + noTerminal.get(i) + ") = ");
                for (int j = 0; j < terminal.size(); j++) {
                    if (firstSet[i][j] != null) {
                        System.out.print(firstSet[i][j] + " ");
                    }
                }
                System.out.println();
            }
            followSet = new String[noTerminal.size()][terminal.size()];
            for (int i = 0; i < noTerminal.size(); i++) {
                follow(noTerminal.get(i));
                System.out.print("FOLLOW(" + noTerminal.get(i) + ") = ");
                for (int j = 0; j < terminal.size(); j++) {
                    if (followSet[i][j] != null) {
                        System.out.print(followSet[i][j] + " ");
                    }
                }
                System.out.println();
            }
            System.out.println("----------------LL(1)分析表-----------------");
            analysis = new int[noTerminal.size()][terminal.size()];
            table();
            System.out.print("      ");
            for (String s : terminal) {
                System.out.print(s + "     ");
            }
            System.out.println();
            for (int i = 0; i < noTerminal.size(); i++) {
                System.out.print(noTerminal.get(i) + "     ");
                for (int j = 0; j < terminal.size(); j++) {
                    if (analysis[i][j] != 0) {
                        System.out.print(analysis[i][j] + "     ");
                    } else {
                        System.out.print("      ");
                    }
                }
                System.out.println();
            }
            System.out.println("--------------------分析栈-------------------");
            System.out.println(String.format("%-10s", "分析栈") + String.format("%-10s", "剩余字符串"));
            analysisStack(test);
        }
    }
}