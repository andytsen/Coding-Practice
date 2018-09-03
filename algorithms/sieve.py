# python script for it this time because why not
import math

def seive(n):
    # n : int
    res = []
    marks = [0] * (n + 1)
    for i in range(2, int(math.sqrt(n)) + 1 ):
        if marks[i] == 0:
            j = i * i
            while j <= n:
                marks[j] = 1;
                j = j + i
    for i in range(1, n):
        if marks[i] == 0:
            res.append(i)
    return res

# testing
print(seive(30))
print(seive(120))



