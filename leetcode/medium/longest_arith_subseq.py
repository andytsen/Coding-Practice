# Leetcode 1027
# Andrew Tseng

# Find the longest subsequence of A where  A_{i+1} - A_{i} are all the same
# values throughout.



def longest_arithmetic_subseq(nums):
    dp = [[0 for i in range(len(nums))] for j in range(len(nums))]
    diffs = [[0 for i in range(len(nums))] for j in range(len(nums))]
    for i in range(0, len(nums)):
        dp[i][i] = 0
        if (i + 1) < len(nums):
            dp[i][i + 1] = 1
            diffs[i][i+1] = nums[i+1] - nums[i]
    for i in range(0, len(nums) - 1):
        for j in range(i + 2, len(nums)):
            diffs[i][j] = nums[j] - nums[i]
             
    print(diffs)
    print(dp)

    return dp


longest_arithmetic_subseq([9,4,7,2,10])


