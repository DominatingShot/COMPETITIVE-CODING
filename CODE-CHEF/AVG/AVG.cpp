#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases.
    
    while (t--) {
        int n, k, v;
        cin >> n >> k >> v; // Read values for n, k, and v.
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x; // Read the input values one by one.
            sum += x; // Calculate the sum of input values.
        }
        
        int ans = (v * (n + k) - sum) / k; // Calculate the answer using the formula.
        
        if (ans > 0 && (v * (n + k) - sum) % k == 0) {
            cout << ans << endl; // If ans is positive and the remainder is 0, print the answer.
        } else {
            cout << "-1" << endl; // Otherwise, print -1.
        }
    }
    
    return 0;
}
