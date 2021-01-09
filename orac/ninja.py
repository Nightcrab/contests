import random

finp = "ninjain.txt"
fout = "ninjaout.txt"

with open(finp) as fi:
    inp = []
    for line in fi:
        inp.append([int(x) for x in line.split(" ")])

N = inp[0][0]
K = inp[0][1]
r = N % (K+1)

out = int(K*(N - r)/(K+1) + (r>0)*(r-1))

out = str(out)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)