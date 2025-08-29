bool isIdealPermutation(vector<int>& nums) {
    if(nums.size() < 3)
        return true;
    int maximum = nums[0];
    for (int i=2; i<nums.size(); i++){
        maximum = max(maximum, nums[i-2]);
        if (maximum > nums[i])
            return false;
    }
    return true;
}