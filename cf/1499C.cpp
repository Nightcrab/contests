#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000000
#define ll long long int

/*
	problem description
    in:
        t cases
        {
            n
            sequence C
        }

    L = sum (k from 0 to n) C_k a_k
    for some sequence a
    sum a_k = 2n
    a_k > 0

    out:
        min L.

    Note we can safely split L into vertical and horizontal sums:

    L = L_0 + L_1 = sum (even k) C_k a_k + sum (odd k) C_k a_k

    where sum (even k) a_k = sum (odd k) a_k = n.
    correlation of k parity and direction depends on initial move.
    however: for a solution S_0 there exists equally optimal S_1 mirrored across the diagonal
    so the initial move is irrelevant.

    wlog, assume the first move is to the right.
    If p horizontal segments are created, we must have exactly p or p-1 verticals.
    iterate for p:
        under given constraints for a_k:
            minimise linear expression: sum(k from 0 to p) C_2k a_2k (1)
            then: sum(k from 0 to p) C_(2k+1) a_(2k+1)
        append L
    cout << min(L)

    our solution is O(n).

    (1) makes use of running minimum of C at p, as well as the sum of C_i for i < p.

    to get the minimum path for p segments, set all segments to 1 except for the lightest (two) segment(s) which has to make up the remaining distance.

    1 1
    2 1
    2 2
    3 2
    3 3
    ...

    cmd
        g++ -o mingrid2.exe mingrid2.cpp && mingrid2.exe mingrid.in 
*/

void out (int a) {
    cout << a << "\n";
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll m[2] = {INF};
        ll s[2] = {0};

        ll L = INF;

        ll a; //even C_k
        ll b; //odd C_k

        cin >> a;
        cin >> b;

        m[0] = a;
        m[1] = b;

        s[0] += a;
        s[1] += b; // 1 1

        L = min(L, a*n+b*n);

        int p = 0;
        int n2 = n/2 + (n % 2 == 1);

        for (p=2;p<=n2;p++)
        {
            ll l1;
            ll l2;

            cin >> a;

            m[0] = min(m[0], a);

            s[0] += a; // p p-1

            l1 = s[0] + (n-p)*m[0];
            l2 = s[1] + (n-p+1)*m[1];

            L = min(L, l1+l2);

            if (p == n2 && n % 2 == 1) {
                p++;
                break;
            }

            cin >> b;
            m[1] = min(m[1], b);

            s[1] += b; // p p

            l2 = s[1] + (n-p)*m[1];

            L = min(L, l1+l2);

        }

        cout << L << "\n";
    }

    cout << endl;
    return 0;
}
