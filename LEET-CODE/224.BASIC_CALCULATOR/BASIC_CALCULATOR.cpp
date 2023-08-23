class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res=0;
        int sign=1;
        int num=0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){ 
                res+=sign*num;
                sign=1;
                num=0;
            }
            else if(s[i]=='-'){
                res+=sign*num;
                sign=-1;
                num=0;
            }
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res+=sign*num;
                res*=s.top();
                st.pop();
                res+=s.top();
                st.pop();
                num=0;
            }      
        }
        if(num!=0){
            res+=sign*num;
        }
        return res;
    } 
};