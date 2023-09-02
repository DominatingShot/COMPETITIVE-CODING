class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            if(trust.size()==0){
                return 1;
            }
            return -1;
        }
        unordered_map<int,int> m;
        for(int i=0;i<trust.size();i++){
            m[trust[i][1]]++;
            m[trust[i][0]]--;
        }
        for(auto i:m){
            if(i.second==n-1){
                return i.first;
            }
        }
        return -1;
    }
};