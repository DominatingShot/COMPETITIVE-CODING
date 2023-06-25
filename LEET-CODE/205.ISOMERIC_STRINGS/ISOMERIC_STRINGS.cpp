#include <bits/stdc++.h>  // Include standard C++ libraries
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;  // If the lengths of the strings are different, they cannot be isomorphic
        }
        if (s.size() == 0) {
            return true;  // If the strings are empty, they are trivially isomorphic
        }

        map<char, char> m;  // Map to store mappings from characters in 's' to characters in 't'
        map<char, char> m2;  // Map to store mappings from characters in 't' to characters in 's'

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end() && m2.find(t[i]) == m2.end()) {
                // If the characters are not mapped in both directions, create new mappings
                m[s[i]] = t[i];  // Map character from 's' to 't'
                m2[t[i]] = s[i];  // Map character from 't' to 's'
            } else {
                // If the characters are already mapped, check if the mappings match
                if (m[s[i]] != t[i] || m2[t[i]] != s[i]) {
                    return false;  // If the mappings don't match, the strings are not isomorphic
                }
            }
        }

        return true;  // If all characters are successfully mapped and the mappings match, the strings are isomorphic
    }
};
