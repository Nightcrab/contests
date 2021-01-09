
finp = "in.txt"
fout = "out.txt"

with open(finp) as fi:
	inp = fi.readlines()

for i in range(len(inp)):
	inp[i] = inp[i].split(" ")
inp = list(map(lambda x : list(map(lambda y : int(y), x)), inp))



out = ""
out = str(out)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)