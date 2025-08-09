void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    mergeSort(nums1, 0, nums1.size()-1);
    mergeSort(nums2, 0, nums2.size()-1);
    
    vector<int> inter;
    int i=0, j=0;
    while (i < nums1.size() && j < nums2.size()){
        if (nums1[i] == nums2[j]){
            inter.push_back(nums1[i]);
            i++; j++;
        } else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return inter;
}