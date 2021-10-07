#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)

/*

    At each turn, we guess a number x.

    the number changes from y to z such that x XOR z = y.

    consider that we are guessing log_k (n) passwords independently where each password is one k-it.

    we want all of the digits to be correct after exactly p < n guesses.

    when k = 2:

    XOR table:
    x y z
    0 0 0
    0 1 1
    1 0 1
    1 1 0

    y can take on any of n possible initial values.

    Consider that XOR is its own inverse for k = 2.
    
    if we know that y_q != y' at turn q, we can XOR y' with previous guesses to eliminate a possible value of y_0.

    hence we we guess the password in at most n guesses by iterating possible values of y_0.

    in a more straightforward approach, we can XOR a possible y_0 to get our guess y' and check if it is right,
    proceeding until we exhaust all possbile y_0.

    further we note that (x XOR y) XOR z = x XOR (y XOR z)

    so we only need to store the cumulative XOR of all previous guesses.

    when k >= 2:

    addition modulo k is still associative. 

    hence, a similar strategy should still apply, however

    note that XOR mod k is no longer self-inverse. rather:

    x KXOR z = y 

    x + z = y mod k

    hence

    z = y - x mod k.

    also note that when solving the initial problem, I misread the assignments of x and y.

    so actually y is our guess and x is the previous password.

    hence we have z = y_i - (y_(i-1) - ... ( - x0))

    z = y_i - y_(i-1) + ... (x0)

    hence we have an alternating sum of our guesses and x0.

    also:

    we need a k-itwise XOR.

    let a = a_0 + a_1 k + a_2 k^2 ... 
    and define b similarly.

    a kXOR b = (a_0 kXOR b_0) + (a_1 kXOR b_1) k ...

    To avoid converting bases, we keep numbers as arrays storing their digits in base k.

    0 0 0
    0 1 1
    1 0 1
    1 1 0

	g++ -o 1543D.exe 1543D.cpp && 1543D.exe < 1543D.in
*/

int logK (int a, int k) {
    return log(a)/log(k);
}

void KXOR (int *a, int *b, int *c, int k) {
    for (int i=0;i<18;i++) {
        c[i] = ((a[i]+b[i]) % k);
    }
}

void KNOR (int *a, int *b, int *c, int k) {
    for (int i=0;i<18;i++) {
        c[i] = ((a[i]-b[i]) % k);
        if (c[i] < 0) {
            c[i] += k;
        }
    }
}

void KFlip (int *a, int k) {
    for (int i=0;i<18;i++) {
        a[i] = a[i]*(-1) % k;
        if (a[i] < 0) {
            a[i] += k;
        }
    }
}

int b10 (int* a, int *kpow) {
    int b = 0;
    for (int i=0;i<18;i++) {
        b += a[i]*kpow[i];
    }
    return b;
}

void incr(int *a, int k) {
    for (int i=0;i<18;i++) {
        a[i] = (a[i] + 1 ) % k;
        if (a[i] != 0) {
            break;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin >> n >> k;

        int kpow[18] = {0};
        kpow[0] = 1;

        for (int i=1;i<=logK(n, k);i++) {
            kpow[i] = k*kpow[i-1];
        }

        int x0[18] = {0};
        int y[18] = {0};

        for (int i=0;i<n;i++) {

            int guess[18] = {0};
            if (i % 2 == 1) {
                KNOR(y, x0, guess, k);
            }
            else {
                KXOR(y, x0, guess, k);
            }
            cout << b10(guess, kpow) << endl;
            cout.flush();
            KNOR(guess, y, y, k);

            int r;

            cin >> r;
            if (r == 1) {
                break;
            }

            incr(x0, k);
        }
    }

    cout << endl;
    cout.flush();
    return 0;
}
