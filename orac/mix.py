finp = "mixin.txt"
fout = "mixout.txt"

with open(finp) as fi:
	inp = fi.readlines()

for i in range(len(inp)):
	inp[i] = inp[i].split(" ")
inp = list(map(lambda x : list(map(lambda y : int(y), x)), inp))

def quo (a,b):
	return int((a - a%b)/b)

n = inp[0][0]
d = inp[0][1]

out = str(quo(n,d))

if n % d != 0:
	out +=" "+str(n%d)+"/"+str(d)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)