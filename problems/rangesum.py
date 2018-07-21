"""
Interviewing.io Question from Showcase section
Andy Tseng
Range Sum, 

given an intger array, given an integer k for range sum, calculate the range sum array. 

For example, [1, 2, 3, 4, 5], k = 3, 
SumArray[0] = 1 + 2 + 3
SumArray[1] = 2 + 3 + 4
..


"""

def sum_array(arr, k):
    length = len(arr)
    if length < k:
        return -1 # bad input
    left = 0
    right = k
    rangesum = [0] * len(arr)
    
    for i in range(k, len(arr)):
        rangesum[i] = rangesum[i-1] - arr[left] + (arr[right] if i < (len(arr) - k + 1) else 0)
        left += 1
        right += 1


    return rangesum
    
print("Range Sum")
arr = [1,2,3,4,5]
print(sum_array(arr,3))


" 
