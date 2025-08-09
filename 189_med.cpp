void reversePart(vector<int> &nums, int start, int end){
    while (start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        end--; start++;
    }
}
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = k%size;
    if (!k)
        return;
    reversePart(nums, size-k, size-1);
    reversePart(nums, 0, size-k-1);
    reversePart(nums, 0, size-1);
}