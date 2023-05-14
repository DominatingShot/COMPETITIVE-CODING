#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        char c=n[0];
        for(char i : n){
            if(c<i){
            c=i;
            }
        }
        return c-'0';
    }
};