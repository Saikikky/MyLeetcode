class MinStack {

    private Stack<Integer> data;
    private Stack<Integer> min;

    /** initialize your data structure here. */
    public MinStack() {
        data = new Stack<>();
        min = new Stack<>();
    }

    public void push(int x) {
        data.add(x);
        if (min.isEmpty() || min.peek() >= x) {
            min.add(x);
        } else {
            min.add(min.peek());
        }
    }

    public void pop() {
        if (!data.isEmpty()) {
            data.pop();
            min.pop();
        }
    }

    public int top() {
        if (!data.isEmpty()) {
            return data.peek();
        }
        throw new RuntimeException("栈元素为空");
    }

    public int getMin() {
        if (!min.isEmpty()) {
            return min.peek();
        }
        throw new RuntimeException("栈元素为空");
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */