vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int size = nums.size();
    if (size < 3)
        return res;
    sort(nums.begin(), nums.end());
    for (int i=0; i<size-2; i++){
        if (i>0 && nums[i]==nums[i-1])
            continue;
        int j = i+1, k = size-1;
        while (j < k){
            int sum = nums[i]+nums[j]+nums[k];
            if (sum == 0){
                res.push_back({nums[i], nums[j], nums[k]});
                int jPrev = nums[j++];
                int kPrev = nums[k--];
                while (j < size && jPrev == nums[j])
                    j++;
                while (k > i && kPrev == nums[k] )
                    k--;
            }
            else if (sum > 0) k--;
            else j++;
        }
    }
    return res;
}