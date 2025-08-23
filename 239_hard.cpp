vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int l = 0, r = k - 1;
    deque<int> dq;
    vector<int> res;
    for (int i=l; i<=r; i++){
        if (dq.empty())
            dq.push_back(nums[i]);
        else if (nums[i] > dq.back()){
            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
        } else dq.push_back(nums[i]);
    }
    res.push_back(dq.front());
    while (r < nums.size()-1){
        if (nums[l] == dq.front())
            dq.pop_front();
        l++;
        r++;
        if (dq.empty())
            dq.push_back(nums[r]);
        else if (nums[r] > dq.back()){
            while (!dq.empty() && nums[r] > dq.back())
                dq.pop_back();
            dq.push_back(nums[r]);
        } else dq.push_back(nums[r]);
        res.push_back(dq.front());
    }
    return res;
}