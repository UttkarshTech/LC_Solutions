void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0)
        return;
    if (m == 0){
        int i = 0;
        for (auto item : nums2)
            nums1[i++] = item;
    }

    for (int i = m+n-1; i>=n; i--)
        nums1[i] = nums1[i-n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n){
        if (nums1[n+i] <= nums2[j])
            nums1[k++] = nums1[n + i++];
        else
            nums1[k++] = nums2[j++];
    }
    if (i >= m)
        while (j < n)
            nums1[k++] = nums2[j++];
    else if (j >= n)
        while (i < m)
            nums1[k++] = nums1[n + i++];
}