int missingNumber(vector<int>& nums) {
    int size = nums.size(), sum = 0;
    for (auto i : nums)
        sum += i;
    return size*(size+1)/2 - sum;
}