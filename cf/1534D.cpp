#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*
	We must infer the set of edges of an unweighted tree.

	At any time we can make a query k,
	and receive the set of the lengths of the shortest paths between k and each node in the tree.

	After one query we are able to find a 2 colouring of the tree.

	Note also that the parent node as well as all nodes below k have a distance of 1.

	We are given ceil(n/2) queries.

	If we query every node of colour min(A,B) we should be able to find every edge in the graph.

	solution is O(n^2)

	g++ -o 1534D.exe 1534D.cpp && 1534D.exe < 1534D.in
*/


vector<int> &minvec(vector<int> &a, vector<int> &b) {
	if (b.size() < a.size()) {
		return b;
	}
	else {
		return a;
	}
}
int main () {
    ios_base::sync_with_stdio(false);
    
    int n;
    int junk;
    cin >> n;

    int R[2000] = {0};
    vector<pair<int,int>> edges;
    vector<int> A;
    vector<int> B;

    cout << "? 1" << endl; 
    cout.flush();
    for (int i=0;i<n;i++) {
    	cin >> R[i];
    	if (R[i] % 2 == 0 && R[i] > 0) {
    		A.push_back(i);
    	}
    	else if (R[i] % 2 == 1) {
    		B.push_back(i);
    	}

    	if (R[i] == 1) {
    		edges.push_back(make_pair(0, i));
    	}
    }

    vector<int> &C = minvec(A,B);

    for (int i=0;i<C.size();i++) {
    	cout << "? " << C[i]+1 << endl;
    	cout.flush();
    	for (int j=0;j<n;j++) {
    		cin >> R[j];
    		if (j == 0) {
    			continue;
    		}
    		if (R[j] == 1) {
    			edges.push_back(make_pair(C[i], j));
    		}
    	}
    }

    cout << "!";

    for (int i=0;i<edges.size();i++) {
    	cout << "\n" << edges[i].first+1 << " " << edges[i].second+1;
    }
    cout << endl;
    cout.flush();
    return 0;
}
