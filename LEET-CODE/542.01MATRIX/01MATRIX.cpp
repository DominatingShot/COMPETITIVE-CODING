class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int inf=m+n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=inf,left=inf;
                if(mat[i][j]==0){
                    continue;
                }
                if(i-1>=0){
                    up=mat[i-1][j];
                }
                if(j-1>=0){
                    left=mat[i][j-1];
                }
                mat[i][j]=min(up,left)+1;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int down=inf,right=inf;
                if(mat[i][j]==0){
                    continue;
                }
                if(i+1<m){
                    down=mat[i+1][j];
                }
                if(j+1<n){
                    right=mat[i][j+1];
                }
                mat[i][j]=min(mat[i][j],min(down,right)+1);
            }
        }
        return mat;
    }
};