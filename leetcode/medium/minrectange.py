


def minArea(points):
    minY = points[0][1]
    minX = points[0][0]

    if len(points) < 4:
        return 0

    for p in points:
        x = p[0]
        y = p[1]

    print(minX)
    print(minY)

minArea([[1,2], [3,3], [5,4], [3,0]])

