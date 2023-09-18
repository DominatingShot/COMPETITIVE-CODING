class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g = makeGraph(numCourses, prerequisites); // Create a directed graph.
        vector<int> indegree = computeIndegree(g); // Compute the indegree of each course.

        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (indegree[j] == 0) {
                    break;
                }
            }
            
            if (j == numCourses) {
                return false; // If there is no course with no dependencies left, there is a cycle.
            }
            
            indegree[j] = -1; // Mark the course as completed.
            
            for (int k = 0; k < g[j].size(); k++) {
                indegree[g[j][k]]--; // Reduce the indegree of all courses dependent on this course.
            }
        }
        
        return true; // No cycle was found, all courses can be finished.
    }
    
    vector<vector<int>> makeGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses); // Create a graph with numCourses nodes.
        
        for (int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]); // Add directed edges between courses.
        }
        
        return g;
    }
    
    vector<int> computeIndegree(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(), 0); // Initialize indegree for all courses to 0.
        
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                indegree[graph[i][j]]++; // Increment the indegree for courses with dependencies.
            }
        }
        
        return indegree;
    }
};
