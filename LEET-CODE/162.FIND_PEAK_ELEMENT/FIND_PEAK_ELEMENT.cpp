#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> v){ //define a function findPeakElement that takes a vector of integers as input and returns an integer
    if(v.size()==1){ //base case: if the vector has only one element, that element is a peak element
        return 0;
    }
    else if(v.size()==2){ //base case: if the vector has only two elements, return the index of the greater element
        if(v[0]>v[1]){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{ //recursive case: divide the vector into two halves and search for a peak element in the left or right half depending on the values of the mid element and its adjacent elements
        int mid = v.size()/2; //find the index of the middle element
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){ //if the middle element is greater than its adjacent elements, it is a peak element
            return mid;
        }
        else if(v[mid]>v[mid+1]){ //if the middle element is greater than its right adjacent element, search for a peak element in the left half of the vector
            vector<int> v2(v.begin(), v.begin()+mid);
            return findPeakElement(v2);
        }
        else{ //if the middle element is greater than its left adjacent element, search for a peak element in the right half of the vector
            vector<int> v2(v.begin()+mid, v.end());
            return findPeakElement(v2)+mid;
        }
        
    }
}
};
