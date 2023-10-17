string removeDuplicateLetters(string s) {
        cout<<"HI1"<<endl;
        string ans = "";
        stack<char> st;
        for(auto c: s) {
            if(st.empty()) {
                st.push(c);
            } else {
                stack<char> temp;
                while(!st.empty() && st.top() > c) {
                    temp.push(st.top());
                    st.pop();
                }
                if(st.top() == c) continue;
                st.push(c);
                while(!temp.empty()) {
                    st.push(temp.top());
                    temp.pop();
                }
            }
        }
        while(!st.empty()) {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }