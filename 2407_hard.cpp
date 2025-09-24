int querySegTree(vector<int> &segTree, int i, int begin, int end, int l, int r){
    if (r < begin || l > end || l > r)
        return 0;
    if (l <= begin && end <= r)
        return segTree[i];
    int mid = (begin + end)/2;
    int leftRes = querySegTree(segTree, i*2, begin, mid, l, r);
    int rightRes = querySegTree(segTree, i*2+1, mid+1, end, l, r);
    return max(leftRes, rightRes);
}
void updateSegTree(vector<int> &segTree, int i, int begin, int end, int index, int val){
    if (begin == end){
        segTree[i] = val;
        return;
    }
    int mid = (begin + end)/2;
    if (index <= mid)
        updateSegTree(segTree, 2*i, begin, mid, index, val);
    else updateSegTree(segTree, 2*i+1, mid+1, end, index, val);

    segTree[i] = max(segTree[2*i], segTree[2*i+1]);
}
int lengthOfLIS(vector<int>& nums, int k) {
    vector<int> segTree (4*1e5 + 4, 0);
    for (auto i : nums){
        int l = max(1, i-k), r = i-1;
        int len = querySegTree(segTree, 1, 1, 1e5+1, l, r) + 1;
        updateSegTree(segTree, 1, 1, 1e5+1, i, len);
    }
    return segTree[1];
}