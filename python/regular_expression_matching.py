class RegularExpression(object):

    def __init__(self, _input: str, _pattern: str):
        self.input = _input
        self.pattern = _pattern
        self.memoization_table = []

        self.input_length = len(_input)
        self.pattern_length = len(_pattern)
        for i in range(0, self.input_length + 1):
            self.memoization_table.append([])
            for j in range(0, self.pattern_length + 1):
                self.memoization_table[i].append(None)

    def is_match_util(self, input_index, pattern_index) -> bool:

        if pattern_index == -1 and input_index == -1:
            return True

        if pattern_index == -1:
            return False

        if self.memoization_table[input_index + 1][pattern_index + 1] is not None:
            return self.memoization_table[input_index + 1][pattern_index + 1]

        if input_index == -1:
            res: bool = True
            # checking for pairs of (character and '*')
            i = pattern_index
            for i in range(pattern_index, 0, -2):
                if self.pattern[i] != '*':
                    res = False
                    break

            if i == 0 and self.pattern[i] != '*':
                res = False
            if i == 2 and self.pattern[i-2] != '*':
                res = False

            self.memoization_table[input_index + 1][pattern_index + 1] = res
            return self.memoization_table[input_index + 1][pattern_index + 1]

        if self.pattern[pattern_index] == '.' or self.input[input_index] == self.pattern[pattern_index]:
            res = self.is_match_util(input_index - 1, pattern_index - 1)
            self.memoization_table[input_index + 1][pattern_index + 1] = res
            return self.memoization_table[input_index + 1][pattern_index + 1]

        elif self.pattern[pattern_index] == '*':
            res: bool = False
            if pattern_index > 0:
                if self.pattern[pattern_index - 1] == '.' or self.pattern[pattern_index - 1] == self.input[input_index]:
                    res = res or self.is_match_util(input_index - 1, pattern_index)
                res = res or self.is_match_util(input_index, pattern_index - 2)

            self.memoization_table[input_index + 1][pattern_index + 1] = res
            return self.memoization_table[input_index + 1][pattern_index + 1]

        self.memoization_table[input_index + 1][pattern_index + 1] = False
        return self.memoization_table[input_index + 1][pattern_index + 1]

    @property
    def is_match(self) -> bool:
        if self.pattern_length == 0 and self.input_length == 0:
            return True
        if self.pattern_length == 0:
            return False
        if self.input_length == 0:
            return self.is_match_util(-1, len(self.pattern) - 1)
        return self.is_match_util(len(self.input) - 1, len(self.pattern) - 1)


def main():
    inp = input()
    pattern = input()

    reg = RegularExpression(inp, pattern)
    print(reg.is_match)


if __name__ == "__main__":
    main()
