int sortAndCount(vector<int>& nums, int low, int high) {
    if (low >= high)
        return 0;

    int middle = low + (high - low) / 2;
    int totalPairs = sortAndCount(nums, low, middle);
    totalPairs += sortAndCount(nums, middle + 1, high);
    totalPairs += mergeAndCount(nums, low, middle, high);

    return totalPairs;
}

int mergeAndCount(vector<int>& nums, int low, int middle, int high) {
    int crossPairs = 0;
    int rightPtr = middle + 1;

    for (int leftPtr = low; leftPtr <= middle; ++leftPtr) {
        while (rightPtr <= high && (long long)nums[leftPtr] > 2LL * nums[rightPtr])
            rightPtr++;
        crossPairs += rightPtr - (middle + 1);
    }
    vector<int> temp;
    temp.reserve(high - low + 1);
    int p1 = low, p2 = middle + 1;

    while (p1 <= middle && p2 <= high) {
        if (nums[p1] <= nums[p2])
            temp.push_back(nums[p1++]);
        else 
            temp.push_back(nums[p2++]);
    }
    while (p1 <= middle)
        temp.push_back(nums[p1++]);
    while (p2 <= high)
        temp.push_back(nums[p2++]);
    for (int i = 0; i < temp.size(); ++i)
        nums[low + i] = temp[i];

    return crossPairs;
}
int reversePairs(vector<int>& nums) {
    if (nums.empty())
        return 0;
    return sortAndCount(nums, 0, nums.size() - 1);
}