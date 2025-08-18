string removeOuterParentheses(string s) {
    string res;
    stack<int> st;
    for (int i=0; s[i] != '\0'; i++){
        if (s[i] == '(') st.push(i);
        else {
            int open = st.top();
            st.pop();
            if (st.empty()){
                for (int j=open+1; j<i; j++)
                    res += s[j];
            }
        }
    }
    return res;
}