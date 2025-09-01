int findMin(vector<int>& nums) {
    int minNum = INT_MAX;
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        minNum = min(minNum, nums[mid]);
        if (nums[low] <= nums[mid]){
            //left half is sorted
            minNum = min(minNum , nums[low]);
            low = mid + 1;
        }
        else {
            //right half is sorted
            if (mid < nums.size()-1)
                minNum = min(minNum, nums[mid+1]);
            high = mid - 1;
        }
    }
    return minNum;
}