int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) 
        m[nums[i]] = 1;
    int maxCount = 1;
    for (auto &i : m) {
        if (m.find(i.first-1) != m.end())
            continue;
        else {
            int temp = i.first;
            while (m.find(++temp) != m.end()) {
                i.second++;
            }
            if (i.second > maxCount) maxCount = i.second;
        }
    }
    return maxCount;
}