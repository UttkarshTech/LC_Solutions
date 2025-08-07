int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int start = 0, end = size-1, mid;
    if (nums[end] < target)
        return end+1;
    else if (nums[start] > target)
        return 0;
    while (1){
        mid = (start + end)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target){
            if (start == mid)
                break;
            start = mid;
        } else {
            if (start == mid)
                break;
            end = mid;
        }
    }
    if (nums[mid] > target)
        return mid - 1;
    else 
        return mid + 1;
}