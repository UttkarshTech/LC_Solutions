bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s; int i = 0, size = pushed.size();
    for (auto j : popped){
        if (!s.empty() && s.top() == j)
            s.pop();
        else {
            while (i < size && pushed[i] != j){
                s.push(pushed[i]);
                i++;
            }
            if (i == size && !s.empty())
                return false;
            i++;
        }
    }
    return true;
}