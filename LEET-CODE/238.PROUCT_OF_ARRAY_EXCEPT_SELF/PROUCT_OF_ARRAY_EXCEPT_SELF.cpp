class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Create a vector 'ans' to store the product of all elements to the left of the current element
        // Initialize each element of 'ans' to 1
        vector<int> ans(nums.size(), 1);
        
        // 'curr' will keep track of the product of all elements to the left of the current element
        int curr = 1;
        
        // Calculate the product of all elements to the left of the current element and store in 'ans'
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = curr * nums[i - 1];
            curr = ans[i]; // Update 'curr' for the next iteration
        }
        
        // Reset 'curr' to 1 to calculate the product of all elements to the right of the current element
        curr = 1;
        
        // Calculate the product of all elements to the right of the current element
        // and also update the 'nums' vector to store the product of all elements to the right of each element
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] *= nums[i + 1]; // Update 'ans' to include the product of elements to the right
            nums[i] *= nums[i + 1]; // Update 'nums' to store the product of elements to the right
        }
        
        // 'ans' now contains the product of all elements except the element at the current index.
        // The 'nums' vector also stores the product of all elements to the right of each element.
        return ans; // Return the 'ans' vector as the final result.
    }
};
