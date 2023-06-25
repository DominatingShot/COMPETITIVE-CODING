class MinStack {
    Stack<Integer> stack; // Stack to store the elements of the stack
    Stack<Integer> minStack; // Stack to store the minimum elements of the stack

    public MinStack() {
        stack = new Stack<>(); // Initializing the main stack
        minStack = new Stack<>(); // Initializing the minimum stack
    }

    public void push(int val) {
        stack.add(val); // Adding the value to the main stack

        if (minStack.isEmpty() || minStack.peek() >= val)
            minStack.add(val); // If the minimum stack is empty or the new value is smaller, add the value to the minimum stack
        else
            minStack.add(minStack.peek()); // If the new value is not smaller, duplicate the current minimum value in the minimum stack
    }

    public void pop() {
        stack.pop(); // Removing the top element from the main stack
        minStack.pop(); // Removing the corresponding minimum value from the minimum stack
    }

    public int top() {
        return stack.peek(); // Returning the top element of the main stack
    }

    public int getMin() {
        return minStack.peek(); // Returning the current minimum value from the minimum stack
    }
}
