"""
ID:  
LANG: PYTHON2
TASK: gift1
"""
fin = open('gift1.in', 'r')
fout = open('gift1.out', 'w')

inp = []

for line in fin:
    inp.append(line.strip("\n"))

np = int(inp[0])
ac = {}

for x in range(np):
	ac[inp[x+1]] = 0 

def divide(a,b):
	if a == 0 or b == 0:
		return {
			"q" : 0,
			"r" : 0
		}
	return {
		"q" : (a - a % b)//b,
		"r" : a % b
	}

l = 0
r = -2

for x in range(len(inp) - (np + 1)):
	y = x + (np + 1)

	if x == l + r + 2:
		l = x
		giver = inp[y]
		continue

	if x == l+1:
		a,r = inp[y].split(" ")
		a,r = [int(a), int(r)]
		ac[giver] += divide(a,r)["r"] - a
		continue

	ac[inp[y]] += divide(a,r)["q"]

out = ""

for x in range(np):
	out += inp[x+1] + " " + str(ac[inp[x+1]]) + "\n"

fout.write(str(out))
fout.close()