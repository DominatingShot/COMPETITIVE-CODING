class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n,string(n,'.'));
        helper(result,temp,0,0,n);
        return result;
    }
    void helper(vector<vector<string>>& result, vector<string>& temp, int row ,int column,int n){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        while(isvalid(temp,row,column,n)){
            temp[row][column]='Q';
            helper(result,temp,row+1,0,n);
            temp[row][column]='.';
            column++;
           
        }
        
    }
    void isvalid(vector<string>& temp, int row, int col, int n){
        for(int i=0;i<row;i++){
            if(temp[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(temp[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(temp[i][j]=='Q')
                return false;
        }
        return true;
    }
};
