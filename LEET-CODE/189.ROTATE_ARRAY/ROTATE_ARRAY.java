class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length; // Calculate the effective rotation value within the range [0, nums.length - 1].
        int[] temp = new int[nums.length]; // Create a temporary array to store the rotated elements.

        // Iterate through the original array.
        for (int i = 0; i < nums.length; i++) {
            // Calculate the new index for the current element after rotation.
            // Use modulo to wrap around when reaching the end of the array.
            temp[(i + k) % nums.length] = nums[i];
        }

        // Copy the rotated elements from the temporary array back to the original array.
        for (int i = 0; i < nums.length; i++) {
            nums[i] = temp[i];
        }
    }
}
