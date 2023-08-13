class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=0;
        for(char cs:s)
            c^=cs;
        for(char cs:t)
            c^=cs;
        return c;
    };
}