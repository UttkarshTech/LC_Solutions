vector<int> constructPrefix(vector<int> heights, int size){
    vector<int> prefixRectangle (size, 0);
    stack<int> st;
    for (int i=0; i<size; i++){
        if (heights[i] == 0){
            while (!st.empty())
                st.pop();
            st.push(i);
            prefixRectangle[i] = 1;
        }
        else if (st.empty()){
            st.push(i);
            prefixRectangle[i] = 1;
        }
        else if (heights[i] > heights[st.top()]){
            st.push(i);
            prefixRectangle[i] = 1;
        } else if (heights[i] == heights[st.top()]) {
            prefixRectangle[i] = prefixRectangle[i-1] + 1;
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()])
                st.pop();
            if (st.empty()){
                st.push(i);
                prefixRectangle[i] = i+1;
            } else if (heights[i] == heights[st.top()]){
                prefixRectangle[i] = i - st.top() + prefixRectangle[st.top()];
                st.push(i);
            }
            else {
                prefixRectangle[i] = i - st.top();
                st.push(i);
            }
        }
    }
    return prefixRectangle;
}
vector<int> constructSuffix(vector<int> heights, int size){
    vector<int> suffixRectangle (size, 0);
    stack<int> st;
    for (int i=size-1; i>=0; i--){
        if (heights[i] == 0){
            while (!st.empty())
                st.pop();
            st.push(i);
            suffixRectangle[i] = 1;
        }
        else if (st.empty()){
            st.push(i);
            suffixRectangle[i] = 1;
        }
        else if (heights[i] > heights[st.top()]){
            st.push(i);
            suffixRectangle[i] = 1;
        } else if (heights[i] == heights[st.top()]) {
            suffixRectangle[i] = suffixRectangle[i+1] + 1;
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()])
                st.pop();
            if (st.empty()){
                st.push(i);
                suffixRectangle[i] = size - i;
            } else if (heights[i] == heights[st.top()]){
                suffixRectangle[i] = st.top() - i + suffixRectangle[st.top()];
                st.push(i);
            }
            else {
                suffixRectangle[i] = st.top() - i;
                st.push(i);
            }
        }
    }
    return suffixRectangle;
}
int largestRectangleArea(vector<int>& heights) {
    int size = heights.size();
    if (size == 0)
        return 0;
    vector<int> prefixRectangle = constructPrefix(heights, size);
    vector<int> suffixRectangle = constructSuffix(heights, size);
    int maxArea = -1;
    for (int i=0; i<size; i++){
        int area = heights[i] * (prefixRectangle[i] + suffixRectangle[i] - 1);
        if (area > maxArea)
            maxArea = area;
    }
        
    return maxArea;
}