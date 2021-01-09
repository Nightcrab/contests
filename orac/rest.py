
finp = "restin.txt"
fout = "restout.txt"

with open(finp) as fi:
	inp = fi.readlines()

for i in range(len(inp)):
	inp[i] = inp[i].split(" ")

inp = list(map(lambda x : list(map(lambda y : int(y), x)), inp))

N = inp[0][0]
A = inp[0][1]
B = inp[0][2]

d = inp[1:]
d = list(filter(lambda x: x[0] > 0 or x[1] > 0, d))
a = []

c1 = 0
c2 = 0

""" greedy algo
for i in range(len(d)):
	d[i].append(0)
	if c1 < A and d[i][0] > d[i][1]:
		d[i][2] = 1
		c1 += 1
	else:
		d[i][2] = 0
		c2 += 1"""
#sort by net gain

h = 0
d.sort(key=lambda x : x[1]-x[0])
print(d)
for i in range(len(d)):
	if (i < c1):
		d[i][2] = 1
		h += d[i][0]
	else:
		d[i][2] = 0
		h += d[i][1]

print(d)
out = str(h)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)