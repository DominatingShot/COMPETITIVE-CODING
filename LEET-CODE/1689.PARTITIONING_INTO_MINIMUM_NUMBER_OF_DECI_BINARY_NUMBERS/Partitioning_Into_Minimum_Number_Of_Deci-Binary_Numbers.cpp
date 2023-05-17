#include <bits/stdc++.h>
using namespace std;

// Define a class Solution
class Solution {
public:
    // Define a method named minPartitions that takes a string n as input and returns an integer.
    int minPartitions(string n) {
        // Initialize a character variable c to the first character of the input string.
        char c=n[0];
        // Iterate over all the characters in the input string.
        for(char i : n){
            // Update the value of c to the maximum character encountered so far.
            if(c<i){
            c=i;
            }
        }
        // Return the integer equivalent of the character c.
        return c-'0';
    }
};
