bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    long sum = 0;
    m[0] = -1;
    for (int i=0; i<nums.size(); i++){
        sum = (sum + (long)nums[i]) % k;
        if (m.find(sum) == m.end())
            m[sum] = i;
        else {
            if (i - m[sum] > 1)
                return true;
        }
    }
    return false;
}