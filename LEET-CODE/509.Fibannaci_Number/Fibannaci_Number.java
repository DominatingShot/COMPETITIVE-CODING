class Solution {
    public int fib(int n) {
        // Base case: If n is 0, return 0
        if (n == 0) {
            return 0;
        }
        // Base case: If n is 1, return 1
        if (n == 1) {
            return 1;
        }
        // Recursive case: Calculate the Fibonacci number by summing the two preceding ones
        else {
            return fib(n - 1) + fib(n - 2);
        }
    }
}
