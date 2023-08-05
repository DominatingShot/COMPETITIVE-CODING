//not mine
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input vector in non-decreasing order

        if (nums.size() < 3) { // Base case 1: If the vector contains less than three elements, return an empty vector
            return {};
        }

        if (nums[0] > 0) { // Base case 2: If the smallest element in the vector is greater than zero, there can't be any triplet summing to zero
            return {};
        }

        vector<vector<int>> answer; // Initialize the vector to store the triplets

        for (int i = 0; i < nums.size(); ++i) { // Traverse the array to fix the first number in the triplet
            if (nums[i] > 0) { // If the fixed number is positive, stop here because we can't make it zero by searching further
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) { // If the number is repeating, ignore the lower loop and continue to the next number
                continue;
            }

            int low = i + 1, high = nums.size() - 1; // Initialize two pointers 'low' and 'high', and set the sum as 0
            int sum = 0;

            while (low < high) { // Use two-pointer approach to search for the other two numbers in the triplet
                sum = nums[i] + nums[low] + nums[high];

                if (sum > 0) { // If the sum is positive, we need more negative numbers to make it zero, so decrement 'high'
                    high--;
                } else if (sum < 0) { // If the sum is negative, we need more positive numbers to make it zero, so increment 'low'
                    low++;
                } else { // If the sum is zero, we found a triplet
                    answer.push_back({nums[i], nums[low], nums[high]}); // Push the triplet to the answer vector

                    int last_low_occurrence = nums[low];
                    int last_high_occurrence = nums[high];

                    // To avoid duplicate triplets, navigate to the last occurrence of nums[low] and nums[high]
                    while (low < high && nums[low] == last_low_occurrence) {
                        low++;
                    }
                    while (low < high && nums[high] == last_high_occurrence) {
                        high--;
                    }
                }
            }
        }

        return answer; // Return the answer vector containing all unique triplets summing to zero
    }
};
