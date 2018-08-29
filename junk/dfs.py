



from collections import deque
def largest_blob(grid):
    max_blob = 0
    m = len(grid)
    n = len(grid[0])
    visited = set()
    q = deque()
    
    for i in range(m):
        for j in range(n):
            if (i,j) not in visited:
                original = grid[i][j]
                q.appendleft((i,j))
                visited.add((i,j))
                cur_blob = 0
                while q:
                    x,y = q.pop()
                    cur_blob += 1
                    neighbors = [ (x - 1, y), (x,y-1), (x + 1, y), (x,y+1)] 
                    for cand_x, cand_y in neighbors:
                        if (cand_x >= 0 and cand_x < m and cand_y >= 0 and cand_y < n
                                and (cand_x, cand_y) not in visited and grid[cand_x][cand_y] == original):
                            q.appendleft((cand_x, cand_y))
                            visited.add((cand_x,cand_y))
                max_blob = max(max_blob, cur_blob)    
    return max_blob

#TESTING
print(largest_blob([['r']]) == 1)
print(largest_blob([['r', 'r', 'd'], ['r', 'a', 'd']]) == 3)
print(largest_blob([['r', 'd', 'r', 'r'], ['a', 'b', 'r', 'r'], ['c', 'z', 'x', 'r']]) == 5)
