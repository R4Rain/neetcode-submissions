class MinStack {
public:
    stack<int> order;
    stack<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
        order.push(val);
    }
    
    void pop() {
        int top = order.top();
        order.pop();

        if (!min_stack.empty() && top == min_stack.top()) {
            min_stack.pop();
        }
    }
    
    int top() {
        return order.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
