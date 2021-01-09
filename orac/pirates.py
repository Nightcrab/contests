inp = "piratein.txt"

with open(inp) as fi:
	inp = fi.readlines()

L = int(inp[0])
x = int(inp[1])
y = int(inp[2])

try:
	fo = open("pirateout.txt", "x")
except:
	pass
fo = open("pirateout.txt", "w")

fo.write(str(min(x+y,(2*L-x-y))))