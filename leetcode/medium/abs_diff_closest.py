import math

def closest_divisors(num):
    start = math.floor(math.sqrt(num))
    diff = num
    res = (1, num)
    for i in range(start, num + 2 + 1):
        if (num + 1) % i == 0:
            j = (num + 1) / i
            if math.fabs(i - j) < diff:
                diff = math.fabs(i-j)
                res = (i,j)
        if (num + 2) % i == 0:
            j = (num + 2) / i
            if math.fabs(i - j) < diff:
                diff = math.fabs(i-j)
                res = (i,j)
    return res

print(closest_divisors(8))
print(closest_divisors(123))
print(closest_divisors(999))
