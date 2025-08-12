const long long MOD = 1000000007;
vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> res, pow2;
    int i = 1;
    while (n != 0){
        if (n & 1)
            pow2.push_back(i);
        i <<= 1;
        n >>= 1;
    }
    for (auto item : queries){
        if (item[0] == item[1])
            res.push_back(pow2[item[0]]);
        else {
            long long a = pow2[item[0]];
            int i = item[0]+1;
            while (i <= item[1])
                a = (a * pow2[i++]) % MOD;
            res.push_back(a);
        }
    }
    return res;
}