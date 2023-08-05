class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (i < j) {
            // Calculate the area of the container formed by vertical lines at i and j
            int area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, area); // Update the maximum area if the current area is larger

            // Move the pointer that corresponds to the shorter line
            // Since the height of the container is determined by the shorter line,
            // moving the pointer that corresponds to the longer line will not increase the area.
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area; // Return the maximum area of the container
    }
};
