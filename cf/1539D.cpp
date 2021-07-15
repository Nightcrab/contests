#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define ll long long int

/*
	problem description

	in:
		sequence A. 
		sequence B.

	During each turn, we buy a product i which will cost 1 or 2.
	i costs 1 iff N >= B[i], where N is the current turn number.
	N_0 = 0.

	We must buy A[i] of product i and minimise cost.

	sol 1:

	Consider a greedy solution where we always buy the product with the least B[i].
	
	let k = min(B).

	For the first k turns, all prices are 2.
	Consider that we have some optimal solution.
	Consider a purchase of item i at turn N.
	If the price of i was 1, then on this turn, if we buy any needed item with price 1, we will definitely also buy i later at a price of 1. hence solution is unchanged.
	If the price of i was 2, consider that we buy the needed item j with B[j] = max(B) on turn N, and i at a later turn N'. 
	The solution was optimal, hence i must cost 2 on turn N' (B[i] < N' would imply this is a better solution). 
	Hence j costs 2 on turn N' hence both cost 2 on N and N'. Hence the solution is unchanged. 

		
	Therefore if we always buy:
	1. a needed item with price 1
	2. the needed item j with greatest B.

	the solution is optimal.

    cmd
        g++ -o pricefixed2.exe pricefixed2.cpp && pricefixed2.exe < pricefixed.in 
*/

bool compare (pair<ll,ll> &i, pair<ll,ll> &j) {
	return i.second < j.second;
}

int main () {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    pair<ll, ll> in[100000];

    ll m = 0;
    ll c = 0; //cost

    int i = 0;

    while (t--)
    {
    	cin >> in[i].first >> in[i].second;
    	m += in[i].first;
    	i++;
    }

    sort(begin(in), begin(in)+i, compare);

    int nB = 0;
    int xB = i-1;

    ll k;
    ll *na, *nb, *xa, *xb;

    for (ll N=0;N<m;) {

    	na = &in[nB].first;
    	nb = &in[nB].second;
    	xa = &in[xB].first;
    	xb = &in[xB].second;

    	if (*na == 0) {
    		nB++;
    	}
    	if (*xa == 0) {
    		xB--;
    	}
    	if (*nb <= N) {
    		c += *na;
    		N += *na;
    		*na = 0;
    	}
    	else {
    		k = min(*xa, *nb - N); //number of times to buy xB. N + (b[nB] - N) = b[nB]. let N = 1, b[nB] = 3. buy once. N=2. buy again N=3. then buy out nB.
    		c += 2*k;
    		*xa -= k; //either catch up to b[nB] or buy out xB.
    		N += k;
    		if (*nb <= N) {//if caught up to b[nB], buy out all of item nB.
	    		c += *na;
	    		N += *na;
	    		*na = 0;
    		}
    	}
    }

    cout << c << endl;
    return 0;
}
