class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0){
            return {1};
        }
        vector<int> result{1,1};
        for(int i=2;i<n+1;i++){
            vector<int> temp;
            for(int j=0;j<i+1;j++){
                if(j==0||j==i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(result[j-1]+result[j]);
                }
            }
            result=temp;
        }
        return result;
    }
};