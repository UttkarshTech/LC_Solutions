int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;
    int sum = 0;
    for (auto i : piles){
        pq.push(i);
        sum += i;
    }
    while (k--){
        int x = pq.top();
        int minus = x>>1;
        sum -= minus;
        pq.pop();
        pq.push(x-minus);
    }
    return sum;
}