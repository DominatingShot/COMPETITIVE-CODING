class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        for(int i=0;i<groupSizes.size();i++){
                bool flag=false;
                for(int j=0;j<result.size();j++){
                    if(groupSizes[result[j][0]]==groupSizes[i]&&result[j].size()<groupSizes[i]){
                            result[j].push_back(i);
                            flag = true;
                            break;
                    }
                    flag = false;
                }
                if(!flag){
                    vector<int> temp;
                    temp.push_back(i);
                    result.push_back(temp);
                }
            
        }
        return result;
    }
};