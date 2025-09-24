int matrixSum(vector<vector<int>>& nums) {
    int rows = nums.size();
    int cols = nums[0].size();
    int score = 0;
    for (auto &i : nums){
        sort(i.begin(), i.end());
    }
    for (int j=0; j<cols; j++){
        int maxi = INT_MIN;
        for (int i=0; i<rows; i++) maxi = max(maxi, nums[i][j]);
        score += maxi;
    }
    return score;
}

// int matrixSum(vector<vector<int>>& nums) {
//     int rows = nums.size();
//     int cols = nums[0].size();
//     int score = 0;
//     vector<priority_queue<int>> pqMat(rows);
//     for (int i=0; i<rows; i++){
//         for (auto j : nums[i])
//             pqMat[i].push(j);
//     }
//     while(cols--){
//         int maxOfMaxes = INT_MIN;
//         for (auto &i : pqMat){
//             int x = i.top();
//             i.pop();
//             maxOfMaxes = max(maxOfMaxes, x);
//         }
//         score += maxOfMaxes;
//     }
//     return score;
// }