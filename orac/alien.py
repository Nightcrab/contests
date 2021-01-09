
finp = "alienin.txt"
fout = "alienout.txt"

with open(finp) as fi:
    inp = []
    for line in fi:
        inp.append([int(x) for x in line.split(" ")])

N = inp[0][0]
W = inp[0][1]
d =[x[0] for x in inp][1:]

a = 0
b = 0
out = 0

for x in range(N):
	while (d[b] - d[a] >= W and b > a):
		a += 1
	b += 1
	if (b-a > out):
		out = b-a

out = str(out)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)