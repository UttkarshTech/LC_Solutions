string removeKdigits(string nums, int k) {
    stack<int> st;
    for (auto i : nums){
        int x = (int)i - 48;
        if (st.empty() || k == 0)
            st.push(x);
        else {
            while (!st.empty() && k > 0 && st.top() > x){
                st.pop();
                k--;
            }
            st.push(x);
        }
    }
    if (k > 0){
        while (!st.empty() && k>0){
            st.pop();
            k--;
        }
    }
    if (st.empty())
        return "0";
    else {
        int i = 0;
        int size = st.size();
        while (!st.empty()){
            nums[size-1-(i++)] = (char)(st.top()+48);
            st.pop(); 
        }
        i = 0;
        while (i < size && nums[i] == '0')
            i++;
        if (i == size)
            return "0";
        return nums.substr(i, size-i);
    }
}