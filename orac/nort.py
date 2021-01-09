finp = "nortin.txt"
fout = "nortout.txt"

with open(finp) as fi:
	inp = fi.readlines()

inp = inp[0]
inp = [int(inp.split(" ")[0]),int(inp.split(" ")[1])]

if (inp[0] % 2 == 1 and inp[1] % 2 == 1):
	out = inp[0]*inp[1]-1
else:
	out = inp[0]*inp[1]
out = str(out)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)