vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, pair<int, int>> m;
    vector <int> arr(2);
    for (int i=0; i<nums.size(); i++){
        if (m[target - nums[i]].second == 1){
            arr[0] = i;
            arr[1] = m[target - nums[i]].first;
            return arr;
        }
        else 
            m[nums[i]] = {i, 1};
    }
    return arr;
}