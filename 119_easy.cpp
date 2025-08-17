vector<int> getRow(int rowIndex) {
    vector<int> row;
    if (rowIndex == 0){
        row.push_back(1);
        return row;
    } else if (rowIndex == 1){
        row.push_back(1);
        row.push_back(1);
        return row;
    } 
    row.push_back(1);
    row.push_back(1);
    for (int i=2; i<=rowIndex; i++){
        int cur = 1, prev;
        for (int j=0; j<i; j++){
            if (j==0 || j == i)
                row[j]= 1;
            else {
                prev = cur;
                cur = row[j];
                row[j] = prev + cur;
            }
        }
        row.push_back(1);
    }
    return row;
}