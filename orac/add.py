
finp = "addin.txt"
fout = "addout.txt"

with open(finp) as fi:
	inp = fi.readlines()

for i in range(len(inp)):
	inp[i] = inp[i].split(" ")

out = str(int(inp[0][0])+int(inp[0][1]))

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)