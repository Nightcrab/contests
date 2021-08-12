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

    At each turn, we burn elements of a sequence S in order, until the total value of the turn is >= the previous turn.

    The task can be naively completed in O(n).

    g++ -o nom.exe nom.cpp && nom.exe
*/


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N;

    ifstream in("nomin.txt");
    ofstream out("nomout.txt");

    in >> N;

    int max = 0;

    int s = 0;

    int ans = 0;

    while (N--) {
        int d;
        in >> d;

        s += d;

        if (s >= max) {
            max = s;
            s = 0;
            ans++;
        }
    }

    out << ans << "\n";


    in.close(); 
    out.close();
    return 0;
}