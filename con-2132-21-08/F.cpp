/*F. Rada and the Chamomile Valley
time limit per test3 seconds
memory limit per test512 megabytes
Yesterday, Rada found a portal that can transport her to the Chamomile Valley
and back. Rada's happiness knew no bounds, but it didn't last long — she
suddenly realized that she didn't know where and when any of the Smeshariki
would be.

The Chamomile Valley consists of 𝑛
 houses and 𝑚
 lanes connecting the houses. The lanes are numbered from 1
 to 𝑚
. You can walk along the lanes in both directions. It is known that from any
house, you can reach any other house via the lanes, and there is no lane
connecting a house to itself. Moreover, any two houses are connected by at most
one lane.

Rada knows that the Smeshariki walk every day from house number 1
 to house number 𝑛
, but she doesn't know which specific lanes they will take. Rada will be in the
Chamomile Valley on each of the next 𝑞 days. On the 𝑘 -th day, she will be at
house number 𝑐𝑘
.

Since Rada does not know which specific lanes the Smeshariki will take, she is
only interested in those lanes that they will definitely use. To ensure she does
not miss any of them, she wants to know the index of the nearest such lane on
each day. Rada is too busy strolling through the Chamomile Valley, so she asks
you to help her determine the required lane indices.

The distance from house 𝑐
 to the lane connecting houses 𝑎
 and 𝑏
 is defined as the minimum of 𝜌(𝑎,𝑐)
 and 𝜌(𝑏,𝑐)
, where 𝜌(𝑎,𝑏)
 is the minimum number of lanes needed to reach house number 𝑏
 starting from house number 𝑎
.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of each test case follows.

The first line contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤2⋅105
, 𝑛−1≤𝑚≤min(𝑛⋅(𝑛−1)2,2⋅105)
) — the number of houses and lanes, respectively.

The next 𝑚
 lines contain two integers 𝑢≠𝑣
 (1≤𝑢,𝑣≤𝑛
) — a lane connecting houses numbered 𝑢
 and 𝑣
. The lanes are given in order of numbering, that is, the description of the
first lane comes first, followed by the second, third, and so on up to the 𝑚 -th
lane.

Next, an integer 𝑞
 (1≤𝑞≤2⋅105
) is given — the number of days Rada will be walking in the Chamomile Valley.

The next 𝑞
 lines each contain a single integer 𝑐
 (1≤𝑐≤𝑛
) — the house at which Rada will be on that day.

It is guaranteed that from any house, you can reach any other house by only
using the lanes, and there are no lanes from a house to itself, and any two
houses are connected by at most one lane.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
, the sum of 𝑚
 across all test cases does not exceed 2⋅105
, and the sum of 𝑞
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the answer for each of the days. If there are
multiple suitable lanes on any of the days, output the lane with the smallest
index among the suitable ones. If there are no required lanes, output −1
.

Examples
InputCopy
3
3 3
1 2
2 3
3 1
1
1
5 4
1 2
2 3
3 4
4 5
3
1
2
3
7 6
1 2
1 5
2 3
3 4
5 7
6 7
7
1
2
3
4
5
6
7
OutputCopy
-1
1 1 2
2 2 2 2 2 5 5
InputCopy
2
5 4
4 2
4 1
5 1
3 5
5
1
2
3
4
5
6 6
1 2
2 3
3 4
4 5
5 2
5 6
2
3
4
OutputCopy
3 3 3 3 3
1 6
Note
In all further explanations, we denote the transition from house 𝑎
 to house 𝑏
 via the lane numbered 𝑐
 as 𝑎→𝑐𝑏
.

In the first sample, from house 1
 to house 3
, you can reach it via at least the following paths:

1→33

1→12→23

As we can see, these two paths do not share any common lanes, which means there
are no suitable lanes.

In the second sample, it can be noted that there is a unique path from 1
 to 𝑛
:

1→12→23→34→45

As can be seen, the answer for the 𝑣
-th vertex is max(𝑣−1, 1)
.
*/
/*🔑 Step 1: What are the “lanes they will definitely use”?

The Smeshariki walk from 1 → n, but they may choose any shortest path.
So, the lanes that are definitely used in every shortest path are exactly the
edges that belong to all shortest paths from 1 to n.

👉 This is the intersection of all shortest paths.

So we want:

All edges (u, v, idx) such that for every shortest path from 1 → n, the edge (u,
v) is present.

🔑 Step 2: Detecting such edges

How do we check if an edge (u, v) is in every shortest path?

Compute:

dist1[x] = shortest distance from 1 → x (via BFS since unweighted).

distN[x] = shortest distance from x → n.

Let D = dist1[n] = length of shortest path 1 → n.

Now for an edge (u, v):

If we orient it: suppose dist1[u] + 1 + distN[v] = D, then edge (u, v) can lie
on some shortest path (going u→v).

Similarly for (v, u).

So edges satisfying this are candidates for being in shortest paths.

🔑 Step 3: Which of them are in all shortest paths?

This reduces to the idea of a shortest-path DAG from 1 to n.

Consider only edges that satisfy dist1[u] + 1 + distN[v] = D (directed from
u→v). This forms a DAG of possible shortest paths.

Now, an edge is in all shortest paths iff it lies on every path from 1 → n in
this DAG.

👉 That’s basically the dominator / articulation edge in DAG of shortest paths.

But there’s a simpler trick (no heavy dominator algorithm needed):

For each level d = dist1[x],
let count[d] = number of nodes reachable at that distance on shortest paths.
If for an edge (u, v) with dist1[u] + 1 = dist1[v]:

and count[dist1[v]] == 1,
then this edge is forced — because the next layer has only that single node to
continue the path.

So we can precompute which edges are “forced”.

🔑 Step 4: Answering queries

We now know the set of forced edges.
For each query c:

Distance from c to an edge (u, v) is min(dist(c, u), dist(c, v)).
But computing that naively is too slow.

Instead, note: we only need the nearest forced edge.

So:

For each forced edge (u, v, idx), mark its two endpoints with label idx.

Then run a multi-source BFS from all endpoints, propagating (dist, idx) info.

For each node c, you get the nearest edge index.

🔑 Step 5: Complexity

BFS from 1 → O(n+m)

BFS from n → O(n+m)

Build DAG → O(m)

Multi-source BFS for forced edges → O(n+m)

Answer queries → O(q)

All good under constraints (2e5).
*/

