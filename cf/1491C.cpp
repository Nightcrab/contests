#include <bits/stdc++.h>
using namespace std;

/*
	problem description
	in:
	t
	{
		n
		sequence S
	}
	
	out:
	minimum number of passes to reduce all trampolines to 1

	1. all permutations of an optimal set of passes is still optimal
		proof:
			consider two adjacent passes
			consider a trampoline T that appears in both passes
				T takes values t in the first run and t-1 in the second run, but in both instances takes peko to the +t'th and the +(t-1)th trampoline
			consider a trampoline T in only one pass
				T takes peko to trampoline +t.
			in either case, the outcome is the same regardless of the order of passes.
			=> all permutations of a destructive sequence are also destructive.
	2. consider an optimal set of passes P
		let T be the leftmost non-1 trampoline with strength t
		P must contain t-1 passes starting on T
		in our chosen permutation of P we may do all of these right away
		this leaves us with a smaller trampoline sequence S, which we must destroy.

	So we have at least one recursive solution.

*/

void pass (int *S, int T, int n, long long int &m, int *U) {
    m += max(0, S[T] - 1 - U[T]); // new passes
    int i = 0;
    for (i = T+2; i < min(n,T+S[T]+1); i++) { // O(n)
        U[i] += 1;
    }
    U[T+1] += max(0,U[T] - S[T] + 1);
}

void next () {
    int n;
    cin >> n;
    int S[n];
    int U[n] = {0};
    int i;
    long long int m = 0;
    for (i=0;i<n;i++) {
        cin >> S[i];
    }
    for (i=0;i<n;i++) { // O(n)
        pass(S, i, n, m, U);
    }   
    cout << m << "\n";
}

int main () {
    int t;
    cin >> t;
    for (int i=0;i<t;i++) {
        next();
    }
    cout << endl;
    return 0;
}
