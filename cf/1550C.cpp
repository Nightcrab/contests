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
    	
    Three points A,B,C are 'bad' if B lies in the rectangle bounded by A and C.

    A sequence S is good if no triples of (b_i, i) are bad.

    consider the points
    (b_i, i), (b_j, j), (b_k, k).

    wlog, let i < j < k.


    therefore we have

    --------- 
    * 
        *       bad
            *
    --------- 
    *   
            *   (1)
        *
    ---------
    *       *
                (2)
        *
    ---------


    other configurations are vertically or horizontally symmetric.

    so the triple is bad iff we have b_i <= b_j <= b_k or b_i => b_j => b_k.

    consider that a fourth point (b_l, l) is added to a good subarray.

    let Y = {b_i, b_j, b_k}

    if b_l \in Y the 4tuple is bad.

    Consider that there are 5 points in a good subarray.

    consider the first and last points A,B in the array.
    they must be vertically adjacent.
    otherwise a point between them would form a bad triple.

    the maximal and minimal points C, D must be horizontally adjacent.

    there is at least 1 point X which is not maximal or minimal in any way.

    it comes vertically between C and D and horizontally between A and B.

    wlog, let B be higher than A. 

    hence either X is higher than B or lower than A.

    if X is higher than B and to the right of D, D,X,B is bad.
    if X is higher than B and to the left of D, A,X,D is bad.
    if X is lower than A and to the left of C, A,X,C is bad.
    if X is lower than A and to the right of C, C,X,B is bad.

    hence such an array does not exist. we only need to check subarrays of length 3 and 4.

    since we have to solve for subarrays (O(n)) not subsequences (O(n^4)) brute force is perfectly fine.
  
    g++ -o 1550C.exe 1550C.cpp && 1550C.exe < 1550C.in  
*/

int d(pll a, pll b) {
    return abs((b.first - a.first)) + abs((b.second - a.second));
}

bool check_triple_bad(pll a, pll b, pll c) {
    if (d(a,c) == d(a,b) + d(b,c)) {
        return true;
    }
    return false;
}

void check_array_good (ll * a, int l, ll &count) {
    int tcount = 0;

    if (!check_triple_bad(make_pair(a[l],l+1), make_pair(a[l+1],l+2), make_pair(a[l+2],l+3))) { //XXXO
        tcount++;
        count++;
    }
    if (!check_triple_bad(make_pair(a[l],l+1), make_pair(a[l+1],l+2), make_pair(a[l+3],l+4))) { //XXOX
        tcount++;
    }
    if (!check_triple_bad(make_pair(a[l],l+1), make_pair(a[l+2],l+3), make_pair(a[l+3],l+4))) { //XOXX
        tcount++;
    }
    if (!check_triple_bad(make_pair(a[l+1],l+2), make_pair(a[l+2],l+3), make_pair(a[l+3],l+4))) { //OXXX
        count += (tcount == 3); //the whole subarray is good.
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    ll a[200000];

    while (t--)
    {
        int n;
        cin >> n;
        ll ans = n + n - 1;
        forn (i,n) {
            cin >> a[i];
        }
        if (n > 2) {
            for (int i=0;i<n-3;i++) {
                check_array_good(a, i, ans);
            }
            if (!check_triple_bad(make_pair(a[n-3],n-2), make_pair(a[n-2],n-1), make_pair(a[n-1],n))) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    cout << endl;
    return 0;
}