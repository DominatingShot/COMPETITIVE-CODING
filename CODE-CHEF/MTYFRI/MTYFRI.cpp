#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases.

    while (t--) { // Loop through each test case.
        int n, k;
        cin >> n >> k; // Read the size of the lists and maximum swaps allowed.

        vector<int> v1, v2; // Create two vectors to represent the two teams.

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (j % 2 == 0)
                v1.push_back(x); // Push even-indexed elements into v1.
            else
                v2.push_back(x); // Push odd-indexed elements into v2.
        }

        sort(v1.rbegin(), v1.rend()); // Sort v1 in descending order (to maximize).
        sort(v2.begin(), v2.end());   // Sort v2 in ascending order (to minimize).

        int minsize = min(v1.size(), v2.size()); // Calculate the minimum size between v1 and v2.

        int least = min(minsize, k); // Determine the number of swaps to perform (minimum of minsize and k).

        for (int j = 0; j < least; j++) {
            if (v1[j] > v2[j]) {
                swap(v1[j], v2[j]); // Swap elements between v1 and v2 if v1[j] > v2[j].
            } else {
                break; // Break the loop if no more swaps can be made to maximize.
            }
        }

        int sum1 = accumulate(v1.begin(), v1.end(), 0); // Calculate the sum of elements in v1.
        int sum2 = accumulate(v2.begin(), v2.end(), 0); // Calculate the sum of elements in v2.

        if (sum2 > sum1) {
            cout << "YES" << endl; // If sum2 is greater than sum1, it's possible to maximize.
        } else {
            cout << "NO" << endl; // Otherwise, it's not possible to maximize.
        }
    }

    return 0;
}
