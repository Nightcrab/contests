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

    consider that there is an optimal solution S where two of the additional chords, AB and CD, do not intersect.

    note that chords AB and CD intersect iff A and B are on opposite sides of CD. aka

    C < A < D. 
    D < B < C.

    hence A and B are on the same side of CD.

    wlog, let the clockwise ordering of the four points be C < D < B < A hence as directed segments, AB and CD are parallel.

    note that AD and CB intersect within the circle.

    consider some chord EF which intersects chord AB.

    Hence wlog A < E < B therefore B < F < A.

    in all cases of F, EF either intersects AD or CB.

    hence the optimality of S has strictly increased.

    S cannot be optimal unless all additional chords intersect all other chords exactly once.

    Consider one chord XY.

    there are n points on one side of XY and k points on the other.

    XY intersects every other chord only if every point on one side of XY matches to a point on the other.

    hence n = k. hence given X there is only one possible candidate for Y.

    i.e. only one such S exists.

    the chords can be found and number of intersections counted both in O(n^2) time

    use of a segtree would probably reduce this but we will see if O(n^2) passes.

    note there are 2n-2k-2 unused points which are not X or Y. hence there should be n-k-1 of these points on either side of XY. 

    8 9 0 1 2

    > 8 or < 2.

    5 6 7 8

    > 5 and < 8.

	g++ -o 1552C.exe 1552C.cpp && 1552C.exe < 1552C.in
*/

bool intersecting (int A, int B, int C, int D) {

    if (C < D) {
        if (C < A && A < D && (B < C || B > D)) {
            return true;
        }
        if (C < B && B < D && (A < C || A > D)) {
            return true;
        }
    }
    else {
        if (D < A && A < C && (B < D || B > C)) {
            return true;
        }
        if (D < B && B < C && (A < D || A > C)) {
            return true;
        }
    }
    return false;

}

int main () {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int N = 2*n;

        vector<pair<int,int>> chords;

        unordered_map<int,int> points;

        int a,b;
        for (int i=0;i<k;i++) {
            cin >> a >> b;
            a--;
            b--;
            chords.push_back({a,b});
            points.insert({a,1});
            points.insert({b,1});
        }


        for (int i=0;i<N;i++) {
            if (points.find(i) != points.end()) {
                continue;
            }
            int p = 0;
            for (int j=1;j<N;j++) {
                if (points.find((i+j) % N) == points.end()) {
                    if (p == n - k - 1) {
                        chords.push_back({i,(i+j) % N});
                        points.insert({i, 1});
                        points.insert({(i+j) % N, 1});
                        k++;
                        break;
                    }
                    p++;
                }
            }
        }

        int ans = 0;

        for (int i=0;i<chords.size()-1;i++) {
            for (int j=i+1;j<chords.size();j++) {
                if (intersecting(chords[i].first, chords[i].second, chords[j].first, chords[j].second)) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    cout << endl;
    return 0;
}

