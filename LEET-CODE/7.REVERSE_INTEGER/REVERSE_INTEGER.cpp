#include <bits/stdc++.h>
using namespace std;
class Solution {                      
public:
    int reverse(int x) {
        int r=0;      // decleare r 
        try {
            while (x) {
                r = r * 10 + x % 10;
                x = x / 10;
            }
        } catch (const overflow_error& e) {
            return 0;
        } // check range if r is outside the range then return 0  
        return int(r);  // if r in the 32 bit range then return r
    }
}; 
//Not proper solution