

def max_area(heights):
    p1 = 0
    p2 = len(heights) - 1
    area = 0
    hcur = 0
    while p1 != p2:
        if p1 > len(heights):
            break
        if p2 < 0:
            break
        cur_area = (p2 - p1) * (heights[p1] if heights[p2] > heights[p1] else heights[p2])
        if cur_area > area:
            print(p1,p2,heights[p1],heights[p2])
            area = cur_area
        if heights[p1] > heights[p2]:
            p2 -= 1
        else:
            p1 += 1

    return area


print(max_area([1,8,6,2,5,4,8,3,7]))



         

        


