#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*

    we must find any string S where |S| = k and

    every substring of S appears in S an odd number of times. 

    consider a string which contains only one character N times.

    substring A will appear N times. substring AA appears N-1 times.

    consider that we append a character B and copy the original string, but remove one character.

    Hence we have 2N-1, 2N-3 ... copies of each A*k substring.

    and one copy of every substring that includes B.

    this works for all even n.
    consider that n is odd. add C to the end of the string.

	g++ -o 1554D.exe 1554D.cpp && 1554D.exe < 1554D.in
*/

int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "a" << endl;
            continue;
        }
        if (n % 2 == 0) {
            for (int i=0;i<n/2;i++) {
                cout << "a";
            }
            cout << "b";
            for (int i=0;i<n/2-1;i++) {
                cout << "a";
            }
        }
        else {
            for (int i=0;i<(n-1)/2;i++) {
                cout << "a";
            }
            cout << "b";
            for (int i=0;i<(n-1)/2-1;i++) {
                cout << "a";
            }
            cout << "c";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}