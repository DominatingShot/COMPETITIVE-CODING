class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        if (i == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            swap(num[i], num[k]);
            recursion(num, i+1, res);

        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};