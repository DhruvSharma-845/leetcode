#include <stack>
#include <utility>

class StockSpanner {
private:
    std::stack<std::pair<int, int>> priceIndices;
    int currentIndex = -1;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        ++currentIndex;
        while(!priceIndices.empty() && price >= priceIndices.top().first) {
            priceIndices.pop();
        }
        int topIndex = -1;
        if(!priceIndices.empty()) {
            topIndex = priceIndices.top().second;
        }
        priceIndices.push(std::make_pair(price, currentIndex));
        return currentIndex - topIndex;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */