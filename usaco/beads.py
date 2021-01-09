"""
ID:  
LANG: PYTHON2
TASK: beads
"""
fin = open('beads.in', 'r')
fout = open('beads.out', 'w')

inp = []

def main():

	def read(s):
		return s

	for line in fin:
	    inp.append(read(line))

	n = int(inp[0])
	s = list(inp[1])

	m = 0

	def count(i, l, d):
		nl = l[:]
		if d == 1:
			i += 1
		k = i % n
		r = 0
		o_c = l[k]
		while (not l[k] == "c") and (l[k] == "w" or l[k] == o_c):
			r += 1
			nl[k] = "c"
			k += d
			k = k % n
			if k == i % n:
				break
		return [r,nl]

	def update(lc, m):
		l = count(x,lc,-1)
		r = count(x,l[1],1)
		m = max(m,l[0]+r[0])
		return m

	for x in range(len(s)):
		if s[x] == "w":
			lc = s[:]
			lc[x] = "r"
			m = update(lc,m)
			lc[x] = "b"
			m = update(lc,m)
			continue
		m = update(s,m)


	out = str(m) + "\n"
	return str(out)

fout.write(main())
fout.close()