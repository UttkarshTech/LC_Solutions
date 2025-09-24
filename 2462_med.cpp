long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> left, right;
    long long cost = 0;
    int leftMark = 0, rightMark = costs.size()-1;
    for (; leftMark < candidates; leftMark++) left.push(costs[leftMark]);
    for (; rightMark >= leftMark && rightMark >= costs.size()-candidates; rightMark--)
        right.push(costs[rightMark]);
    while (k--){
        int minCostLeft = (left.size() > 0) ? left.top() : INT_MAX;
        int minCostRight = (right.size() > 0) ? right.top() : INT_MAX;
        if (minCostLeft <= minCostRight){
            left.pop();
            cost += minCostLeft;
            if (leftMark <= rightMark) left.push(costs[leftMark++]);
        }
        else {
            right.pop();
            cost += minCostRight;
            if (leftMark <= rightMark) right.push(costs[rightMark--]);
        }
    }
    return cost;
}