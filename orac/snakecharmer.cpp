#include <bits/stdc++.h>
using namespace std;

#define INF 100000000000000000
#define INF32 1000000000
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define ll long long int
#define forn(i,n) for (int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
#define pvii pair<vector<int>,vector<int>>

/*
	problem description

    constrained pathfinding from (0,0) to specified (x,y) on a co-ordinate grid.

    at any point, the agent is either aligned horizontally (east west) or vertically (north south)
    the agent can then only move either up or down, or left and right respectively.

    the agent always starts in a vertical alignment.  It changes alignment every move.

    solution:

    we will use A* algorithm in conjunction with a heuristic.
    even though A* is a very memory intensive algorithm we should note that we've been allowed 1GB of memory which is substantial.

    the heuristic will be the distance of a path which moves diagonally to a point (x,k) and then moves in a straight line towards (x,y).

    starting with a northern orientation, the agent can move one unit sideways after 2 moves, ending with its initial orientation.
    Hence h(0) >= 2*x.
    Once at (x,k) the agent can move upwards two units after 4 moves, encountering the intermediary point on move #3.
    Hence let h(0) = 2*x + 2*y.

    A point will be represented by the co-ordinates (x,y,z) where z is 0 or 1 depending on the orientation (0,1) = (horizontal, vertical).

    if z is 0, the next two nodes are (x,y+1,1) and (x,y-1,1)

    if z is 1, the next nodes are (x+1,y,0) and (x-1,y,0).

    we store previously visited nodes in a hashmap 
    open nodes are stored in a heap (priority queue). nodes n are ordered by g(n) + h(n).

    g++ -o charmer.exe charmer.cpp && charmer.exe
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

int comp (pvii a, pvii b) {
    return a.first[1] > b.first[1];
}

int heu(int x, int y, vector<int> &dest) {
    return 2*abs(dest[0] - x) + 2*abs(dest[1] - y);
}

void f(pvii &node, vector<int> &dest) {
    node.first[1] = node.first[0] + heu(node.first[2], node.first[3], dest);
}

void visitNode (pvii &node, map<vector<int>, vector<int>> &visited, vector<pvii> &open) {

    vector<int> point = {node.first[2],node.first[3],node.first[4]};

    if (visited.find(point) == visited.end()) {

        open.push_back(node);
        push_heap(all(open), comp);
    }
}

void backtrack (map<vector<int>, vector<int>> &visited, vector<int> p3, string &out) {
   
    
    vector<int> p2 = visited.find(p3) -> second;
    vector<int> p1 = visited.find(p2) -> second;

    if (p3[0] - p2[0] == -1) {
        if (p2[1] - p1[1] == 1) {
            out += "L";
        }
        if (p2[1] - p1[1] == -1) {
            out += "R";
        }
    }
    else if (p3[0] - p2[0] == 1) {
        if (p2[1] - p1[1] == 1) {
            out += "R";
        }
        if (p2[1] - p1[1] == -1) {
            out += "L";
        }
    }
    else if (p3[1] - p2[1] == 1) {
        if (p2[0] - p1[0] == 1) {
            out += "L";
        }
        if (p2[0] - p1[0] == -1) {
            out += "R";
        }
    }
    else if (p3[1] - p2[1] == -1) {
        if (p2[0] - p1[0] == 1) {
            out += "R";
        }
        if (p2[0] - p1[0] == -1) {
            out += "L";
        }
    }
    if (p1[0] == 0 && p1[1] == 0) {
        if (p3[0] == 1 && p3[1] == 1) {
            out += "R";
        }
        if (p3[0] == -1 && p3[1] == 1) {
            out += "L";
        }
        if (p3[0] == 1 && p3[1] == -1) {
            out += "R";
        }
        if (p3[0] == -1 && p3[1] == -1) {
            out += "L";
        }
        return;
    }
    backtrack(visited, p2, out);
}

void nextStep (map<vector<int>, vector<int>> &visited, vector<pvii> &open, vector<int> &start, vector<int> &dest, bool &done) {
    vector<int> curr = open[0].first;
    vector<int> prev = open[0].second;

    int g = curr[0] + 1;
    int x = curr[2];
    int y = curr[3];
    int z = curr[4];

    pvii left(vector<int>{g, 0, x, y, !z}, curr);
    pvii right(vector<int>{g, 0, x, y, !z}, curr);

    if (z == 0) {
        left.first[3]++;
        right.first[3]--;
    }
    else {
        left.first[2]++;
        right.first[2]--;
    }

    f(left,dest);
    f(right,dest);

    visited.insert(pvii (vector<int>{x,y,z}, vector<int>{prev[2], prev[3], prev[4]}));

    if (x == dest[0] && y == dest[1]) {
        done = true;
        dest[2] = z;
        return;
    }

    pop_heap(all(open),comp);
    open.pop_back();

    visitNode(left, visited, open);
    visitNode(right, visited, open);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int x, y;

    ifstream in("snakein.txt");
    ofstream out("snakeout.txt");

    in >> x >> y;

    map<vector<int>, vector<int>> visited; // (x,y,z), (x,y,z)
    vector<pvii> open; // (g(n), f(n) x, y, z), (prev. node)
    vector<int> dest = {x,y,0};
    vector<int> start = {0, heu(0, 0, dest), 0, 0, 1};
    bool done = false;

    open.push_back(pvii(start, {-1,-1,-1,-1,-1}));
    make_heap(all(open), comp);

    while (!done) {
        nextStep(visited, open, start, dest, done);
        //cout << open[0].first << endl;
    }
    string answer = "";
    backtrack(visited, (dest), answer);
    reverse(all(answer));

    out << answer << endl;
    in.close(); 
    out.close();
    return 0;
}
