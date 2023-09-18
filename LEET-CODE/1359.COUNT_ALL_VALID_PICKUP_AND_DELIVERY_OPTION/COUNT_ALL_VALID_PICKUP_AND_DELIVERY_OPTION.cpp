class Solution {
    const int MOD = 1e9 + 7; // Define the modulo constant.

public:
    int countOrders(int n) {
        long long count = 1; // Initialize a long long variable to store the count.

        for (int i = 2; i <= n; ++i) {
            // Loop from 2 to n to calculate the count of orders.
            count = (count * (2 * i - 1) * i) % MOD;
            // Update the count by multiplying it with (2i - 1) * i and taking modulo MOD.
        }

        return (int)count; // Return the count as an integer.
    }
};
