double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    if (size1 > size2) 
        return findMedianSortedArrays(nums2, nums1);

    int sizeTot = size1 + size2;
    int sizeLeftSubArr = (sizeTot + 1) / 2; 

    int low = 0, high = size1;

    while (low <= high) {
        int mid1 = (low + high)/2; 
        int mid2 = sizeLeftSubArr - mid1; 
        int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int right1 = (mid1 < size1) ? nums1[mid1] : INT_MAX;
        int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int right2 = (mid2 < size2) ? nums2[mid2] : INT_MAX;

        if (left1 <= right2 && left2 <= right1) {
            if (sizeTot % 2 == 1) return max(left1, left2);
            else return (max(left1, left2) + min(right1, right2)) / 2.0;
        } 
        else if (left1 > right2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return -1; 
}