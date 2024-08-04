class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        prices.push_back(price);
        while(!st.empty() && prices[st.top()]<=price){
            st.pop();
        }
        if(st.empty()) {
            st.push(idx);
            idx++;
            return idx;
        }
        else{
            int ans = idx-st.top();
            st.push(idx);
            idx++;
            return ans;
        }
    }
};
