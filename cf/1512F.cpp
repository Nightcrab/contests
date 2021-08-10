#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*
	problem description
	
    in:
    t
    {
        n, c
        a
        b
    }

    consider that we have the ability to go from position P to position P+1.

    if we wait n days before moving to P+1, our total earnings will suffer by n*(a[P+1] - a[P]).
    hence if we want to get to position P+1 and make maximal earnings along the way, we should not hesitate to move from P to P+1. If we do hestitate, our total earnings is suboptimal.

    by backwards induction, this implies that we make the most money if we never hestitate to promote.

    hence it is a question of what position we stop at before trying to buy the computer.

    the minimum days to get to P is f(P). the remaining earnings is g(P).

    hence f(P+1) = f(P) + floor((b[P]-g(P))/a[P]).
    g(P+1) = {(b[P]-g(P))/a[P]}.

    V(P) = (c-g(P) / a[P]).

    we have a solution in O(n), which is to calculate f and g for all positions and then collect the minimum V(P).
*/


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