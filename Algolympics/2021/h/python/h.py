from math import gcd
from functools import reduce

s, t = map(int, input().split())
stars = []
telescopes = []

# get stars
for i in range(s):
    stars.append(list(map(int, input().split())))

# get telescopes
for i in range(t):
    telescopes.append(int(input()))

# output all stars telescope can see
for telescope in telescopes:
    stars_saw = 0
    star_vectors = set()
    for star in stars:
        # a = star[3] / (star[0] ** 2 + star[1] ** 2 + star[2] ** 2)
        d = (star[0] ** 2 + star[1] ** 2 + star[2] ** 2)
        print("Star:", star, "d:", d, "telescope sensitivity:", telescope)
        # check if star can be seen
        # 1. if star's gabisibility >= telescope sensitivity, visible
        if d * telescope <= star[3]:
            # 2. check if there is some star between it
            vector_divisor = reduce(gcd,(abs(star[0]),abs(star[1]),abs(star[2])))
            vector_direction = (star[0] // vector_divisor, star[1] // vector_divisor, star[2] // vector_divisor)
            print("Direction:", vector_direction, "Divisor:", vector_divisor)
            if vector_direction in star_vectors:
                print("Seen stars:", star_vectors)
                continue
            # no star between, so add to vector set and consider it seen
            else:
                star_vectors.add(vector_direction)
                stars_saw += 1
    print(stars_saw)
