int majorityElement(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    int count = 1, key = nums[0];
    int i = 1;
    while (i < nums.size()){
        if (nums[i] == key)
            count++;
        else {
            if (count == 0)
                key = nums[i];
            else
                count--;
        }
        i++;
    }
    return key;
}