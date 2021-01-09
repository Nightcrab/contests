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
r = np

for x in range(len(inp) - (np + 1)):
	y = x + (np + 1)

	if x == l:
		giver = inp[y]

	if x == l+1:
		a,r = inp[y].split(" ")
		a,r = [int(a), int(r)]
		ac[giver] += divide(a,r)["r"] - a

	if x >= l + 2:
		ac[inp[y]] += divide(a,r)["q"]

	if x == l + r + 1:
		l = x + 1

out = ""

for x in range(np):
	out += inp[x+1] + " " + str(ac[inp[x+1]]) + "\n"

fout.write(str(out))
fout.close()