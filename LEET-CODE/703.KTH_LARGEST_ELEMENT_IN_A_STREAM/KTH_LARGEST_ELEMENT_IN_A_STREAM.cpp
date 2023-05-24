#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    // Declare a priority queue with min-heap property
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz; // Variable to store the value of k

    // Constructor to initialize the class with k and nums
    KthLargest(int k, vector<int>& nums) {
        sz = k; // Assign k to sz

        // Add each element from nums to the priority queue
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
    }

    // Method to add a new value to the priority queue
    int add(int val) {
        pq.push(val); // Add the new value to the priority queue

        // If the size of the priority queue exceeds k, remove the smallest element
        while (pq.size() > sz) {
            pq.pop();
        }

        return pq.top(); // Return the current kth largest element
    }
};
