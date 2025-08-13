vector<vector<int>> res;
    int size = nums.size();
    if (size < 4)
        return res;
    sort(nums.begin(), nums.end());
    for (int i=0; i<size-3; i++){
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        for (int j=i+1; j<size-2; j++){
            if (j > i+1 && nums[j] == nums[j-1])
                continue;
            int k = j + 1, l = size - 1;
            while (k < l){
                long sum = ((long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l]) % MOD;
                if (sum == target){
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int kPrev = nums[k];
                    int lPrev = nums[l];
                    while (k < size && kPrev == nums[k])
                        k++;
                    while (l > j && lPrev == nums[l])
                        l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return res;
}