class Solution {
public:
    int countHomogenous(string s) {
        long sum=0;
        for(int i=0;i<s.size();){
            int c=1;
            char temp=s[i];
            int j=i+1;
            sum=sum+c;
            while(s[j]==temp && j<s.size()){
                sum=sum+(++c);
                j++;
            }
            i=j;
        }
        return sum % int(pow(10,9)+7);
    }
};