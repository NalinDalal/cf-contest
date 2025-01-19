/* E. Graph Composition
time limit per test2 seconds
memory limit per test256 megabytes
You are given two simple undirected graphs 𝐹 and 𝐺 with 𝑛 vertices. 𝐹 has 𝑚1
edges while 𝐺 has 𝑚2 edges. You may perform one of the following two types of
operations any number of times:

Select two integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛) such that there is an edge between 𝑢 and 𝑣
in 𝐹. Then, remove that edge from 𝐹. Select two integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛) such
that there is no edge between 𝑢 and 𝑣 in 𝐹. Then, add an edge between 𝑢 and 𝑣 in
𝐹. Determine the minimum number of operations required such that for all
integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛), there is a path from 𝑢 to 𝑣 in 𝐹 if and only if
there is a path from 𝑢 to 𝑣 in 𝐺.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of independent test
cases.

The first line of each test case contains three integers 𝑛, 𝑚1, and 𝑚2
(1≤𝑛≤2⋅105, 0≤𝑚1,𝑚2≤2⋅105) — the number of vertices, the number of edges in 𝐹,
and the number of edges in 𝐺.

The following 𝑚1 lines each contain two integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛) — there is an
edge between 𝑢 and 𝑣 in 𝐹. It is guaranteed that there are no repeated edges or
self loops.

The following 𝑚2 lines each contain two integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛) — there is an
edge between 𝑢 and 𝑣 in 𝐺. It is guaranteed that there are no repeated edges or
self loops.

It is guaranteed that the sum of 𝑛, the sum of 𝑚1, and the sum of 𝑚2 over all
test cases do not exceed 2⋅105.

Output
For each test case, output a single integer denoting the minimum operations
required on a new line.

Example
InputCopy
5
3 2 1
1 2
2 3
1 3
2 1 1
1 2
1 2
3 2 0
3 2
1 2
1 0 0
3 3 1
1 2
1 3
2 3
1 2
OutputCopy
3
0
2
0
2
Note
In the first test case you can perform the following three operations:

Add an edge between vertex 1 and vertex 3.Remove the edge between vertex 1 and
vertex 2.Remove the edge between vertex 2 and vertex 3. It can be shown that
fewer operations cannot be achieved.In the second test case, 𝐹 and 𝐺 already
fulfill the condition in the beginning. In the fifth test case, the edges from 1
to 3 and from 2 to 3 must both be removed.


*/
#include <iostream>
#include <vector>

using namespace std;

// Union-Find (Disjoint Set Union) class
class DSU {
public:
  vector<int> parent, size;

  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]); // Path compression
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      // Union by size
      if (size[rootX] < size[rootY]) {
        swap(rootX, rootY);
      }
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
    }
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    // Create two DSU instances for the two graphs
    DSU dsuF(n), dsuG(n);

    // Reading edges for graph F and applying union
    for (int i = 0; i < m1; i++) {
      int u, v;
      cin >> u >> v;
      dsuF.unite(u, v);
    }

    // Reading edges for graph G and applying union
    for (int i = 0; i < m2; i++) {
      int u, v;
      cin >> u >> v;
      dsuG.unite(u, v);
    }

    // Count the number of components in graph F and graph G
    int compF = 0, compG = 0;
    for (int i = 1; i <= n; i++) {
      if (dsuF.find(i) == i)
        compF++;
      if (dsuG.find(i) == i)
        compG++;
    }

    // The minimum number of operations required
    int result = max(compF, compG) - 1;
    cout << result << endl;
  }

  return 0;
}
