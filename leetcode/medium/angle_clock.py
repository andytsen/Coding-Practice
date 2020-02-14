
#
# 360 / 12 = 30
# 360 / 60 = 6
# 30 degrees
# every min the hour moves 0.5 angle
#

def angle_clock(hour,minute):
    h_angle = ((hour % 12) * 30) + (0.5 * minute)
    m_angle = (minute % 59) * 6
    ang = abs(m_angle - h_angle)
    return min(ang, 360 - ang)

print(angle_clock(3, 15))
print(angle_clock(12,30))
print(angle_clock(3, 30))
print(angle_clock(4, 50))

