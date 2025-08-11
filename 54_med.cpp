vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0, right=matrix[0].size()-1, bottom=matrix.size()-1;
    int left = 0;
    vector<int> res;
    while (top <= bottom && left <= right){
        for (int i=left; i<=right; i++)
            res.push_back(matrix[top][i]);
        top++;
        // if (top <= bottom) this condition checked by loop
        // left <= right holds because right was never changed
        for (int i=top; i<=bottom; i++)
            res.push_back(matrix[i][right]);
        right--;
        // if (left <= right) this condition checked by loop
        if (top <= bottom)
            for (int i=right; i>=left; i--){
                res.push_back(matrix[bottom][i]);
            }
        bottom--;
        // if (top <= bottom) this condition checked by loop
        if (left <= right)
            for (int i=bottom; i>=top; i--)
                res.push_back(matrix[i][left]);
        left++;
    }
    return res;
}