int getMaxPos (vector<int> height){
    int max = INT_MIN, maxPos = -1;
    for (int i=0; i<height.size(); i++){
        if (max < height[i]){
            max = height[i];
            maxPos = i;
        }
    }
    return maxPos;
}
int trap(vector<int>& height) {
    int size = height.size(), i = 0, rwCollected = 0, maxPos = getMaxPos(height);
    if (height[maxPos] == 0)
        return 0;
    while (i < size && height[i] == 0)
        i++;
    stack<int> st;
    st.push(i++);
    for (; i<=maxPos; i++){
        if (!height[i])
            continue;
        if (height[i] < height[st.top()])
            rwCollected -= height[i];
        else {
            rwCollected += height[st.top()]*(i - st.top() - 1);
            st.push(i);
        }
    }
    while (!st.empty())
        st.pop();
    i = size - 1;
    while (i > 0 && height[i] == 0)
        i--;
    if (i == maxPos)
        return rwCollected;
    st.push(i--);
    for (; i>=maxPos; i--){
        if (!height[i])
            continue;
        if (height[i] < height[st.top()])
            rwCollected -= height[i];
        else {
            rwCollected += height[st.top()]*(st.top() - i - 1);
            st.push(i);
        }
    }
    return rwCollected;
}