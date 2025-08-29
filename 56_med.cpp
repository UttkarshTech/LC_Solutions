vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1)
        return intervals;
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    int maxEndPoint = intervals[0][1];
    int j = 0;
    for (int i=1; i<intervals.size(); i++){
        if (maxEndPoint >= intervals[i][0]){
            maxEndPoint = max(maxEndPoint, intervals[i][1]);
        }
        else {
            res.push_back({intervals[j][0], maxEndPoint});
            maxEndPoint = intervals[i][1];
            j = i;
        }
    }
    res.push_back({intervals[j][0], maxEndPoint});
    return res;
}