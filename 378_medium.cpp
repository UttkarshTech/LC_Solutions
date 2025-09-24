int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    for (auto row : matrix){
        for (auto element : row){
            pq.push(element);
            if (pq.size() > k)
                pq.pop();
        }
    }
    return pq.top();
}