def num_substr(s):
    tracker = {'a' : 0, 'b' : 0, 'c' : 0}
    res = 0
    start = 0
    for i in range(0,len(s)):
        tracker[s[i]] += 1
        while tracker['a'] > 0 and tracker['b'] > 0 and tracker['c'] > 0:
            res += len(s) - i
            tracker[s[start]] -= 1
            start += 1
    return res


print(num_substr("abc"))
print(num_substr("abcabc"))
print(num_substr("aaabc"))
