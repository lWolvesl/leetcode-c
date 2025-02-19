from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        res = 0
        n = len(arrays[0])
        min_val = arrays[0][0]
        max_val = arrays[0][n-1]

        for i in range(len(arrays)):
            n = len(arrays[i])
            res = max(res,max(abs(arrays[i][n-1]-min_val),abs(arrays[i][0]-max_val)))
            min_val = min(min_val,arrays[i][0])
            max_val = max(max_val,arrays[i][n-1])

        return res
