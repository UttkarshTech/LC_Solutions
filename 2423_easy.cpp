bool equalFrequency(string word) {
    int freq[26] = {0};
    for (int i = 0, n = word.length(); i < n; ++i)
        freq[word[i] - 'a']++;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] != 0) {
            freq[i]--;
            unordered_set<int> s;
            for (int f : freq) {
                if (f > 0)
                    s.insert(f);
            }
            if (s.size() == 1)
                return true;
            ++freq[i];
        }
    }
    return false;
}