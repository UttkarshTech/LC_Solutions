int kthSmallest(vector<vector<int>>& matrix, int k) {
    int size = matrix.size();
    int l = matrix[0][0], h = matrix[size-1][size-1], mid;
    while(l <= h){
        mid = (l + h) / 2;
        int count = 0, j = size - 1;
        for(int i=0; i<size; i++){
            while(j>=0 && matrix[i][j]>mid)
                j--;
            count += j+1;
        }
        if(count < k)
            l = mid+1;
        else
            h = mid-1;
    }
    return l;
}


// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     priority_queue<int> pq;
//     for (auto row : matrix){
//         for (auto element : row){
//             pq.push(element);
//             if (pq.size() > k)
//                 pq.pop();
//         }
//     }
//     return pq.top();
// }