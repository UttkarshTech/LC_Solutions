vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int size1 = nums1.size(), size2 = nums2.size();
    auto compare = [&](vector<int> &a, vector<int> &b){
        return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);
    vector<vector<int>> res;
    int i=0, j=0;

    while (i<k && i<size1){
        q.push({i, 0});
        i++;
    }

    while (k && !q.empty()){
        auto temp = q.top();
        q.pop();
        i = temp[0];
        j = temp[1];
        res.push_back({nums1[i], nums2[j]});
        if (j < size2-1)
            q.push({i, j+1});
        k--;
    }
    return res;
}