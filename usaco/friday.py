"""
ID:  
LANG: PYTHON2
TASK: friday
"""
fin = open('friday.in', 'r')
fout = open('friday.out', 'w')

inp = []

for line in fin:
	inp.append(int(line))

def row(l):
	s = ""
	for x in range(len(l)):
		s += str(l[x]) + " "
	s = s[:-1]
	s += "\n"
	return s

N = inp[0]

months = [31,28,31,30,31,30,31,31,30,31,30,31]

date = 1
month = 0
year = 1900
leap = False

days = [0]*7

while year < 1900+N:
	leap = (year % 4 == 0 and not year % 100 == 0) or (year % 400 == 0)
	if leap:
		months[1] = 29
	else:
		months[1] = 28
	days[(date+13) % 7] += 1
	date += months[month]
	month = (month + 1) % len(months)
	if month == 0:
		year += 1

out = row(days)

fout.write(str(out))
fout.close()