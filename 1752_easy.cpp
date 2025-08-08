bool check(vector<int>& nums) {
    int i = 0;
    bool changed = false;
    while (i < nums.size()-1){
        if (nums[i] > nums[i+1]){
            if (changed)
                return false;
            else
                changed = true;
        }
        i++;
    }
    if (nums[i] > nums[0] && changed)
        return false;
    return true;
}