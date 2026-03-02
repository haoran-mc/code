class MinStack {
    public:
        stack<int> stk, stk_min;

        MinStack() {
        }

        void push(int x) {
            stk.push(x);
            if (stk_min.size())
                x = min(x, stk_min.top());
            stk_min.push(x);
        }

        void pop() {
            stk.pop();
            stk_min.pop();
        }

        int top() {
            return stk.top();
        }

        int getMin() {
            return stk_min.top();
        }
};
