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
			a, b, k
		}

	Is it possible to reduce a,b both to some number, q, through division, in exactly k total divisons?

	consider c = gcd(a,b).
	q divides c.
	let f(x) denote number of factors of x.

	Note that if a and b can be reduced to c in m moves, it can also be done in k moves for any k <= m. (divison by alpha then beta <=> division by (alpha)(beta))
	The most times we can reduce a is f(a).

	Hence we have k = i + j where i <= f(a) and j <= f(b).
	
	solution 1:
		P = sequence of primes
		d = detected prime divisors

		d(x, p) = number of times p divides x

		loop over p in P:
			d += d(a, p) + d(b, p)
		
		return true if d >= k
		else return false

	
	g++ -o apadn.exe apadn.cpp && apadn.exe < apadn.in

*/

int gcd(int a, int b)
{
	if(b==0) {
		return a;
	}
	else {
		return gcd(b,a%b);   
	}
}

int sieve (bool *iP, int *P)
{
	int N = 0;
	iP[0] = false;
	int n = 32000;
	for (int i=1;i<=ceil(sqrt(n));i++) {
		if (iP[i-1] == false) {
			continue;
		}
		for (int j=i*2;j<=n;j+=i) {
			iP[j-1] = false;
		}
	}

	forn (i, n) {
		if (iP[i] == true) {
			P[N] = i+1;
			N++;
		}
	}
	return N;
}


int nF (int *x, ll *i, int *P, int N) {
	int count = 0;
	if (*x == 1) {
		return 0;
	}
	while (*i<N) {
		while (*x % P[*i] == 0) {
			count += 1;
			*x = *x/P[*i];
		}
		*i += 1;
		if (count > 0) {
			break;
		}
	}
	if (*i == N) {
		count += 1;
		*x = 1;
	}
	return count;
}

int main () {
    ios_base::sync_with_stdio(false);


    bool iP[32000];
    int P[5000];

    memset(begin(iP), true, sizeof(iP));

    int N = 0;

    N = sieve(iP,P);
    int T;
    cin >> T;

    while(T--)
    {
    	int a,b,k;

    	int count = 0;
    	int subcount = -1;
    	ll lowA = 0;
    	ll lowB = 0;

    	cin >> a >> b >> k;


    	//can be made equal in 1 move iff a < b and gcd(a,b) = a

    	if (!(gcd(a,b) == min(a,b) && a != b) && k < 2) {
    		cout << "NO\n";
    		continue;
    	}

    	while (subcount != 0 && count < k) {
    		subcount = nF(&a, &lowA, P, N) + nF(&b, &lowB, P, N);
    		count += subcount;
    	}

    	if (count >= k)
    	{
    		cout << "YES\n";
    		continue;
    	}

    	cout << "NO\n";
    }

    cout << endl;
    return 0;
}
