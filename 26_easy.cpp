int removeDuplicates(vector<int>& nums) {
    int unique = 1, cur = nums[0];
    for (int i=1; i<nums.size(); i++){
        if (nums[i] != cur){
            nums[unique] = nums[i];
            cur = nums[i];
            unique++;
        }
    }
    return unique;
}