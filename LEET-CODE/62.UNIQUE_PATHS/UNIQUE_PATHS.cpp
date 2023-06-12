#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,0));
       int i=0,j=0;
       while(i<m && j<n){
            if(i==0||j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            if(i==m-1 && j==n-1){
                break;
            }
            else if(j==n-1){
                i++;
                j=0;
            }
            else{
                j++;
            }
            
       }
       return dp[i][j];
    }
    
};