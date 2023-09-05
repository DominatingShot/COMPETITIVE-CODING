class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==destination){
                return true;
            }
            visited[curr]=true;
            for(auto i:graph[curr]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        return false;
    }
};