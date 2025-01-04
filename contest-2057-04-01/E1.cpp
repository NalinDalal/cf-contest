/* E1. Another Exercise on Graphs (Easy Version)
time limit per test3 seconds
memory limit per test1024 megabytes
This is the easy version of the problem. The difference between the versions is
that in this version, there is an additional constraint on 𝑚 . You can hack only
if you solved all versions of this problem.

Recently, the instructors of "T-generation" needed to create a training contest.
They were missing one problem, and there was not a single problem on graphs in
the contest, so they came up with the following problem.

You are given a connected weighted undirected graph with 𝑛
 vertices and 𝑚
 edges, which does not contain self-loops or multiple edges.

There are 𝑞
 queries of the form (𝑎,𝑏,𝑘)
: among all paths from vertex 𝑎
 to vertex 𝑏
, find the smallest 𝑘
-th maximum weight of edges on the path†
.

The instructors thought that the problem sounded very interesting, but there is
one catch. They do not know how to solve it. Help them and solve the problem, as
there are only a few hours left until the contest starts.

†
 Let 𝑤1≥𝑤2≥…≥𝑤ℎ
 be the weights of all edges in a path, in non-increasing order. The 𝑘
-th maximum weight of the edges on this path is 𝑤𝑘
.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤100 ) — the number of test cases. The description of the test cases
follows.

The first line of each set of test case contains three integers 𝑛,𝑚
 and 𝑞
 (2≤𝑛≤400
, 𝑛−1≤𝑚≤min(400,𝑛⋅(𝑛−1)2)
, 1≤𝑞≤3⋅105
) — the number of vertices, the number of edges, and the number of questions,
respectively.

Each of the following 𝑚
 lines of each set of test case contains three integers 𝑣,𝑢
 and 𝑤
 (1≤𝑣,𝑢≤𝑛
, 1≤𝑤≤109
) — the ends of the next edge of the graph and its weight, respectively. It is
guaranteed that the graph does not contain self-loops and multiple edges.

Each of the following 𝑞
 lines of each set of test case contains three integers 𝑎,𝑏
 and 𝑘
 (1≤𝑎,𝑏≤𝑛
, 𝑘≥1
) — the next question. It is guaranteed that any path from vertex 𝑎
 to vertex 𝑏
 contains at least 𝑘
 edges.

It is guaranteed that the sum of the values of 𝑛
 across all sets of test cases does not exceed 400
.

It is guaranteed that the sum of the values of 𝑚
 across all sets of test cases does not exceed 400
.

It is guaranteed that the sum of the values of 𝑞
 across all sets of test cases does not exceed 3⋅105
.

Output
For each test case, output the answers to all questions.

Example
InputCopy
3
4 4 2
1 2 2
2 4 2
1 3 4
3 4 1
1 4 2
2 3 1
6 7 3
1 2 10
2 3 3
3 4 9
4 5 2
5 6 1
2 4 10
4 6 10
1 6 3
1 6 2
2 4 1
11 17 10
1 4 5
1 3 19
1 2 10
3 2 13
4 5 1
4 6 11
3 5 9
3 6 18
2 7 17
5 8 15
5 10 8
6 9 4
7 10 20
7 8 16
8 11 3
9 11 6
10 11 14
3 11 1
3 11 3
1 11 1
1 11 4
1 11 3
8 2 2
10 4 1
3 9 2
3 9 1
6 7 3
OutputCopy
1 2
2 9 9
11 3 11 1 3 10 8 4 11 4
Note
In the first set of test cases, one of the optimal paths in the first query is
the path 1→3→4 ; the 2 -nd maximum weight of the edges on this path is 1 . In
the second query, one of the optimal paths is 2→4→3 ; 1 -st maximum weight of
the edges is 2
.

In the second set of input data, one of the optimal paths in the first query is
the path 1→2→4→5→6 ; the 3 -rd maximum weight of the edges on this path is 2
.



*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// n number of vertices
// m number of egdes
// q number of queries (a,b,k)
// m lines contain u,v,w
// q lines contain a,b,k; path from a to b contains k edges
// sum(n)<=400, sum(m)<=400,sum(q)<=3*10^5

// DFS function to collect the edges' weights in the path from a to b
void dfs(int node, int parent, vector<vector<pair<int, int>>> &adj,
         vector<int> &path, vector<bool> &visited) {
  visited[node] = true;
  for (auto &edge : adj[node]) {
    int neighbor = edge.first;
    int weight = edge.second;
    if (!visited[neighbor]) {
      path.push_back(weight);
      dfs(neighbor, node, adj, path, visited);
      // When returning from the DFS, ensure to backtrack.
      path.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, m, q;
    cin >> n >> m >> q;

    // Graph adjacency list: node -> list of pairs (neighbor, weight)
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    // Process each query
    while (q--) {
      int a, b, k;
      cin >> a >> b >> k;

      // We need to find the path from a to b
      vector<int> path;
      vector<bool> visited(n + 1, false);

      // DFS to find the path and collect edge weights
      dfs(a, -1, adj, path, visited);

      // Sort the path weights in descending order
      sort(path.begin(), path.end(), greater<int>());

      // Output the k-th maximum weight in the path
      cout << path[k - 1] << " ";
    }
    cout << endl;
  }
  return 0;
}
