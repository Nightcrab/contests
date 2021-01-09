import random

N = 100000
fout = "spiesin.txt"

out = str(N) + "\n"

for i in range(100000-1):
	out += str(random.randrange(20000)) + " " + str(random.randrange(20000)) + "\n"

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)