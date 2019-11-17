class InterleavingString:
    def __init__(self):
        pass

    def memoizedValue(self, s1_index, s2_index, s3_index, memoizedTable):
        if s3_index in memoizedTable:
            if s1_index in memoizedTable[s3_index]:
                if s2_index in memoizedTable[s3_index][s1_index]:
                    return memoizedTable[s3_index][s1_index][s2_index]
        return None

    def setMemoizedValue(self, s1_index, s2_index, s3_index, memoizedTable, val):
        if s3_index not in memoizedTable:
            memoizedTable[s3_index] = {}

        if s1_index not in memoizedTable[s3_index]:
            memoizedTable[s3_index][s1_index] = {}

        memoizedTable[s3_index][s1_index][s2_index] = val


    def isInterleaveUtil(self, s1: str, s2: str, s3: str, s1_index, s2_index, s3_index, memoizedTable: object):

        val = self.memoizedValue(s1_index, s2_index, s3_index, memoizedTable)
        if val is not None:
            return val

        if s1_index < 0 and s2_index < 0 and s3_index < 0:
            return True

        if s1_index >= 0 and s2_index >= 0 and s1[s1_index] == s2[s2_index] and s1[s1_index] == s3[s3_index]:
            r1 = self.isInterleaveUtil(s1, s2, s3, s1_index - 1, s2_index, s3_index - 1, memoizedTable)
            r2 = self.isInterleaveUtil(s1, s2, s3, s1_index, s2_index - 1, s3_index - 1, memoizedTable)
            self.setMemoizedValue(s1_index, s2_index, s3_index, memoizedTable, r1 or r2)
            return r1 or r2

        if s1_index >= 0 and s1[s1_index] == s3[s3_index]:
            r1 = self.isInterleaveUtil(s1, s2, s3, s1_index - 1, s2_index, s3_index - 1, memoizedTable)
            self.setMemoizedValue(s1_index, s2_index, s3_index, memoizedTable, r1)
            return r1
        elif s2_index >= 0 and s2[s2_index] == s3[s3_index]:
            r2 = self.isInterleaveUtil(s1, s2, s3, s1_index, s2_index - 1, s3_index - 1, memoizedTable)
            self.setMemoizedValue(s1_index, s2_index, s3_index, memoizedTable, r2)
            return r2

        return False

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        memoizedTable = {}
        return self.isInterleaveUtil(s1, s2, s3, len(s1) - 1, len(s2) - 1, len(s3) - 1, memoizedTable)


def main():
    s1 = input()
    s2 = input()
    s3 = input()

    isObj = InterleavingString()
    print(isObj.isInterleave(s1, s2, s3))


if __name__ == "__main__":
    main()
