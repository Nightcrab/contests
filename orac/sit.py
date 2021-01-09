
finp = "sitin.txt"
fout = "sitout.txt"

with open(finp) as fi:
	inp = fi.readlines()

for i in range(len(inp)):
	inp[i] = inp[i].split(" ")
inp = list(map(lambda x : list(map(lambda y : int(y), x)), inp))

m = inp[0][0]
n = inp[0][1]
p = inp[1][0]

if m*n > p:
	out = str(p)+" 0"
else:
	out = str(m*n)+" "+str(p-m*n)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)