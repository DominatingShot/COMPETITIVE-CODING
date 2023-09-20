class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        visited[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i)==abs(j)){
                        continue;
                    }
                    int new_row=row+i;
                    int new_col=col+j;
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && 
                    grid[new_row][new_col]=='1' && !visited[new_row][new_col]){
                        visited[new_row][new_col]=true;
                        q.push({new_row,new_col});
                    }
                }
            }
        }
    }
};