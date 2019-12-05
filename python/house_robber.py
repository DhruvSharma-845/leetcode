class HouseRobber(object):
    def __init__(self):
        self.dp_table = []

    def rob(self, nums) -> int:
        self.dp_table = [None]*(len(nums) + 1)
        return self.rob_util(nums, len(nums) - 1)

    def rob_util(self, nums, index):
        if index < 0:
            return 0

        if self.dp_table[index] is not None:
            return self.dp_table[index]

        res = max(self.rob_util(nums, index - 2) + nums[index], self.rob_util(nums, index - 1))
        self.dp_table[index] = res
        return self.dp_table[index]


def main():
    money = [int(x) for x in input().split(' ')]
    hr = HouseRobber()
    print(hr.rob(money))


if __name__ == '__main__':
    main()
