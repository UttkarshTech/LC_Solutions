bool backspaceCompare(string s, string t) {
    stack<int> stackS, stackT;
    for (auto i : s){
        if (i == '#'){
            if (!stackS.empty())
                stackS.pop();
            else continue;
        } else stackS.push(i);
    }
    for (auto i : t){
        if (i == '#'){
            if (!stackT.empty())
                stackT.pop();
            else continue;
        } else stackT.push(i);
    }
    if (stackS.empty() && stackT.empty())
        return true;
    if (stackS.size() != stackT.size())
        return false;
    while (!stackS.empty()){
        if (stackS.top() == stackT.top()){
            stackS.pop();
            stackT.pop();
        } else return false;
    }
    return true;
}