class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int rowdiff=abs(sx-fx);
        int columndiff=abs(sy-fy);
        if(rowdiff == 0 && columndiff == 0 && t==1){
            return false;
        }
        return max(rowdiff,columndiff)<=t;

    }
};