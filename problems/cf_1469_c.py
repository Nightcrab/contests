import sys
import operator as op
from functools import reduce
import timeit

def main():

	stdin = sys.stdin
	stdout = sys.stdout

	out = ""

	t1 = timeit.default_timer()

	""" problem description:
		in: n, k, H
		out: yes or no, if a fence can be built
		if a fence piece overlaps its neighbour by less than 1 the fence is invalid.
		the fence pieces have height k so this is equivalent to the piece's base being further than k-1 spaces below its neighbour
		solution 1 (dropping the fence from above):
			we want a fence where every piece is as low as possible.
			if a piece is too high, the only way to lower it is to lower the highest adjacent piece.
			=> there is no benefit to raising a piece to lower another.
			=> we always want to be lowering pieces (greedy)
		start with a straight fence at height max(H)
		lower every piece, in some order, until they can go no lower.

	"""

	l = 0

	n = 0
	k = 0
	h = []

	def fmax(a,b):
		if a > b:
			return a
		return max(a,b)

	def run_case(n,k,h):
		m = max(h)
		fence = [0] + [m]*n + [0]
		j = 0
		changes = True
		first_run = True
		while True:
			i = j 
			j = (i+1) % n
			l = i + 1 #use h[i] and fence[l] because fence has some padding
			new_pos = fmax(h[i],max(fence[l+1],fence[l-1]) - k + 1)
			
			if not new_pos - fence[l] == 0:
				fence[l] = new_pos #set the fence piece as low as possible
				changes = True
				continue
			if i == 0:
				if not changes: #changes has not been reset since we last visited i = 0.  if it is still unchanged then we are done. If this is the first iteration and the first fence is unchanged then changes defaults to True so we just keep going.
					break
				else:
					changes = False
			if first_run and i == n - 1:
				first_run = False #place this before the height diff check to avoid comparing first and last height values.
			if first_run and (h[j] > h[i] + 2*k + 1 or h[j] + 2*k + 1 < h[i]): # k = 2. h = [0,a]. f = [0,a,a,0] max for fence[1] is 0+2-1 = 1. min for fence[2] is a. if gap >= k we stop. aka, if h[1] - (h[0]+k-1) > k. h[1] > h[0] + 2*k + 1.
				return "no"

		for j in range(n):
			if fence[j+1]-h[j] >= k:
				return "no"

		if fence[1] > h[0] or fence[n] > h[n-1]:
			return "no"

		return "yes"
	
	for line in stdin.readlines():
		line = line.strip()
		if l == 0:
			t = int(line)
		elif l % 2 == 1:
			n,k = [int(x) for x in line.split(" ")]
		elif l % 2 == 0:
			h = [int(x) for x in line.split(" ")]
			out += run_case(n,k,h) + "\n"
		l += 1

	stdout.write(out)

	sys.stdout.close()

main()
