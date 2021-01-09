"""
ID:  
LANG: PYTHON2
TASK: ride
"""

from functools import reduce

fin = open('ride.in', 'r')
fout = open('ride.out', 'w')

inp = []

def read(s):
	return s

for line in fin:
    inp.append(read(line).strip("\n"))
inp = [reduce(lambda a,b : a*(ord(b) - 64), l, 1) for l in inp]
print(inp)
x = inp[0] % 47 == inp[1] % 47
out = "GO"*int(x) + "STAY"*int(not x)

fout.write(str(out)+"\n")
fout.close()