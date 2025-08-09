vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    int i=0, j=1;
    for (auto item : nums){
        if (item >= 0){
            res[i] = item;
            i += 2;
        } else {
            res[j] = item;
            j += 2;
        }
    }
    return res;
}