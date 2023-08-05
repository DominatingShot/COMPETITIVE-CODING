class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); // Get the number of children (ratings size).
        int candy = n; // Start with assigning one candy to each child (minimum).
        int i = 1; // Initialize a pointer to traverse the ratings array.

        while (i < n) { // Traverse the ratings array.
            if (ratings[i] == ratings[i - 1]) { // If the current rating is equal to the previous one, just continue to the next child.
                i++;
                continue;
            }

            int peak = 0; // Initialize variables to track peak and valley.
            while (ratings[i] > ratings[i - 1]) { // Calculate the number of candies for the increasing slope (peak).
                peak++;
                candy += peak; // Add candies based on peak.
                i++;
                if (i == n) return candy; // If we reached the end of the array, return the total candies.
            }

            int valley = 0; // Initialize the valley to track the decreasing slope.
            while (i < n && ratings[i] < ratings[i - 1]) { // Calculate the number of candies for the decreasing slope (valley).
                valley++;
                candy += valley; // Add candies based on valley.
                i++;
            }

            candy -= min(peak, valley); // Adjust the total candies by subtracting the minimum of peak and valley.
        }

        return candy; // Return the total candies distributed.
    }
};
