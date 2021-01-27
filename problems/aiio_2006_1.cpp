#include <bits/stdc++.h>
using namespace std;

/*
	problem description
	given a list of spies on an integer grid, place a package, minimising the sum of the manhattan distances from the spies to the package
	in:
	N
	x y
	x y
	...

	since we are using manhattan distance, x and y are independent. If we solve the problem for 1 dimension we are done.
	consider that the package is between two spies, with a spies to its left and b spies to its right. If it moves left the total distance increases by b and decreases by a. 
	wlog, let b >= a.
	Thus if the package is not on top of a spy, and b=/=a then we are suboptimal.
	If the package is on top of a spy, moving right will move us away from a+1 spies and toward b spies. This position is suboptimal unless N is odd and b=a or N is even and b=a+1.
	N is odd:
		on a spy:
			a=/=b:
				move
			else:
				stay
		not on a spy:
			move
	N even:
		on a spy:
			b = a+1:
				do nothing (1)
			else:
				move
		not on a spy:
			if a=b:
				do nothing (2)
			else:
				move
	note that sliding the package around between or on two adjacent spies does nothing to the total distance. Thus (1) and (2) are identical.
	In all cases the optimal solution is to place at the median x and median y.
*/

int middle (int a, int b) {
	int n = b - a;

	if (n % 2 == 0) {
		return a + n / 2;
	}
	else {
		return a + (n-1) / 2;
	}	
}

int b_insert (int a[], int b, int start, int end) {
	// a is already sorted
	// end is the first element not included. start = 0, end = n means we are working with n integers.
	int half = middle(start, end);
	if (end - start == 0) {
		return start;
	}

	if (b > a[half]) {
		return b_insert(a, b, half + 1, end);
	}
	else if (b == a[half]) {
		return half;
	}

	return b_insert(a, b, start, half);
}

void insert (int a[], int size, int b) {
	int k = b_insert(a, b, 0, size);
	for (int i = size + 1; i > k; i--) {
		a[i] = a[i-1];
	}
	a[k] = b;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ifstream in("spiesin.txt");
    ofstream out("spiesout.txt");

    int n, x, y;
    in >> n;
    cout << n << endl;

    int m = middle(0,n);

    int X [n];
    int Y [n];
    int c = -1;

    for (int i = 0; i < n; i++) {
    	in >> x >> y;
    	c++;
    	insert(X, c, x);
    	insert(Y, c, y);
    }

    out << X[m] << " " << Y[m] << "\n";
    cout << X[m] << " " << Y[m] << "\n";
    in.close(); 
    out.close();

    return 0;
}
