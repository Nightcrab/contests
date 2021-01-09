import sys
import operator as op
from functools import reduce
import timeit

def main():

	stdin = sys.stdin
	stdout = sys.stdout

	t1 = timeit.default_timer()

	X = []

	out = ""
	c = 0
	l = 0
	t = 0

	"""problem description
		https://codeforces.com/problemset/problem/1462/E1
		
		given: a sequence of integers, X. min(X)>=1. max(X)<=len(X)
		out: the number of non-unique 3-tuples spanning a width no larger than 2. (1,1,3) is ok. (1,1,4) is not.
		note that [1,1,1] and [1,1,1] are counted as separate solutions if X contains four 1s.

		in format:
			#test cases
			( test case
				n
				sequence a
			)
		solution 1, O(n)? but for unfixed k and m, it generalises better than solution 2: 
			W = [ 2-tuples Y such that width(Y) <= 2 ]
			iterate W for Y:
				Z[Y] = |{x in X/{Y_1,Y_2} : x is in the interval [Y_1,Y_2]}|. 
				total += Z[Y]
		solution 2, O(n):
			the only possible unique tuples are
			1 (x,x+1,x+1) -> a * (b choose 2)
			2 (x,x+1,x+2) -> a * b * c
			3 (x,x+2,x+2) -> a * (c choose 2)
			4 (x,x,x+1) -> (a choose 2) * b
			5 (x,x,x+2) -> (a choose 2) * c
			6 (x,x,x) ->  (a choose 3)

			def choose(n,k)
				if k > n
					return 0
				else
					return nCk

			let X = dict {x : # of occurences}
			iterate X for x:
				a = X[x]
				b = X[x+1]
				c = X[x+2]
				//better than a switch case or set of conditions is to add all the cases at once, with invalid cases (where x+1 or x+2 is not present in sufficient quantity) already being equal to 0.
				total += (sum of all cases)
	"""

	def ncr(n, r):
	    r = min(r, n-r)
	    numer = reduce(op.mul, range(n, n-r, -1), 1)
	    denom = reduce(op.mul, range(1, r+1), 1)
	    return numer // denom  # if Python 2, use /

	def choose(n,k):
		if k > n:
			return 0
		if k == n:
			return 1
		return ncr(n,k)

	def case(X):
		 #note indexes of X are 1 behind the corresponding numbers in A
		if len(X) < 3:
			return 0
		recent = [X[0],X[1],choose(X[0],2),choose(X[1],2)] #at the end of the loop, populate with b,c,bC2,cC2. at the start of the loop, read out a,b,aC2,bC2
		total = 0
		for x in range(len(X)-2):
			a,b,c = recent[0], recent[1], X[x+2] 
			aC2, bC2 = recent[2], recent[3]
			cC2 = choose(c,2)
			total += a*bC2 + a*b*c + a*cC2 +  aC2*(b+c) + choose(a,3) #uhhh we can use DP maybe edit: we tried to use DP lol
			recent = [b,c,bC2,cC2]
		return total

	"""
	known for case x = n: 
		T = a*choose(b,2) + a*b*c + a*choose(c,2) +  choose(a,2)*(b+c) + choose(a,3) #need to calculate aC2,bC2,cC2,aC3
	case x = n+1:
		new a = b
		new b = c
		new c = X[x+3] = d
		=> T = b*choose(c,2) + b*c*d + a*choose(d,2) +  choose(b,2)*(c+d) + choose(b,3) # the only thing we need to calculate per loop is choose(d,2) and choose(b,3)
		in recent we want: b, c, bC2, cC2
	"""

	for line in stdin.readlines():
		line = line.strip()
		if l == 0:
			t = int(line)
		elif l % 2 == 1:
			X = [0]*(int(line)+2)
		else:
			a = (int(x) for x in line.split())
			for i in a:
				X[i-1] += 1
			out += str(case(X)) + "\n"
		l += 1


	stdout.write(out)

	sys.stdout.close()

main()