#      |
# AABABBA
# K = 1

# * |       
# ABABB
# K = 1

# AABA
# 





# s = string input, k = num of operations
def char_replacement_longest(s, k):
    if len(s) == 0:
        return 0
    start = 0
    index = 0
    ans = 0
    misses = 0
    cur_char = s[0]
    while index < len(s):
        print(index, start, cur_char)
        if s[index] != cur_char:
            misses += 1
            if misses > k:
                while s[start] == cur_char:
                    start += 1
                index = start
                cur_char = s[index]
                misses = 0
                continue;
        ans = max(ans, index - start + 1)
        index += 1
    return ans


print (char_replacement_longest("AABABBA", 1))
print("==========================")
print (char_replacement_longest("ABAB", 2))



