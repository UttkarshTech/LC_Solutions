void moveZeroes(vector<int>& nums) {
    int countZero = 0, nonZero = 0;
    for (auto i : nums){
        if (i == 0)
            countZero++;
    }
    for (int i=0; i<nums.size(); i++){
        if (nums[i] != 0){
            nums[nonZero] = nums[i];
            nonZero++;
        }
    }
    for (int i=nums.size()-countZero; i<nums.size(); i++){
        nums[i] = 0;
    }
}