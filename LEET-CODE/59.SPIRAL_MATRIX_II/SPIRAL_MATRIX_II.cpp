#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0)); //define a vector of vectors to store the elements of the matrix
        int i=0, j=0; //define two variables to store the indices of the current element
        map<pair<int, int>, bool> m; //define a map to store the indices of the elements that have already been visited
        int k=1; //define a variable to store the value of the current element
        while(true){
            v[i][j] = k; //store the value of the current element in the matrix
            k++; //increment the value of the current element
            m[{i, j}] = true; //mark the current element as visited
            if(m[{i, j+1}]!=true && j+1<n){ //if the element to the right of the current element has not been visited and is within the bounds of the matrix, move to the right
                j++;
            }
            else if(m[{i+1, j}]!=true && i+1<n){ //if the element below the current element has not been visited and is within the bounds of the matrix, move down
                i++;
            }
            else if(m[{i, j-1}]!=true && j-1>=0){ //if the element to the left of the current element has not been visited and is within the bounds of the matrix, move to the left
                j--;
            }
            else if(m[{i-1, j}]!=true && i-1>=0){ //if the element above the current element has not been visited and is within the bounds of the matrix, move up
                i--;
                while(m[{i-1, j}]!=true && i-1>=0){ //if the element above the current element has not been visited and is within the bounds of the matrix, move up
                    k++; //increment the value of the current element
                    v[i][j] = k; //store the value of the current element in the matrix
                    m[{i, j}] = true; //mark the current element as visited
                    i--;
                }
            }
            else{ //if all the adjacent elements have been visited or are out of bounds, break out of the loop
                break;
            }
        }
        return v; //return the vector containing the elements of the matrix in spiral order
    }
};