class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(),0);
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};