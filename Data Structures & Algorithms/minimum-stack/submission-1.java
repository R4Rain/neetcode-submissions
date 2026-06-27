class MinStack {
    Stack<Integer> order;
    Stack<Integer> min_stack;

    public MinStack() {
        order = new Stack<>();
        min_stack = new Stack<>();
    }
    
    public void push(int val) {
        if (min_stack.isEmpty() || val <= min_stack.peek()) {
            min_stack.push(val);
        }
        order.push(val);
    }
    
    public void pop() {
        int top = order.pop();

        if (top == min_stack.peek()) {
            min_stack.pop();
        }
    }
    
    public int top() {
        return order.peek();
    }
    
    public int getMin() {
        return min_stack.peek();
    }
}
