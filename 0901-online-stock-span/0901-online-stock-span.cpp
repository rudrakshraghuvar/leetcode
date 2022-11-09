class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int, int>> stck;
    int next(int price) {
        int ans = 1;
        while(!stck.empty() && stck.top().first <= price) {
            ans += stck.top().second;
            stck.pop();
        }
        
        stck.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */