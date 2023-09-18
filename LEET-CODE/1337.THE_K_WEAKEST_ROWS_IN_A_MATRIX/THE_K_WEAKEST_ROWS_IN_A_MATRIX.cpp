class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;         // Vector to store the indices of the k weakest rows.
        vector<vector<int>> rowstatus;  // Vector to store the row status (number of ones and row index).

        // Calculate the number of ones in each row and store it along with the row index.
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1)
                    count++;
            }
            rowstatus.push_back({ count, i });

            // If the result is empty, add the current row index as the first result.
            if (result.size() == 0) {
                result.push_back(i);
            } else {
                int j = 0;
                for (; j < result.size(); j++) {
                    // Insert the current row index at the appropriate position based on the number of ones.
                    if (count < rowstatus[result[j]][0]) {
                        result.insert(result.begin() + j, i);
                        break;
                    }
                }
                // If the row index is not inserted (i.e., it's greater than or equal to all previous rows),
                // and there are fewer than k results, add it to the end.
                if (j == result.size() && result.size() < k)
                    result.push_back(i);
            }

            // If there are more than k results, remove the last one.
            if (result.size() > k)
                result.pop_back();
        }
        return result; 
