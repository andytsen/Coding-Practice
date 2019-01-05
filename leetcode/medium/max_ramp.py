


def maxRamp(arr):
    width = 0
    minIndex = len(arr) * 2;
    for i in sorted(range(len(arr)), key = arr.__getitem__):
        width = max(width, i - minIndex)
        minIndex = min(i, minIndex)  
    return width

print(maxRamp([9,8,1,0,1,9,4,0,4,1]))
