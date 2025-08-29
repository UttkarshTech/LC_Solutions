int getMax(vector<int> arr){
    int maxDays; 
    for (auto i : arr)
        maxDays = max(i, maxDays);
    return maxDays;
}

bool getMBouquets(vector<int> arr, int m, int k, int days){
    int consCount = 0, bouquets = 0;
    for (auto i : arr){
        if (i <= days){
            consCount++;
            if (consCount == k){
                consCount = 0;
                bouquets++;
            }
        } else consCount = 0;
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < (long)m*(long)k)
        return -1;
    int low = 1, high = getMax(bloomDay), mid, ans;
    while (low <= high){
        mid = ((long)low + (long)high)/2;
        bool state = getMBouquets(bloomDay, m, k, mid);
        if (state) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}