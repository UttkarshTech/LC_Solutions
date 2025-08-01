bool isValid(string s) {
    int i = 0;
    stack<char> stk;
    while (s[i] != '\0'){
        switch (s[i]){
            case '(' : stk.push(s[i]);
            break;
            case '{' : stk.push(s[i]);
            break;
            case '[' : stk.push(s[i]);
            break;
            case ')' : 
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            break;
            case '}' : 
                if (!stk.empty() && stk.top() == '{')
                    stk.pop();
                else
                    return false;
            break;
            case ']' : 
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                    return false;
            break;
        }
        i++;
    }
    return stk.empty();
}