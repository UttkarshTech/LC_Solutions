class StockSpanner {
public:
    vector<int> priceHistory;
    stack<int> st;
    StockSpanner() {}
    
    int next(int price) {
        priceHistory.push_back(price);
        int size = priceHistory.size();
        if (st.empty() || price < priceHistory[st.top()]){
            st.push(size-1);
            return 1;
        } else {
            int span;
            while (!st.empty() && price >= priceHistory[st.top()])
                st.pop();
            if (st.empty())
                span = size;
            else 
                span = size - 1 - st.top();
            st.push(size-1);
            return span;
        }
    }
};