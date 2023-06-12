#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = matrix.size(); //find the number of rows in the matrix
        int y = matrix[0].size(); //find the number of columns in the matrix
        vector<int> v; //define a vector to store the elements of the matrix in spiral order
        int i=0, j=0; //define two variables to store the indices of the current element
        map<pair<int, int>, bool> m; //define a map to store the indices of the elements that have already been visited
        while(true){
            v.push_back(matrix[i][j]); //push the current element into the vector
            m[{i, j}] = true; //mark the current element as visited
            if(m[{i, j+1}]!=true && j+1<y){ //if the element to the right of the current element has not been visited and is within the bounds of the matrix, move to the right
                j++;
            }
            else if(m[{i+1, j}]!=true && i+1<x){ //if the element below the current element has not been visited and is within the bounds of the matrix, move down
                i++;
            }
            else if(m[{i, j-1}]!=true && j-1>=0){ //if the element to the left of the current element has not been visited and is within the bounds of the matrix, move to the left
                j--;
            }
            else if(m[{i-1, j}]!=true && i-1>=0){ //if the element above the current element has not been visited and is within the bounds of the matrix, move up
                i--;
                while(m[{i-1, j}]!=true && i-1>=0){ //if the element above the current element has not been visited and is within the bounds of the matrix, move up
                    v.push_back(matrix[i][j]); //push the current element into the vector
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
