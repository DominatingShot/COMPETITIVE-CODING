class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Create a mapping of digits to their corresponding letters on a phone keypad.
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> result;
        if (digits.size() == 0) {
            return result; // If the input string is empty, return an empty result.
        }
        string temp = "";
        helper(result, temp, m, 0, digits); // Start the recursion from the first digit.
        return result;
    }

    void helper(vector<string>& result, string& temp, unordered_map<char, string>& m, int begin, string& digits) {
        if (begin == digits.size()) {
            result.push_back(temp); // If we've processed all digits, add the current combination to the result.
            return;
        }
        char c = digits[begin];
        int i = 0;
        while (i < m[c].size()) {
            temp = temp + m[c][i]; // Append a letter from the mapping to the current combination.
            helper(result, temp, m, begin + 1, digits); // Recursively generate combinations for the next digit.
            temp.pop_back(); // Backtrack by removing the last added letter.
            i++;
        }
    }
};
