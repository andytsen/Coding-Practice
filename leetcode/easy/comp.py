# Leetcode 
# Andy Tseng

def numSmallerByFrequency(queries, words):
    res = []
    for q in queries:
        q_cnt = 0;
        for word in words:
            if getSmallestCharFreq(q) < getSmallestCharFreq(word):
                q_cnt += 1
        res.append(q_cnt)
    return res


def getSmallestCharFreq(word):
    counts = {}
    for c in word:
        if c not in counts:
            counts[c] = 1
        else:
            counts[c] += 1
    smallest_char = min(counts.keys())
    return counts[smallest_char]
    

print(numSmallerByFrequency(["cbd"], ["zaaaz"]))
print(numSmallerByFrequency(["bbb", "cc"],["a", "aa", "aaa", "aaaa"]))

