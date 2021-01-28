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

void heap_median (vector<int> &a, vector<int> &b, int c) {
	// a : max heap, b: min heap
	// a[0] is the largest number < the median
	// b[0]*-1 is the smallest number >= it
	if (c < a[0]) {
		a.push_back(c);
		push_heap(a.begin(),a.end());
	}
	else {
		b.push_back(-1*c);
		push_heap(b.begin(),b.end());
	}
	if (a.size() > b.size() + 1) {
		b.push_back(-1*a[0]);
		push_heap(b.begin(),b.end());
		pop_heap(a.begin(),a.end());
		a.pop_back();
	}
	else if (b.size() > a.size() + 1) {
		a.push_back(-1*b[0]);
		push_heap(a.begin(),a.end());
		pop_heap(b.begin(),b.end());
		b.pop_back();
	}

}

int get_median(vector<int> a, vector<int> b) {
	cout << a[0] << " " << b[0] << endl;
    if (a.size() > b.size()) {
    	return a[0];
    }
    else {
    	return b[0]*-1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ifstream in("spiesin.txt");
    ofstream out("spiesout.txt");

    int n, x, y;
    in >> n;

    vector<int> maxX, minX, maxY, minY; // heaps


    if (n < 4) {
    	int c = -1;
    	int X [n];
    	int Y [n];

    	int m = middle(0,n);

	    for (int i = 0; i < n; i++) {
	    	in >> x >> y;
	    	c++;
	    	insert(X, c, x);
	    	insert(Y, c, y);
	    }
	    out << X[m] << " " << Y[m] << "\n";
    }
    else {
    	int x1, y1, x2, y2;
    	in >> x1 >> y1 >> x2 >> y2;
    	minX.push_back(max(x1,x2)*-1);
    	maxX.push_back(min(x1,x2));
    	minY.push_back(max(y1,y2)*-1);
    	maxY.push_back(min(y1,y2));

	    for (int i = 0; i < n - 2; i++) {
	    	in >> x >> y;
	    	heap_median(maxX, minX, x);
	    	heap_median(maxY, minY, y);
	    }
	    out << get_median(maxX,minX) << " ";
	    out << get_median(maxY,minY) << "\n";
    }


    in.close(); 
    out.close();

    return 0;

}
