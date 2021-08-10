#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

/*

    given a sequence S of n integers.
    determine if it is possible to divide S into k subarrays such that
    each subarray
    1. is nondecreasing
    2. with endpoint values L and R contains every element <R and >L.

    we call such subarrays of S good.

    hence the subarrays can be rejoined to form a non decreasing sequence.

    since S has no duplicates, all subarrays should be strictly increasing.

    the problem is equivalent to choosing k-1 items of S such that S is divided to satisfy 1 and 2.

    Note that if this is possible for some p < k then it is possible for k as well.

    To solve:

    First create a boolean array B where B[i] indicates whether i is present in S.

    We know there must be a subarray whose first element is S[0].

    Consider the largest possible good subarray at the start of S.

    we can prove that choosing a smaller subarray is never preferable.

    is it possible to add terms to the start of a sequence such that the number of minimum subarrays decreases?
        Assume that this is true.

        hence, there exists two such arrays A and B. A+B has a more minimal solution than B.

        removing an element from a good subarray will keep the subarray good.
        B is a subset of A+B. Hence, take A+B's minimal solution and remove elements (or single element subarrays) until the solution fits B.

        This solution to B is better than or as good as A+B's hence the minimality of B's original solution is contradicted.

    Hence we always slice the largest good subarray from the start of S and proceed recursively.

    As we loop through S, tracking our left element L,
    if the next element is not the next greatest unchecked element in [L,R] from B, we let the previous number be R and the current be L.

    note that if L and R are the same we have a subarray of length 1.

    Solution is O(n). However, iterating the bitset will take too long (2 * 10^9 elements).

    Since we only ever need to know what the next largest number is, it would be more practical to sort S and use that in place of B.

    g++ -o 1557B.exe 1557B.cpp && 1557B.exe < 1557B.in
*/


int S[100000];
int sorted[100000];
        
int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--) 
    {
        int n,k;       
        cin >> n >> k;

        unordered_map<int,int> pos;

        for (int i=0;i<n;i++) {
            cin >> S[i];
            S[i]--;
            sorted[i] = S[i];
        }

        sort(sorted,sorted+n);

        for (int i=0;i<n;i++) {
            pos.insert({sorted[i], i});
        }

        int l = 0;
        int r = pos.at(S[l]); //current index in sorted[].
        int p = 1;

        for (int i=1;i<n;i++) {
            if (r+1 == n || S[i] != sorted[r+1]) {
                l = i;
                r = pos.at(S[l]);
                p++;
                continue;
            }
            r++;
        }

        if (p <= k) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    cout << endl;
    return 0;
}