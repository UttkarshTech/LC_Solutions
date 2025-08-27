bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int low = 0, high = rows-1, chosenRow = -1, mid;
    while (low <= high){
        mid = low + (high-low)/2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] > target)
            high = mid - 1;
        else {
            if (matrix[mid][cols-1] == target)
                return true;
            else if (matrix[mid][cols-1] > target){
                chosenRow = mid;
                break;
            } else 
                low = mid + 1;
        }
    }
    if (chosenRow == -1)
        return false;
    low = 0; high = cols-1;
    while (low <= high){
        mid = low + (high-low)/2;
        if (matrix[chosenRow][mid] == target)
            return true;
        else if (matrix[chosenRow][mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return matrix[chosenRow][mid] == target;
}