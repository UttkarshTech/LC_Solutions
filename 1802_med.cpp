long getSum(int n, int index, long peakValue) {
    long leftLength = index;
    long rightLength = n - 1 - index;
    long sum = peakValue;
    if (peakValue > leftLength)
        sum += (peakValue - 1 + peakValue - leftLength) * leftLength / 2;
    else
        sum += (peakValue - 1) * peakValue / 2 + (leftLength - (peakValue - 1));
    if (peakValue > rightLength) 
        sum += (peakValue - 1 + peakValue - rightLength) * rightLength / 2;
    else 
        sum += (peakValue - 1) * peakValue / 2 + (rightLength - (peakValue - 1));
    return sum;
}
int maxValue(int n, int index, int maxSum) {
    long low = 1, high = maxSum;
    int ans = 0;
    while (low <= high) {
        long mid = low + (high - low) / 2;
        long sum = getSum(n, index, mid);

        if (sum <= maxSum) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}