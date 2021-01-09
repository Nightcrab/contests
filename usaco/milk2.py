"""
ID:  
LANG: PYTHON2
TASK: milk2
"""
fin = open('milk2.in', 'r')
fout = open('milk2.out', 'w')

inp = []

def read(s):
	return s.split(" ")

for line in fin:
	inp.append(read(line))

N = int(inp[0][0])

times = []
times_d = {}

for x in range(len(inp) - 1):
	if not int(inp[x+1][0]) in times_d:
		times_d[int(inp[x+1][0])] = 0
	if not int(inp[x+1][1]) in times_d:
		times_d[int(inp[x+1][1])] = 0
	times.append(int(inp[x+1][0]))
	times_d[int(inp[x+1][0])] += 1 
	times.append(int(inp[x+1][1]))
	times_d[int(inp[x+1][1])] -= 1 

times = list(set(times))
times.sort()

cows = 0
milk = 0
nomilk = 0
lastmilk = times[0]
lastnomilk = times[0]
time = 0 

for y in range(len(times)):

	print(cows,time)
	print(milk,nomilk)
	time = times[y]

	if cows == 0:
		lastmilk = time
		nomilk = max(nomilk,time - lastnomilk)
	else:
		lastnomilk = time
		milk = max(milk,time - lastmilk)

	print(cows,time)
	print(milk,nomilk)

	cows += times_d[times[y]]


out = str(milk)+" "+str(nomilk)

fout.write(str(out)+"\n")
fout.close()