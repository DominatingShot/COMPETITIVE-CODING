class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)
            return false;
        for(int i=0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(helper(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index==word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='*'|| board[i][j]!=word[index])
            return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool res=helper(board,word,i+1,j,index+1) || helper(board,word,i-1,j,index+1) || helper(board,word,i,j+1,index+1) || helper(board,word,i,j-1,index+1);
        board[i][j]=temp;
        return res;
    } 
};