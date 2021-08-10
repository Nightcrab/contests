#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

/*

    in {
        n m
        string S
        {
            l r
        }
    }

    l r are indexes in [1,n]

    substring bounds are inclusive

    Note that given any palindrome string,
    At the center of that palindrome is either a 2 or a 3 palindrome.

    Hence the number of palindromes is equal to the number of 2 and 3 length palindromes.
    At a minimum we need to make changes such that each of these is disrupted.

    For distinct palindromes this is at least one change.

    For overlapping palindromes this is at least one per group.

    In the case of a distinct palindrome, can we always remove it with one change?

    consider a 2 palindrome aa.
    neither of these terms are part of another palindrome.

    if we make exactly one change, we change one of them to either b or c.

    if changing it to ba doesn't work, we must have a or b to the immediate left (to form a 2 or 3 palindrome).

    it can't be an a since that would contradict the distinctness of the original.

    hence we have baa. bca doesn't work, only if we had baac.

    if we have baac it is impossible to fix the palindrome with one change.

    ---

    Consider a string with no 2 or palindromes.

    wlog let the string start with ab.

    the following letter cannot be a or b hence we have

    abc. the following letter cannot be b or c hence we have

    abcabcabcabc...

    hence there are 3 possible strings the input can be transformed into.

    this can be solved using a prefix sum, with O(n) time to build the array and O(1) to answer a query.

    g++ -o 1555D.exe 1555D.cpp && 1555D.exe < 1555D.in

*/

void diff_sum (int * a, int * b, int * result) {
    for (int i=0;i<sizeof(b);i++) {
        if (a[i] != b[i]) {
            result[i] = result[i-1] + 1;
        }
        else {
            result[i] = result[i-1];
        }
    }
}

void diff_sum2 (int *b, int * result, int offset) {
    for (int i=1;i<sizeof(b);i++) {
        result[i] = result[i-1];
        if ((i+offset) % 3 == b[i]) {
            result[i]++; //prefix sum is sum up to and not including i
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;

    int S[200000];


    forn (i,n) {
        char k;
        cin >> k;
        S[i] = int(k);
        S[i] -= 97;
    }
    vector<vector<int>> ps(6, vector<int>(n+1));

    int p[] = {0, 1, 2};

    int s;

    for (int i=0;i<6;i++) {
        s = 0;
        ps[i][0] = 0;
        for (int j=0;j<n;j++) {
            if (S[j] != p[j % 3]) {
                s++;
            }
            
            ps[i][j+1] = s; //p[i][1] is the first term.  p[i][n] is the last term. ps is the sum up to and including the j'th term.
        }
        int * pp;
        pp = p;
        next_permutation(pp,pp+3);
    }

    while (m--) {
        int l,r;
        cin >> l >> r;
        int ans = INF32;
        for (int i=0;i<6;i++) {
            ans = min(ans, ps[i][r] - ps[i][l-1]);
        }
        cout << ans << endl;
    }

    cout << endl;
    return 0;
}