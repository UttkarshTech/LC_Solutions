int maxSubArray(vector<int>& nums) {
    int j = 0, size = nums.size();
    if (size == -1)
        return nums[0];
    while (j < size && nums[j] < 0)
        j++;
    if (j == size)
        j = 0;
    int sum = nums[j], maxSum = nums[j];
    for (int i=j+1; i<size; i++){
        if (sum>0 && nums[i]>=0){
            sum += nums[i];
        } else if (sum>0 && nums[i]<0){
            sum += nums[i];
        } else if (sum<=0 && nums[i]>=0){
            sum = nums[i];
        } else if (sum<=0 && nums[i]<0){
            if (nums[i] > maxSum){
                maxSum = nums[i];
            }
            sum = 0;
        }

        if (sum != 0 && sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}