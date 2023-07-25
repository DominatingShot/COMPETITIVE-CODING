class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalsurplus = 0;
        int surplus = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            totalsurplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }
        if(totalsurplus < 0)
            return -1;
        else
            return start;
    }
};
