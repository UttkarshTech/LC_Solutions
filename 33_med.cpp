int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid]) {
            // left is sorted
            if (target < nums[mid] && target >= nums[low])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}