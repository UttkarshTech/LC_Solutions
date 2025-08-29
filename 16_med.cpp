int threeSumClosest(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 3){
        int sum = 0;
        for (auto i : nums)
            sum += i;
        return sum;
    }
    sort(nums.begin(), nums.end());
    int minDist = INT_MAX, closestSum;
    for (int i=0; i<size-2; i++){
        if (i>0 && nums[i]==nums[i-1])
            continue;
        int j = i+1, k = size-1;
        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
                return sum;
            int dist = abs(target - sum);
            if (dist < minDist){
                minDist = dist;
                closestSum = sum;
            }
            if (sum < target){
                j++;
            } else k--;
        }
    }
    return closestSum;
}