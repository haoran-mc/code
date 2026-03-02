import java.util.Stack;

public class OPGConstruct {
    Grammar grammar = new Grammar();
    private Stack<Integer> stack = new Stack<Integer>(); //临时栈
    private int[][] opgMatrix; //算符优先表
    private int[][] firstVt; //FirstVt集
    private int[][] lastVt;    //LastVt集
    private int row = grammar.lengthVn();  //行
    private int column = grammar.lengthVt();    //列
    private String strForm[] = grammar.getForm();  //获得文法产生式

    public OPGConstruct() {
        opgMatrix = new int[column][column];
        firstVt = new int[row][column];
        lastVt = new int[row][column];
        init(opgMatrix, column);
        init(firstVt, row);
        init(lastVt, row);
        constructOPGMatrix();//构造优先矩阵
    }

    //初始化数组
    private void init(int[][] temp, int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < column; j++) {
                temp[i][j] = 0;
            }
        }
    }

    //打印FirstVt集
    public void printFirstVt() {
        System.out.println(".......................FirstVt集.......................\n");
        for (int i = 0; i < row; i++) {
            System.out.print("FirstVt(" + grammar.getVn(i) + "):");
            for (int j = 0; j < column; j++) {
                if (firstVt[i][j] == 1) {
                    System.out.print(grammar.getVt(j) + " ");
                }
            }
            System.out.println();
        }
    }

    // 打印LastVt集
    public void printLastVt() {
        System.out.println(".......................LastVt集.......................\n");
        for (int i = 0; i < row; i++) {
            System.out.print("LastVt(" + grammar.getVn(i) + "):");
            for (int j = 0; j < column; j++) {
                if (lastVt[i][j] == 1) {
                    System.out.print(grammar.getVt(j) + " ");
                }
            }
            System.out.println();
        }
    }

    // 打印算符优先关系矩阵
    public void printOPGMatrix() {
        System.out.println(".......................算符优先表.......................\n");
        System.out.print("  ");
        for (int i = 0; i < column; i++) {
            System.out.print(grammar.getVt(i) + " ");
        }
        System.out.println();
        for (int i = 0; i < column; i++) {
            System.out.print(grammar.getVt(i) + " ");
            for (int j = 0; j < column; j++) {
                if (opgMatrix[i][j] == 0) {
                    System.out.print("? ");
                } else if (opgMatrix[i][j] == 1) {
                    System.out.print("= ");
                } else if (opgMatrix[i][j] == 2) {
                    System.out.print("< ");
                } else if (opgMatrix[i][j] == 3) {
                    System.out.print("> ");
                }
            }
            System.out.println();
        }
    }

    // flag=true时插入FirstVt集，若为false插入LastVt集；
    //满足条件后入栈，先入非终结符下标，再入终结符下标（vn，vt）
    public void insertStack(boolean flag, int tempVn, int tempVt) {
        if (flag) {
            if (firstVt[tempVn][tempVt] == 0) {
                firstVt[tempVn][tempVt] = 1;
                stack.push(tempVn);
                stack.push(tempVt);
            }
        } else {
            if (lastVt[tempVn][tempVt] == 0) {
                lastVt[tempVn][tempVt] = 1;
                stack.push(tempVn);
                stack.push(tempVt);
            }
        }
    }

    //构建firstVt集
    public void constructFirstVt() {
        char[] chs;
        stack.clear();//清空临时栈
        int tempVn = 0, tempVt = 0;//临时变量
        // 判别每一个产生式
        for (String value : strForm) {
            chs = value.toCharArray();
            // 找到产生式左边字符在vn中的位置
            if (grammar.isVn(chs[0]) != -1) {
                tempVn = grammar.isVn(chs[0]);
            }
            // 形如A→a...
            if (grammar.isVt(chs[2]) != -1) {
                tempVt = grammar.isVt(chs[2]);
                insertStack(true, tempVn, tempVt);
            } else if (chs.length >= 4) {   // 形如A→Ba...
                if ((grammar.isVn(chs[2]) != -1)
                        && (grammar.isVt(chs[3]) != -1)) {
                    tempVt = grammar.isVt(chs[3]);
                    insertStack(true, tempVn, tempVt);
                }
            }
        }
        //形如A→B...
        while (!stack.isEmpty()) {
            tempVt = stack.pop();
            tempVn = stack.pop();
            // 判别每一个产生式
            for (String s : strForm) {
                chs = s.toCharArray();
                // 产生式右边第一个字符是非终结符
                if (grammar.isVn(chs[2]) != -1) {
                    if (tempVn == (grammar.isVn(chs[2]))) {
                        insertStack(true, grammar.isVn(chs[0]), tempVt);
                    }
                }
            }
        }
    }

    //构建LastVt集
    public void constructLastVt() {
        char[] chs;
        stack.clear();//清空临时栈
        int tempVn = 0, tempVt = 0;//临时变量
        int chLength;//暂存每个产生式长度
        for (String value : strForm) {   //判别每一个产生式
            chs = value.toCharArray();
            chLength = chs.length;
            if (grammar.isVn(chs[0]) != -1) {   //找到产生式左边字符在vn中的位置
                tempVn = grammar.isVn(chs[0]);
            }
            if (grammar.isVt(chs[chLength - 1]) != -1) {   //形如A→....a
                tempVt = grammar.isVt(chs[chLength - 1]);
                insertStack(false, tempVn, tempVt);//入栈
            } else if (chs.length >= 4) {   //形如A→.....aB
                if ((grammar.isVn(chs[chLength - 1]) != -1)
                        && (grammar.isVt(chs[chLength - 2]) != -1)) {
                    tempVt = grammar.isVt(chs[chLength - 2]);
                    insertStack(false, tempVn, tempVt);
                }
            }
        }
        //形如A→...B
        while (!stack.isEmpty()) {
            tempVt = stack.pop();
            tempVn = stack.pop();
            for (String s : strForm) {   //判别每一个产生式
                chs = s.toCharArray();
                chLength = chs.length;
                if (grammar.isVn(chs[chLength - 1]) != -1) {   //产生式最后一个字符是非终结符
                    if (tempVn == (grammar.isVn(chs[chLength - 1]))) {
                        insertStack(false, grammar.isVn(chs[0]), tempVt);
                    }
                }
            }
        }
    }

    //构建优先关系矩阵opgMatrix
    //0表示不存在关系，1表示=，2表示<，3表示>
    public void constructOPGMatrix() {
        constructLastVt();
        constructFirstVt();
        char[] chs;
        int chLength;//暂存每个产生式长度
        //判别每一个产生式
        for (String s : strForm) {
            chs = s.toCharArray();
            chLength = chs.length;
            if (chLength > 3) {   // 不考虑A→B这种情况
                for (int j = 2; j <= chLength - 2; j++) {
                    searchEqual(chLength, j, chs);
                    searchSmall(j, chs);
                    searchBig(j, chs);
                }
            }
        }
    }

    //填充opgMatrix中相等的优先关系
    private void searchEqual(int chLength, int j, char[] chs) {
        int X = grammar.isVt(chs[j]);
        int Y = grammar.isVt(chs[j + 1]);
        //形如A→aa
        if ((X != -1) && (Y != -1)) {
            opgMatrix[X][Y] = 1;
        }
        //形如A→aBa
        if (j <= chLength - 3) {
            int L = grammar.isVt(chs[j]);
            int M = grammar.isVn(chs[j + 1]);
            int N = grammar.isVt(chs[j + 2]);
            if ((L != -1) && (M != -1) && (N != -1)) {
                opgMatrix[L][N] = 1;
            }
        }
    }

    //填充opgMatrix中小于的优先关系
    private void searchSmall(int j, char[] chs) {
        //形如A→aB
        int P = grammar.isVt(chs[j]);
        int Q = grammar.isVn(chs[j + 1]);
        if ((P != -1) && (Q != -1)) {
            for (int k = 0; k < column; k++) {
                if (firstVt[Q][k] != 0) {
                    opgMatrix[P][k] = 2;
                }
            }
        }
    }

    //填充opgMatrix中大于的优先关系
    private void searchBig(int j, char[] chs) {
        //形如A→Ba
        int A = grammar.isVn(chs[j]);
        int B = grammar.isVt(chs[j + 1]);
        if ((A != -1) && (B != -1)) {
            for (int k = 0; k < column; k++) {
                if (lastVt[A][k] != 0) {
                    opgMatrix[k][B] = 3;
                }
            }
        }
    }

    //返回优先矩阵
    public int[][] getOPGMatrix() {
        return opgMatrix;
    }
}