int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;
    int low=1,  high = x/2, mid, last;
    while (low <= high){
        mid = (low + high)/2;
        long long res = (long long)mid * (long long)mid;
        if (res == x)
            return mid;
        else if (res < x){
            last = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return min(last, mid);
}