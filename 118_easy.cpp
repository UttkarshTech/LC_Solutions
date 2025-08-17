vector<vector<int>> generate(int n) {
    vector<vector<int>> pascal;
    for (int i = 1; i <= n; i++) {
        vector<int> row;
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1)
                row.push_back(1);
            else
                row.push_back(pascal[i - 2][j - 1] + pascal[i - 2][j]);
        }
        pascal.push_back(row);
    }
    return pascal;
}