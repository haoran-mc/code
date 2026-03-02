>> 表达时样例：4+2*3-5/5=
while input_ch等于'=' && stack1 == empty:
    if input_ch 是数字
        push(stack2, input_ch)
        input_ch = getchar()
    else
        if stack1 == empty
            push(stack1, input_ch)
            input_ch = getchar()
        else
            switch 栈顶与input_ch的优先级比较
                case 栈顶优先级高:
                    push(stack1, input_ch)
                    input_ch = getchar()
                    break;
                case 优先级相等:
                    说明是遇到了括号，pop(stack1)
                    input_ch = getchar()
                case 栈顶优先级较低：
                    退栈，theta = pop(stack1),
                    a = pop(stack2),
                    b = pop(stack2)
                    运算救国res = operate(theta, a, b)
                    push(stack2, res);
                    break;

栈顶元素即为结果
