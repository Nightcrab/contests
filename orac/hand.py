
finp = "handin.txt"
fout = "handout.txt"

with open(finp) as fi:
    c = 0
    inp = []
    for line in fi:
        inp.append([int(x) for x in line.split(" ")])
        c += 1

N = inp[0][0]
S = inp[0][1]
K = inp[0][2]

n = S

m = inp[1:]

for x in range(K):
	i = m[x][0]
	f = m[x][1]
	if (i == n):
		n = f
		continue
	if ((i < n and f < n) or (i > n and f > n)):
		continue
	if (f < n):
		n += 1
		continue
	if (f == n and i < n):
		n -= 1
		continue
	if (f == n and i > n):
		n += 1
		continue
	if (f > n):
		n -= 1
out = n
out = str(out)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)