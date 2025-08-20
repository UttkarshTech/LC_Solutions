string longestCommonPrefix(vector<string>& strs) {
    string s = strs[0];
    for(int i=1; i<strs.size(); i++){
        int j=0;
        while (j<strs[i].size() && j<s.size()){
            if (strs[i][j] == s[j])
                j++;
            else{
                s = s.substr(0, j);
                if (s == "")
                    return s;
                else
                    break;
            }
        }
        if (j == strs[i].size()){
            s = strs[i];
        }
    }
    return s;
}