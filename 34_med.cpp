int getMinPos(vector<int>& nums, int target){
    int size = nums.size();
    if (!size)
        return -1;
    int low=0, high=size-1, mid;
    while (low <= high){
        mid = low + (high-low)/2;
        if (nums[mid] == target){
            if (mid == 0 || nums[mid-1] != target)
                return mid;
            else
                high = mid-1;
        } else if (nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (nums[mid] != target){
        if (mid != size-1 && nums[mid+1] == target)
            return mid+1;
        else return -1;
    } else return mid;
}
int getMaxPos(vector<int>& nums, int target){
    int size = nums.size();
    if (!size)
        return -1;
    int low=0, high=size-1, mid;
    while (low <= high){
        mid = low + (high-low)/2;
        if (nums[mid] == target){
            if (mid == size-1 || nums[mid+1] != target)
                return mid;
            else
                low = mid+1;
        } else if (nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (nums[mid] != target){
        if (mid != 0 && nums[mid-1] == target)
            return mid-1;
        else return -1;
    } else return mid;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    res.push_back(getMinPos(nums, target));
    res.push_back(getMaxPos(nums, target));
    return res;
}