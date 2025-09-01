int getMax(vector<int> nums) {
    int maxi = INT_MIN;
    for (auto i : nums) maxi = max(maxi, i);
    return maxi;
}
int minEatingSpeed(vector<int>& piles, int h) {
    if (piles.size() == h)
        return getMax(piles);
    int low = 1, high = getMax(piles), mid, ans;
    while (low <= high){
        mid = (low + high)/2;
        int time = 0;
        for (auto i : piles){
            time += ceil((double)i/(double)mid);
            if (time > h)
                break;
        }
        if (time <= h){
            ans = mid;
            high = mid - 1;
        } else low = mid +1;
    }
    return ans;
}