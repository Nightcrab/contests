#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*
	in
		t
		{
			n k
			S
		}
	
	given sequence S, find the pair (i,j) which maximises f(i,j) = g(i,j) - h(i,j) = i*j - k*(S[i] | S[j]).

	consider that the second term increases linearly while the first is quadratic. Hence larger i,j are heavily preferred.

	fix i.

	max f(i) = i*n.

	note a | b <= 2*max(a,b).

	min f(n-1,n) = n*(n-1) - k*2n = n^2 - n - 2kn = n(n - 1 - 2k).

	i is worth considering only if i >= n - 1 - 2k.

	so there are only 2 + 2k indexes we need to consider. 

	from here, brute force is done in O(k^2) however k is small (< 100) so this is OK. (not to be confused with O(k)).

	g++ -o 1554B.exe 1554B.cpp && 1554B.exe < 1554B.in
*/

int main () {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
    	int n,k;
    	cin >> n >> k;
    	ll S[202];
    	ll ans = -1*INF32;
    	int l = max(0,n-2*k-2);
    	for (int i=0;i<l;i++) { //skip n-2*k-2 values.
    		int x;
    		cin >> x;
    	}
    	for (int i=0;i<min(n,2*k + 2);i++) { 
    		cin >> S[i];
    	}
    	for (int i=0;i<min(n,2*k + 2);i++) {
    		for (int j=i+1;j<min(n,2*k + 2);j++) {
    			ans = max(ans, 1LL*(i+1+l)*(j+1+l) - 1LL*k*(S[(i)] | S[(j)]));
    		}
    	}

    	cout << ans << endl;
    }
    cout << endl;
    return 0;
}