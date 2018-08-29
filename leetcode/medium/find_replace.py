# Find and Replace in Leetcode
# https://leetcode.com/problems/find-and-replace-pattern/description/


def findAndReplacePattern(self, words, pattern):
    res = []
    for w in words:
        mapping = {}
        if w.len() == pattern.len():
            for wc in range(1,w.len()): 

