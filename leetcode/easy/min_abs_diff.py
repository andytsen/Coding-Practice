
def min_abs_diff(arr):
    # arr is a list of ints
    arr.sort()
    min_diff = arr[len(arr)-1]
    res = []
    for i in range(0, len(arr) - 1):
        if arr[i+1] - arr[i] < min_diff:
            min_diff = arr[i+1] - arr[i]
    for i in range(0, len(arr) - 1):
        if arr[i+1] - arr[i] == min_diff:
            res.append( [arr[i], arr[i+1]] )
    return res


print(min_abs_diff([1,3,6,10]))
print(min_abs_diff([4,2,1,3]))




