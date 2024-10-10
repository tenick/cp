min_age = {'G': -float('inf'), 'PG': 13, 'R-13': 13, 'R-16': 16, 'R-18': 18}
age, rating = input().split()
print('OK' if int(age) >= min_age[rating] else 'OK IF ACCOMPANIED' if rating == 'PG' else 'ACCESS DENIED')
