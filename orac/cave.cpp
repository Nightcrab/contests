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

    We are given a cave. Which in this case is a rooted tree.

    Our task is to count the number of leaves on the tree. Solved trivially by BFS/DFS.

    g++ -o cave.exe cave.cpp && cave.exe
*/

int count_leaves (vector<vector<int>> &grid, pii root) {

    int y = root.first;
    int x = root.second;

    grid[y][x] = 0;

    int filled_adj = 0;
    int branches = 0;
    int leaves = 0;

    if (grid[y][x+1] != 0) {
        leaves += count_leaves(grid, {y, x+1});
        branches++;
    }
    if (grid[y][x-1] != 0) {
        leaves += count_leaves(grid, {y, x-1});
        branches++;
    }
    if (grid[y+1][x] != 0) {
        leaves += count_leaves(grid, {y+1, x});
        branches++;
    }
    if (grid[y-1][x] != 0) {
        leaves += count_leaves(grid, {y-1, x});
        branches++;
    }

    if (branches == 0) {
        return 1;
    }

    return leaves;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int H,W;

    ifstream in("cavein.txt");
    ofstream out("caveout.txt");

    in >> H >> W;

    vector<vector<int>> grid(H+2, vector<int>(W+2, 0));

    char x;

    for (int i=1;i<H+1;i++) {
        for (int j=1;j<W+1;j++) {
            in >> x;
            if (x == '.') {
                grid[i][j] = 1;
            }
        }
    }

    out << count_leaves(grid, {1, 1});

    in.close(); 
    out.close();
    return 0;
}