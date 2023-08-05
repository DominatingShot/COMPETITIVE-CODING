class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalsurplus = 0; // Initialize a variable to track the total surplus gas.
        int surplus = 0; // Initialize a variable to track the current surplus gas.
        int start = 0; // Initialize the starting index of the circular tour.

        for (int i = 0; i < gas.size(); i++) {
            totalsurplus += gas[i] - cost[i]; // Calculate the total surplus gas considering all stations.
            surplus += gas[i] - cost[i]; // Calculate the current surplus gas considering stations visited so far.

            if (surplus < 0) { // If the current surplus gas becomes negative (not enough to move forward),
                surplus = 0; // reset it to zero (as we need to start from a new station).
                start = i + 1; // Update the starting index to the next station.
            }
        }

        if (totalsurplus < 0) // If the total surplus gas is negative (meaning overall gas is less than the overall cost),
            return -1; // we cannot complete the circular tour, so return -1.
        else
            return start; // Otherwise, return the starting index of the circular tour.
    }
};
