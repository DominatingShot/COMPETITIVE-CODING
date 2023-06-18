class Solution {
public:
    int majorityElement(vector<int>& v) {
        // Sort the input vector in ascending order
        sort(v.begin(),v.end());

        // Return the element at the middle index, which represents the majority element
        return *(v.begin()+(v.size())/2);
    }
};
