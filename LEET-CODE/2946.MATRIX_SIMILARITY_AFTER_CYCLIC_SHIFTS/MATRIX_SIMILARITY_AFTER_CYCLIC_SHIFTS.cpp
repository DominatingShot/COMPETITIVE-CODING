class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rowsize = mat[0].size();
        k=k%rowsize;
        auto temp = mat;
        for(int i=0;i<mat.size();i=i+2){
            if(!helper(mat,i,rowsize,k)){
                return false;
            }
        }
        return true;
        
        
    }
    bool helper(vector<vector<int>>& mat,int i,int n,int k){
        vector<int> temp(n);
        for(int j = 0; j < n; j++) {
            temp[(j + k) % n] = mat[i][j];
        }
        for(int j = 0; j < n; j++) {
            if(temp[j]!=mat[i][j]){
                return false;
            }
        }
        return true;
        
    }
};