

class StockMarketForTwoStocks(object):

    def maxProfit(self, prices) -> int:
        sz = len(prices)
        if sz == 0:
            return 0

        profit = [0]*sz

        max_ele = prices[sz - 1]
        for i in range(sz - 2, -1, -1):
            if prices[i] > max_ele:
                max_ele = prices[i]
            profit[i] = max(profit[i+1], max_ele - prices[i])

        min_ele = prices[0]
        for i in range(1, sz):
            if prices[i] < min_ele:
                min_ele = prices[i]
            profit[i] = max(profit[i-1], profit[i] + (prices[i] - min_ele))

        return profit[sz - 1]

def main():
    stock_prices = [int(num) for num in input().split(" ")]
    sm = StockMarketForTwoStocks()
    print(sm.maxProfit(stock_prices))


if __name__ == '__main__':
    main()
