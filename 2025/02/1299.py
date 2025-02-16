from typing import List

def replaceElements(self, arr: List[int]) -> List[int]:
    m = -1
    for i in range(len(arr) - 1, -1, -1):
        t = arr[i]
        arr[i] = m
        if t > m:
                m = t
    return arr