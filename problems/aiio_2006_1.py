
finp = "spiesin.txt"
fout = "spiesout.txt"

inp = []
x = []
y = []

with open(finp) as fi:
    i = 0
    for line in fi:
    	n = int(line.split()[0])
    	x = [0]*n
    	y = [0]*n
    	first = False
    	break  
    for line in fi:
        x[i],y[i] = line.split()
        x[i],y[i] = [int(x[i]), int(y[i])]
        i += 1

def middle(seq):
	k = len(seq)
	if k % 2 == 0:
		return seq[(k-1)/2]
	else:
		return seq[int(float(k-1)/2-0.5)]

def quickselect_median(l, pivot_fn=middle):
    if len(l) % 2 == 1:
        return quickselect(l, len(l) / 2, pivot_fn)
    else:
        return (quickselect(l, len(l) / 2 - 1, pivot_fn))

def quickselect(l, k, pivot_fn):
    """
    Select the kth element in l
    :l: list
    :k: index
    :pivot_fn: Function to choose a pivot
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

out = str(x) + " " + str(y)
try:
	fo = open(fout, "x")
except:
	pass
fo = open(fout, "w")

fo.write(out)