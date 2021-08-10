#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*

    in:
    
    n m k
    vertical edges (up)
    horizontal edges (to the right)

    we need to calculate, for each node, the shortest cycle in exactly k steps.

    djikstra's should find 1. the shortest distances between nodes 2. the shortest cycles

    note that if we have a cycle with minimum edge X, preceding path A and succeeding path B
    if B > A wlog, it is always more optimal to traverse A, then walk back and forth on X, then travel backwards along A.

    given fixed X, this is suboptimal if A is not the shortest path to X.

    Hence the optimal solution will consist of a shortest path from the start node to another node, and then a return journey along that path.

    If the path length exceeds floor(k/2) we terminate.

    using DP, we store lengths of minimum paths between nodes.
*/



void djikstra () {

}
int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--)
    {
    }

    cout << endl;
    return 0;
}