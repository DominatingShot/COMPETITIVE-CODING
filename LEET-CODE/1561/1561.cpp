class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i = piles.size()-2;
        int x = piles.size()/3;
        int sum = 0;
        while(x>0){
            sum+=piles[i];
            x--;
            i-=2;
        }
        return sum;
    }
};