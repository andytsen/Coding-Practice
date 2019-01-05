# leetcode: https://leetcode.com/problems/asteroid-collision/description/
# Andy Tseng

def asteroid_collisions(asteroids):
    pos = []
    neg = []
    for a in asteroids:
        if a < 0:
            while len(pos) > 0:
                if pos[len(pos) - 1] < abs(a):
                    pos.pop()


