int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    if (size == 1)
        return nums[0];
    int low = 0, high = size-1, mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (mid == 0 || mid == size-1)
            return nums[mid];
        if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
            return nums[mid];
        if (nums[mid+1] != nums[mid]){
            if (mid%2 == 0)
                high = mid-1;
            else
                low = mid + 1;
        } else {
            if (mid%2 == 0)
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}