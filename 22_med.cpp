vector<string> v;
void genPar(int n, int open, int close, string s){
    if (open == n && close == n){
        v.push_back(s);
        return;
    }
    if (open <= n)
        genPar(n, open+1, close, s + "(");
    if (close < open)
        genPar(n, open, ++close, s + ")");
    return;
}
vector<string> generateParenthesis(int n) {
    //your code goes here
    string s = "";
    if (n == 0)
        return v;
    if (n == 1){
        v.push_back("()");
        return v;
    }
    genPar(n, 0, 0, s);
    return v;
}
};