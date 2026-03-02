public class Stack {
    private int maxSize;
    public String[] stackArray;
    public int top;

    public Stack(int s) {
        maxSize = s;
        stackArray = new String[maxSize];
        top = 0;
    }

    public void push(String j) {
        stackArray[top++] = j;
    }

    public String pop() {
        return stackArray[--top];
    }

    public String peek() {
        return stackArray[top - 1];
    }//返回栈顶元素
}
