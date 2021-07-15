#include <bits/stdc++.h>
#include <iterator>
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
	k
	string S
	q
	{
		p, c
	}

	string S : at character i, 0 indicates team with lower index 1. 1 indicates the other team won. ? indicates an unknown result.

	p, c indicates that character i is to be replaced with c.

	given a string S with a sequence replacements c -> p. Find the number of possible winners after each replacement.
	
	solution:
		S is a subgraph of B with B.F <= 2. DFS of S yields the number of possible champions. We will only track the number of possible victors
		of each game in dp.

			Consider that a game P in S is modified. When DFS'ing from S, all results are the same unless they lead to P.
			So we need to DFS from P to one or more leaf nodes.
			If P was 0, we need only to DFS from P's rightmost child.
			If P was 1, we need only to DFS from the left child.
			If P was ? we have already obtained dp[left(P)] and d[right(P)].

			With the new value of dp[P], we need to propagate this value up the tree so that *dp remains accurate.
			Hence we follow a path starting from P to S which takes O(k) time. 


			proof that reaching the end of the tree always returns a team we haven't visited before:
				assume otherwise. Hence there is more than one sequence of games by which team X can win the championship.
				X must win all of the k games they play hence there is only one path from X to the root. so this is impossible.

		retroactive DFS of the tournament bracket will allow us to locate all possible champions.
		when a game outcome P is changed, /only/ the values of all nodes directly above P and P itself become unknown.
		retroactive DFS from P should yield the correct value of P, then DFS towards the root of B should allow us to propagate the new node values.

		implementation of B:
		0
		2 1
		6 5 4 3
		14 13 12 11 10 9 8 7

		instead of 
		7
		5 6
		1 2 3 4

		hence p -> (2^k - 1) - p
		S -> reverse(S)

	cmd

		g++ -o 1535D.exe 1535D.cpp && 1535D.exe < 1535D.in 


*/


template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

int ipow(int base, int exp) {
    int result = 1;
    for (;;) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int left(int p) {
	return p*2 + 2;
}

int right(int p) {
	return p*2 + 1;
}

int up(int p) {
	if (p % 2 == 0) {
		return (p-2)/2;
	}
	else {
		return (p-1)/2;
	}
}

int DFS (int p, vector<int> &dp, string &S, int N) {

	if (dp[p] > 0) {
		return dp[p];
	}

	if (p > N-1) {
		dp[p] = 1;
		return 1;
	}

	if (S[p] == '0') {
		dp[p] = DFS(left(p), dp, S, N);
	}
	else if (S[p] == '1') {
		dp[p] = DFS(right(p), dp, S, N);
	}
	else {
		dp[p] = DFS(left(p), dp, S, N) + DFS(right(p), dp, S, N);
	}
	return dp[p];

}

int prop (int p, vector<int> &dp, string &S) {

	if (dp[p] == 0) {
		return 0;
	}

	if (S[p] == '0') {
		dp[p] = dp[left(p)];
	}
	else if (S[p] == '1') {
		dp[p] = dp[right(p)];
	}
	else {
		dp[p] = dp[left(p)] + dp[right(p)];
	}

	if (p == 0) {
		return dp[p];
	}

	if (p % 2 == 0 && S[up(p)] == '1') {
		return 0;
	}
	if (p % 2 == 1 && S[up(p)] == '0') {
		return 0;
	}

	return prop(up(p), dp, S);
}

int main () {
    ios_base::sync_with_stdio(false);
    
    int k;
    int N;
    cin >> k;
    N = ipow(2,k) - 1;

    string S;

    cin >> S;

    reverse(S.begin(), S.end());

    vector<int> dp(ipow(2,k+1)-1, 0);

    int answer = DFS(0, dp, S, N);
    int q;
    cin >> q;
    while (q--) {
    	int p;
    	char c;
    	cin >> p >> c;
    	S[N - p] = c;
    	if (dp[N - p] == 0) {
    		cout << answer << endl;
    		continue;
    	}
    	dp[N - p] = 0;
    	DFS(N - p, dp, S, N);
    	prop(N - p, dp, S);
    	answer = dp[0];
    	cout << answer << endl;
    }

    cout << endl;
    return 0;
}
