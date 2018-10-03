# Leetcode: 

import os, sys

def bfs(deadends, target, cur, steps):
    if target == cur:
        return steps
    if cur in deadends:
        return 1000000
    minSteps = 0
    for i in range(0, len(target)):
        if target[i] != cur[i]:
            tmp = chr(int(cur[i]) + 1 % 9)
            minSteps = min(minSteps, bfs(deadends, target, cur[1:i] + tmp + cur[i + 1: len(cur)], minSteps + 1))
            tmp = chr(int(cur[i]) - 1 % 9)
            minSteps = min(minSteps, bfs(deadends, target, cur[1:i] + tmp + cur[i + 1: len(cur)], minSteps + 1))
    return steps + minSteps


def open_lock(deadends, target):
   bfs(deadends, target, '0000', 0) 

print(open_lock(["0201", "0101", "0102", "1212" "2002"], "2020"))

     


