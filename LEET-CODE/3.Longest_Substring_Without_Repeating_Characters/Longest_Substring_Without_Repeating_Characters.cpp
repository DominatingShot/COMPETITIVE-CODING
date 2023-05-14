#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) { //define a function lengthOfLongestSubstring that takes a string parameter and returns an integer
        int n=s.length(); //get the length of the input string s and store it in variable n
        int ans=0; //initialize variable ans to 0
        for(int i=0;i<n;i++){ //iterate over each character of the input string s
            unordered_map<char,int> m; //create an empty unordered_map to store the frequency of characters in the current substring
            int x=0; //initialize variable x to 0 to store the length of the current substring
            for(int j=i;j<n;j++){ //iterate over each character of the current substring starting from index i
                m[s[j]]++; //increment the frequency of the current character in the unordered_map
                if(m[s[j]]>1){ //if the frequency of the current character is greater than 1, i.e., the current substring contains repeating characters
                    break; //exit the inner for loop
                }
                x=x+1; //increment the length of the current substring
                ans=max(ans,x); //update the length of the longest substring found so far
            }
        }
        return ans; //return the length of the longest substring without repeating characters
    }
};
