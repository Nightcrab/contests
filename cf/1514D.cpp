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
    n q
    a
    {
        l r
    }

    with each case, find the minimum number of subsequences in a good partition of a[l:r].

    a partition is good if all elements occur no more than ceil(x/2) times in a subsequence where x is the length of a subsequence.
    a partition's subsequences are all good iff the partition is good.

    if the original subsequence is good then we return 1.
    Otherwise, there is exactly one element z which appears more than ceil((r-l)/2) times.
    if a subsequence is made of N of an element and N-1 of everything else, it is good.
    Consider that z appears K too many times. i.e. ceiL((r-l)/2) + K times.

    Is it possible to create a partition of M sequences? consider that each sequence has length a_i where a is a sequence summing to r-l.

    We need to distribute z over these partitions such that it never exceeds ceil(a_i/2) in sequence i.

    if z occurs more than sum(ceil(a_i/2)) <= (r-l)/2 + M/2 times this is impossible. consider k+1 sequences. 

    sum (ceil(a_i/2)) <= sum (a_i/2 + 1/2) = (r-l)/2 + M/2.

    however we know that z occurs ceil((r-l)/2) + K times. 
    if r-l is even, K < M/2 hence M = 2K is optimal. 
    if r-l is odd, K + 1/2 < M/2 hence M = 2K+1 is optimal.

    Consider that if r-l is even, we remove 2K+1 z's and place them in subsequences of length 1.

    the number of z's in the original sequence becomes ceil((r-l)/2) - K + 1.

    the length of the sequence is (r - l - 2K + 1), which is odd.
    hence ceil((r - l - 2K + 1)/2) = (r-l)/2 - K + 1.

    Hence the partition is good and optimal.

    if r-l is odd, remove 2K z's and do likewise.
    the length of the dubious sequence is r - l - 2K which is odd. ceil((r - l)/2 - K) = (r - l)/2 - K + 1/2.
    the number of z's is (r-l)/2 - K + 1/2.

    hence we have a piecewise formula for the size of the optimal partition.

    we just need to calculate K, i.e. the frequency of the most frequent item in a[l:r].

    This could be done in O(qn) time with a naive approach. (too slow)

    Identifying z can be done in O(log n) time using a segtree.
    However the complexity is O(nq log n) which is worse.
    

    g++ -o 1514D.exe 1514D.cpp && 1514D.exe < 1514D.in

*/

int getF_naive (int *S, int l, int r, int n) {

    l--;

    int f[n] = {0};
    int K = 0;

    for (int i=l;i<r;i++) { // O(n)
        K = max(K,++f[S[i]-1]); //O(1)
    }

    return K;
}

int main () {
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    int a[300000];
    for (int i = 0;i<n;i++) {
        cin >> a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int K = getF_naive(a,l,r, n) - ceil((r-l+1)/2);

        if (K <= 0) {
            cout << 1 << endl;
        }
        else if ((r - l + 1) % 2 == 0) { //length of subsequence is actually r - l + 1
            cout << 2*K << endl;
        }
        else {
            cout << 2*K+1 << endl;
        }
    }

    cout << endl;
    return 0;
}