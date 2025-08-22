long long maximumSumOfHeights(vector<int>& maxHeights) {
    int size = maxHeights.size();
    stack<long long> st;
    vector<long long> prefixBeauty(size, 0);
    vector<long long> suffixBeauty(size, 0);
    prefixBeauty[0] = maxHeights[0];
    st.push(0);
    // constructing prefixBeauty vector
    for (int i = 1; i < size; i++) {
        if (st.empty() || maxHeights[i] >= maxHeights[st.top()]) {
            st.push(i);
            prefixBeauty[i] = prefixBeauty[i - 1] + maxHeights[i];
        } else {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()])
                st.pop();
            if (st.empty())
                prefixBeauty[i] = (long long)maxHeights[i] * (i + 1);
            else
                prefixBeauty[i] = (long long)prefixBeauty[st.top()] +
                                    (long long)maxHeights[i] * (i - st.top());
            st.push(i);
        }
    }
    while (!st.empty())
        st.pop();
    st.push(size - 1);
    suffixBeauty[size - 1] = maxHeights[size - 1];
    // constructing suffixBeauty vector
    for (int i = size - 2; i >= 0; i--) {
        if (st.empty() || maxHeights[i] >= maxHeights[st.top()]) {
            st.push(i);
            suffixBeauty[i] = suffixBeauty[i + 1] + maxHeights[i];
        } else {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()])
                st.pop();
            if (st.empty())
                suffixBeauty[i] =
                    (long long)maxHeights[i] * (size - 1 - i + 1);
            else
                suffixBeauty[i] = (long long)suffixBeauty[st.top()] +
                                    (long long)maxHeights[i] * (st.top() - i);
            st.push(i);
        }
    }
    long long maxBeauty = 0;
    // considering each element as the peak and checking for the best option
    // (minimal reduction) (maximal sum)
    for (int i = 0; i < size; i++) {
        long long x = prefixBeauty[i] + suffixBeauty[i] - maxHeights[i];
        if (x > maxBeauty)
            maxBeauty = x;
    }
    return maxBeauty;
}