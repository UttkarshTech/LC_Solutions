const int MOD_INT = 1e9 + 7;
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int nthMagicalNumber(int n, int a, int b) {
    long long A = a;
    long long B = b;

    long long common_divisor = gcd(A, B);
    long long Lcm = (A * B) / common_divisor;

    long long low = 1;
    long long high = (long long)n * std::min(A, B);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long count = (mid / A) + (mid / B) - (mid / Lcm);

        if (count >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans % MOD_INT;
}