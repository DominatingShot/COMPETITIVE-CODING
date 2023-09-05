class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = makeGraph(numCourses,prerequisites);
        vector<int> indegree = computeIndegree(g);
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++){//There is a course with which no other course is dependent
                if(indegree[j]==0){
                    break;
                }
            }
            if(j==numCourses){//There is no course with which no other course is dependent
                return false;//There is a cycle
            }
            indegree[j]=-1;//This course is done
            for(int k=0;k<g[j].size();k++){//Reduce the indegree of all the courses dependent on this course
                indegree[g[j][k]]--;
            }
        }
        return true;
    }
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return g;
    }
    vector<int> computeIndegree(vector<vector<int>>& graph){
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[graph[i][j]]++;
            }
        }
        return indegree;
    }
    
};