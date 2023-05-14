#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> v; // Create a vector to store the operations
      int j=0; // Initialize a variable to keep track of the number of skipped elements
      for(int i=1;i<=*(target.end()-1);i++){ // Loop through 1 to the last element of the target vector
       if(target[i-1-j]==i){ // If the current element matches the target element, push "Push" to the vector
        v.push_back("Push");
      }
       else{ // If the current element does not match the target element
        v.push_back("Push"); // Push "Push" to the vector
        v.push_back("Pop"); // Push "Pop" to the vector
        j=j+1; // Increment the number of skipped elements
      }  
    }
        return v; // Return the vector with the operations
}
};
