def max_sum_three(nums):
    dp = [0,0,0]
    for n in nums:
        tmp = dp.copy()
        for x in dp:
            cur = x + n
            tmp[cur % 3] = max(cur, tmp[cur % 3])
        dp = tmp
    return dp[0]


print(max_sum_three([3,6,1,5,8]))
