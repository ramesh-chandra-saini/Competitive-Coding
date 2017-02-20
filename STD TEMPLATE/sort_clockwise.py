import math

def algo(x):
    return (math.atan2(x[0] - mlat, x[1] - mlng) + 2 * math.pi) % (2*math.pi)


n,d = raw_input().strip().split(' ')
n,d = [int(n),float(d)]
points ,i= [],1
for points_i in xrange(n):
    points_temp = map(float,raw_input().strip().split(' '))
    points_temp.append(i)
    points.append(points_temp)

mlat = sum(x[0] for x in points) / len(points)
mlng = sum(x[1] for x in points) / len(points)

points.sort(key=algo)
for i in points:
    print i[2]," ",
print
