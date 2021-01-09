import timeit

finp = "spiesin.txt"
fout = "spiesout.txt"

inp = []
x = []
y = []

"""
with open(finp) as fi:
    inp = fi.read().split()
    n = int(inp[0])
    x = [0]*n
    y = [0]*n
a = 0
b = 0
c = 0
inp = inp[1:]
for k in inp:
    if c % 2 == 0:
        x[a] = int(k)
        a += 1
    else:
        y[b] = int(k)
        b += 1
    c += 1"""


with open(finp) as fi:
    i = 0
    for line in fi:
    	n = int(line.split()[0])
    	x = [0]*n
    	y = [0]*n
    	first = False
    	break  

    #l = fi.readlines()
    t1 = timeit.default_timer()
    l = fi.readlines()
    for line in l:
        #print(line)
        #x[i],y[i] = line.split()
        #x[i],y[i] = [int(x[i]), int(y[i])]
    	#x[i], y[i] = [int(k) for k in line.split(" ")]
        #x[i], y[i] = map(int, line.split(" "))
        i += 1
    #x = map(lambda l : l.split(" "),fi)
    #i += 1
    #l = line.split(" ")
    #x, y = [[int(k) for k in line.split(" ")] for line in fi]

t2 = timeit.default_timer()

def gt(a,b):
    c,d = [len(a),len(b)]
    if (c > d):
        return a > b

def middle(seq):
	k = len(seq)
	if k % 2 == 0:
		return seq[int(k/2)]
	else:
		return seq[int(float(k-1)/2-0.5)]

def quickselect_median(l, pivot_fn=middle):
    if len(l) % 2 == 1:
        return quickselect(l, len(l) / 2, pivot_fn)
    else:
        return (quickselect(l, len(l) / 2 - 1, pivot_fn))

def quickselect(l, k, pivot_fn):
    """
    Select the kth element in l (0 based)
    :param l: List of numerics
    :param k: Index
    :param pivot_fn: Function to choose a pivot, defaults to random.choice
    :return: The kth element of l
    """
    if len(l) == 1:
        assert k == 0
        return l[0]

    pivot = pivot_fn(l)

    lows = [el for el in l if el < pivot]
    highs = [el for el in l if el > pivot]
    pivots = [el for el in l if el == pivot]

    if k < len(lows):
        return quickselect(lows, k, pivot_fn)
    elif k < len(lows) + len(pivots):
        # We got lucky and guessed the median
        return pivots[0]
    else:
        return quickselect(highs, k - len(lows) - len(pivots), pivot_fn)

def median_of_medians(elems):
    sublists = [elems[j:j+5] for j in range(0, len(elems), 5)]
    medians = []
    for sublist in sublists:         
        medians.append(sorted(sublist)[len(sublist)/2])     
        if len(medians) <= 5:         
            return sorted(medians)[len(medians)/2]     
        else:         
            return median_of_medians(medians) 

x = quickselect_median(x)
y = quickselect_median(y)

t3 = timeit.default_timer()

out = str(x) + " " + str(y)
print(out)
print(t2-t1)
print(t3-t2)

try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)