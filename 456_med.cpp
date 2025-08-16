bool find132pattern(vector<int>& nums) {
    int secMin = INT_MIN, size = nums.size();
    if (size < 3)
        return false;
    stack<int> s;
    for (int i = size-1; i>=0; i--){
        if (nums[i] < secMin)
            return true;
        while (!s.empty() && s.top() < nums[i]){
            secMin = s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    return false;
}