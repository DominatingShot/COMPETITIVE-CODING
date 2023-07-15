class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int ans=0;
        int i=0;
        while(true){
            if(ans == citations.size()-i)
                return ans;
            if(ans < citations[i])
                ans++;
            else
                i++;
        }
    }
};
        
                

            