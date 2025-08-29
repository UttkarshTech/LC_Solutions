long long countBadPairs(vector<int>& elements) {
    long long size = elements.size();
    if (size <= 1)
        return 0;

    unordered_map<int, int> diffFreq;
    long long matchingPairs = 0;

    for (int i = 0; i < size; ++i) {
        int key = i - elements[i];
        matchingPairs += diffFreq[key];
        diffFreq[key]++;
    }

    long long allPairs = size * (size - 1) / 2;
    return allPairs - matchingPairs;
}