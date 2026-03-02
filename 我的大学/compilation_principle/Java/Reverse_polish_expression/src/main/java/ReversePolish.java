import java.io.BufferedReader;
        import java.io.File;
        import java.io.FileReader;
        import java.io.IOException;


public class ReversePolish {
    public static void main(String[] args) {
        String expression = readFileContent("/home/haoran/haoran/Code/Major/Compilation_principle/C/Syntax_analysis/expression.txt");
        String[] expressions = expression.split(";");
        System.out.println("本系统支持的运算符:+、-、*、(、)");
        for(int i=0;i<expressions.length;i++){
            System.out.println("("+(i+1)+")"+expressions[i]+";");
            System.out.print("输出:");
            ReversePolish(expressions[i]);
        }

    }

    public static void ReversePolish(String e){
        e=e+"#";//加上一个判断符
        Stack s1 = new Stack(e.length()+1);//存储符号
        Stack s2 = new Stack(e.length()+1);//存储逆波兰式
        s1.push("#");
        for(int i=0;i<e.length();i++){//从左到右遍历表达式
            char c=e.charAt(i);
            if(isDigit(c)){
                int p=i;
                while (isDigit(e.charAt(p))){p++;}
                s2.push(e.substring(i,p));
                i=p-1;
            }
            else if(isFuHao(c)){
                if(c=='(')
                    s1.push(c+"");
                else if(c==')'){
                    while (!s1.peek().equals("(")){
                        s2.push(s1.pop());
                    }
                    s1.pop();//抛弃'('
                }
                else if(c=='#'){
                    while (!s1.peek().equals("#"))
                        s2.push(s1.pop());
                }
                else{//其他符号
                    if(s1.peek().equals("("))
                        s1.push(c+"");
                    else {
                        if(Fuhao(c+"")>Fuhao(s1.peek())){
                            s1.push(c+"");
                        }
                        else {
                            while(Fuhao(c+"")<=Fuhao(s1.peek())){
                                s2.push(s1.pop());
                            }
                            s1.push(c+"");
                        }
                    }
                }
            }
            else{
                System.out.print("您输入的表达式不符合规范！\n");
                return;
            }
        }
        for(int i=0;i<s2.top;i++){
            System.out.print(s2.stackArray[i]+",");
        }//打印逆波兰式
        System.out.print("\b\n");
    }//逆波兰式的生成算法

    public static boolean isDigit(char c){
        if('0'<=c&&c<='9')
            return true;
        else return false;
    }//判断是否是操作数

    public static boolean isFuHao(char c){
        if(c=='+'||c=='-'||c=='*'||c=='('||c==')'||c=='#')
            return true;
        else return false;
    }//判断是否是符号

    public static int Fuhao(String fh){
        switch(fh){
            case "#":return 0;
            case "(":return 1;
            case "+":
            case "-":
                return 2;
            case "*":return 3;
            case ")":return 4;
            default:return -1;
        }
    }//判断符号优先级的,优先级低的数字小

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
    }//读取文件内容
}