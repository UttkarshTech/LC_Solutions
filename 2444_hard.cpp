long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long count = 0;
    int outOfRangePrev = -1, maxKPrev = -1, minKPrev = -1, size = nums.size();
    for (int i=0; i<size; i++){
        if (nums[i] == maxK)
            maxKPrev = i;
        if (nums[i] == minK)
            minKPrev = i;
        if (nums[i]>maxK || nums[i]<minK)
            outOfRangePrev = i;
        count += max(0, min(maxKPrev, minKPrev) - outOfRangePrev);
    }
    return count;
}