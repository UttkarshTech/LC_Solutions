int getMax(vector<int> nums) {
    int maxi = INT_MIN;
    for (auto i : nums) maxi = max(maxi, i);
    return maxi;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    if (threshold == nums.size())
        return getMax(nums);
    
    int low = 1, high = getMax(nums), mid, ans;
    while (low <= high){
        mid = (low + high) / 2;

        int sum = 0;
        for (auto i : nums){
            sum += ceil((double)i/(double)mid);
            if (sum > threshold)
                break;
        }
        
        if (sum <= threshold){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}