vector<int> constructPrefix(vector<int> heights, int size) {
    vector<int> prefixRectangle(size, 0);
    stack<int> st;
    for (int i = 0; i < size; i++) {
        if (heights[i] == 0) {
            while (!st.empty())
                st.pop();
            st.push(i);
            prefixRectangle[i] = 1;
        } else if (st.empty()) {
            st.push(i);
            prefixRectangle[i] = 1;
        } else if (heights[i] > heights[st.top()]) {
            st.push(i);
            prefixRectangle[i] = 1;
        } else if (heights[i] == heights[st.top()]) {
            prefixRectangle[i] = prefixRectangle[i - 1] + 1;
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()])
                st.pop();
            if (st.empty()) {
                st.push(i);
                prefixRectangle[i] = i + 1;
            } else if (heights[i] == heights[st.top()]) {
                prefixRectangle[i] =
                    i - st.top() + prefixRectangle[st.top()];
                st.push(i);
            } else {
                prefixRectangle[i] = i - st.top();
                st.push(i);
            }
        }
    }
    return prefixRectangle;
}
vector<int> constructSuffix(vector<int> heights, int size) {
    vector<int> suffixRectangle(size, 0);
    stack<int> st;
    for (int i = size - 1; i >= 0; i--) {
        if (heights[i] == 0) {
            while (!st.empty())
                st.pop();
            st.push(i);
            suffixRectangle[i] = 1;
        } else if (st.empty()) {
            st.push(i);
            suffixRectangle[i] = 1;
        } else if (heights[i] > heights[st.top()]) {
            st.push(i);
            suffixRectangle[i] = 1;
        } else if (heights[i] == heights[st.top()]) {
            suffixRectangle[i] = suffixRectangle[i + 1] + 1;
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()])
                st.pop();
            if (st.empty()) {
                st.push(i);
                suffixRectangle[i] = size - i;
            } else if (heights[i] == heights[st.top()]) {
                suffixRectangle[i] =
                    st.top() - i + suffixRectangle[st.top()];
                st.push(i);
            } else {
                suffixRectangle[i] = st.top() - i;
                st.push(i);
            }
        }
    }
    return suffixRectangle;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> histoMatrix;
    vector<int> histoRow(cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                histoRow[j]++;
            else
                histoRow[j] = 0;
        }
        histoMatrix.push_back(histoRow);
    }

    int maxArea = -1;
    for (int i = 0; i < rows; i++) {
        vector<int> prefixRectangle = constructPrefix(histoMatrix[i], cols);
        vector<int> suffixRectangle = constructSuffix(histoMatrix[i], cols);
        for (int j = 0; j < cols; j++) {
            int area = histoMatrix[i][j] * (prefixRectangle[j] + suffixRectangle[j] - 1);
            if (area > maxArea)
                maxArea = area;
        }
    }
    return maxArea;
}