/* Plan to Code

BFS from 1 and from n.

Find D = dist1[n].

Mark candidate edges satisfying dist1[u] + 1 + distN[v] == D.

Count nodes per dist1 level.

An edge is forced if it is the only edge entering the next level.

Collect all forced edges, store their indices.

Multi-source BFS from all endpoints of forced edges.

For each query c, print nearest edge index or -1.
*/

/*Find all bridges in the graph.

Compress the graph into bridge-connected components (components when all bridges
are removed).

Build the bridge-tree (a tree where nodes = components and tree-edges =
bridges).

The bridges that are present in every 1→n path are exactly the bridges that lie
on the unique path between comp(1) and comp(n) in the bridge-tree. Collect those
bridges.

Do a multi-source propagation starting from the endpoints of those bridges to
answer: for each vertex c, which bridge (index) is the nearest (minimum graph
distance; tie-breaker: smaller index). If no such bridge exists, answer -1.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (1LL << 60);

int n, m;
vector<vector<pair<int, int>>> g; // (to, edgeIndex)
vector<pair<int, int>> edges;

// Tarjan bridge variables
vector<int> tin, low;
vector<char> visited;
int timer_dfs;
vector<char> isBridge;

void dfs_br(int v, int pe) {
  visited[v] = 1;
  tin[v] = low[v] = ++timer_dfs;
  for (auto &pr : g[v]) {
    int to = pr.first, ei = pr.second;
    if (ei == pe)
      continue;
    if (visited[to]) {
      // back edge
      low[v] = min(low[v], tin[to]);
    } else {
      dfs_br(to, ei);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v]) {
        // bridge edge index ei
        isBridge[ei] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    cin >> n >> m;
    g.assign(n + 1, {});
    edges.assign(m + 1, {0, 0});
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      edges[i] = {u, v};
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }

    // find bridges
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    isBridge.assign(m + 1, 0);
    timer_dfs = 0;
    for (int i = 1; i <= n; ++i)
      if (!visited[i])
        dfs_br(i, -1);

    // build components by removing bridge edges (iterative DFS)
    vector<int> comp(n + 1, -1);
    int compCnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (comp[i] != -1)
        continue;
      // stack DFS
      compCnt++;
      stack<int> st;
      st.push(i);
      comp[i] = compCnt;
      while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto &pr : g[v]) {
          int to = pr.first, ei = pr.second;
          if (isBridge[ei])
            continue; // skip bridges
          if (comp[to] == -1) {
            comp[to] = compCnt;
            st.push(to);
          }
        }
      }
    }

    // build bridge-tree: nodes are comps 1..compCnt, edges labeled by original
    // edge index
    vector<vector<pair<int, int>>> tree(compCnt + 1);
    for (int ei = 1; ei <= m; ++ei)
      if (isBridge[ei]) {
        int u = edges[ei].first, v = edges[ei].second;
        int cu = comp[u], cv = comp[v];
        // should be cu != cv
        tree[cu].push_back({cv, ei});
        tree[cv].push_back({cu, ei});
      }

    int comp1 = comp[1], compN = comp[n];

    // If comp1 == compN then no bridge lies on all paths -> all answers -1
    vector<int>
        forcedBridgeIndices; // indices of bridges lying on path comp1->compN
    if (comp1 != compN) {
      // BFS from comp1 to find path to compN (track parent and edge idx)
      vector<int> parent(compCnt + 1, -1), parentEdge(compCnt + 1, -1);
      queue<int> q;
      q.push(comp1);
      parent[comp1] = comp1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == compN)
          break;
        for (auto &pr : tree[u]) {
          int v = pr.first, ei = pr.second;
          if (parent[v] == -1) {
            parent[v] = u;
            parentEdge[v] = ei;
            q.push(v);
          }
        }
      }
      // reconstruct path compN->comp1
      if (parent[compN] != -1) {
        int cur = compN;
        while (cur != comp1) {
          int ei = parentEdge[cur];
          forcedBridgeIndices.push_back(ei);
          cur = parent[cur];
        }
        // forcedBridgeIndices currently in order from compN side to comp1;
        // ordering doesn't matter
      }
    }

    int qcount;
    cin >> qcount;
    vector<int> queries(qcount);
    for (int i = 0; i < qcount; ++i)
      cin >> queries[i];

    if (forcedBridgeIndices.empty()) {
      // no forced bridges -> all -1
      for (int i = 0; i < qcount; ++i) {
        if (i)
          cout << ' ';
        cout << -1;
      }
      cout << '\n';
      continue;
    }

    // Multi-source lexicographic Dijkstra (distance first, then smallest edge
    // index) Sources: for each forced bridge index, both endpoints of that
    // original edge
    vector<ll> distNode(n + 1, INFLL);
    vector<int> bestEdge(n + 1, -1);
    using T3 = tuple<ll, int, int>; // (dist, edgeIndex, node)
    priority_queue<T3, vector<T3>, greater<T3>> pq;

    for (int ei : forcedBridgeIndices) {
      int u = edges[ei].first, v = edges[ei].second;
      // endpoint u
      if (distNode[u] > 0 ||
          (distNode[u] == 0 && (bestEdge[u] == -1 || ei < bestEdge[u]))) {
        distNode[u] = 0;
        bestEdge[u] = ei;
        pq.emplace(0, ei, u);
      }
      // endpoint v
      if (distNode[v] > 0 ||
          (distNode[v] == 0 && (bestEdge[v] == -1 || ei < bestEdge[v]))) {
        distNode[v] = 0;
        bestEdge[v] = ei;
        pq.emplace(0, ei, v);
      }
    }

    while (!pq.empty()) {
      auto [d, ei, u] = pq.top();
      pq.pop();
      if (d != distNode[u] || ei != bestEdge[u])
        continue;
      for (auto &pr : g[u]) {
        int v = pr.first;
        ll nd = d + 1;
        int ne = ei;
        if (nd < distNode[v] ||
            (nd == distNode[v] && (bestEdge[v] == -1 || ne < bestEdge[v]))) {
          distNode[v] = nd;
          bestEdge[v] = ne;
          pq.emplace(nd, ne, v);
        }
      }
    }

    // output answers
    for (int i = 0; i < qcount; ++i) {
      if (i)
        cout << ' ';
      int c = queries[i];
      if (bestEdge[c] == -1)
        cout << -1;
      else
        cout << bestEdge[c];
    }
    cout << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/contest/2132/submission/334923516
