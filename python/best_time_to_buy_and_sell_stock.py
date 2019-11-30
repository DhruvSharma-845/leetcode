class StockMarket(object):

    def findMaxSubarray(self, diffs):
        #max_so_far = -maxsize - 1
        max_so_far = 0
        max_ending_here = 0

        start_point = -1
        end_point = -1

        for i in range(0, len(diffs)):
            max_ending_here = max_ending_here + diffs[i]
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here

            if max_ending_here < 0:
                max_ending_here = 0

        return max_so_far

    def maxProfit(self, prices) -> int:
        diffs = []
        for e in range(1, len(prices)):
            diffs.append(prices[e] - prices[e-1])

        return self.findMaxSubarray(diffs)


def main():
    stock_prices = [int(num) for num in input().split(" ")]
    sm = StockMarket()
    print(sm.maxProfit(stock_prices))


if __name__ == '__main__':
    main()
