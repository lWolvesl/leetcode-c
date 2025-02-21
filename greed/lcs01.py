import math

def least_minutes(n: int) -> int:
    if n == 0:
        return 0
    return math.ceil(math.log2(n)) + 1
