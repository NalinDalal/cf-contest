/*F. Tree, TREE!!!
time limit per test2 seconds
memory limit per test256 megabytes

Roots change, but the tree stands strong — so should your logic.
Behruzbek received a tree∗
 with 𝑛
 nodes. For a chosen root†
 𝑟
, Behruzbek wants to find cuteness of the tree.

Consider every set of 𝑘
 distinct nodes of the tree. For each such set, compute its lowest common
ancestor (LCA) in the tree when it is rooted at 𝑟 . Let 𝑆𝑟 be the set of all
distinct nodes obtained this way; then cuteness of the tree is |𝑆𝑟| , where |𝑆|
 means the number of distinct elements.

After discovering the cuteness of trees, Behruzbek became interested in finding
the kawaiiness of the tree! Kawaiiness is defined as:

∑𝑟=1𝑛|𝑆𝑟|=|𝑆1|+|𝑆2|+⋯+|𝑆𝑛|

Unfortunately, Behruzbek is feeling sleepy now. Please help Behruzbek by finding
the kawaiiness of the tree!

∗
A tree is a connected graph without cycles.

†
A rooted tree is a tree where one vertex is special and called the root.

Input
The first line contains the number of test cases 𝑡
 (1≤𝑡≤104
).

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑘≤𝑛≤2⋅105
) — the number of vertices in the tree and the number of distinct integers to be
chosen.

The following 𝑛−1
 lines of each test case describe the tree. Each of the lines contains two
integers 𝑢 and 𝑣 (1≤𝑢,𝑣≤𝑛 , 𝑢≠𝑣 ) that indicate an edge between vertex 𝑢 and 𝑣
. It is guaranteed that these edges form a tree.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the value of ∑𝑟=1𝑛|𝑆𝑟|
.

Example
InputCopy
4
2 2
1 2
5 3
1 2
1 3
1 4
1 5
6 3
1 2
1 3
2 4
2 5
3 6
10 5
5 6
4 9
3 9
2 6
2 8
8 9
6 10
1 6
4 7
OutputCopy
2
9
17
35
Note
Let 𝑓(𝑖)=|𝑆𝑖|

For the third example:

Root is 1
, only 1
 and 2
 nodes can be obtained. For example, we can choose: 𝐿𝐶𝐴(4,5,6)=1
 and 𝐿𝐶𝐴(2,4,5)=2
. As a result, 𝑓(1)=2
.

Root is 2
, only 1
 and 2
 nodes can be obtained. For example, we can choose: 𝐿𝐶𝐴(1,3,6)=1
 and 𝐿𝐶𝐴(1,4,5)=2
. As a result, 𝑓(2)=2
.

Root is 3
, 𝑓(3)=3
. For example, node 3
 can be obtained by choosing: 𝐿𝐶𝐴(2,4,6)=3
.

Root is 4
, 𝑓(4)=3
. For example, node 2
 can be obtained by choosing: 𝐿𝐶𝐴(1,3,5)=2
.

Root is 5
, 𝑓(5)=3
. For example, node 2
 can be obtained by choosing: 𝐿𝐶𝐴(3,4,6)=2
.

Root is 6
, 𝑓(6)=4
. For example, node 3
 can be obtained by choosing: 𝐿𝐶𝐴(3,4,5)=2
.
Overall, 2+2+3+3+3+4=17
.
*/

// LCA is node that has common ancestor of both give nodes
// i.e. for nodes v,w; T must be thier parent
// i.e. T has desendants v,w

/*(t--){
 n,k
 n- no of vertices
 k- no of nodes to be chosen
 (n--){
    u,v
    //u,v represnt the nodes which are connected
 }
 ans=|s1|+|s2|+|s3|....+|sn|
 |s1|-> no of distince elemtns
 Consider every set of 𝑘
 distinct nodes of the tree. For each such set, compute its lowest common
ancestor (LCA) in the tree when it is rooted at 𝑟 . Let 𝑆𝑟 be the set of all
distinct nodes obtained this way; then cuteness of the tree is |𝑆𝑟| , where |𝑆|
 means the number of distinct elements.

  }
*/
/*Use combinatorial counting:
    For a node u (under root r), u is LCA for sets if all selected k nodes are
in subtree of u, but not all are in any subtree of child of u. For each node u,
find how many k-sized sets have u as their LCA. Use subtree sizes,
inclusion-exclusion principles.

Preprocessing can be done with DFS for each root or using tree DP to reroot
efficiently.

For k=2, DP or binary lifting makes it practical.


for each test case {
    read n, k
    build tree
    kawaiiness = 0
    for r in 1..n { // each node as root
        reroot tree at r
        compute cuteness = number of unique LCAs among all k-node sets
        kawaiiness += cuteness
    }
    output kawaiiness
}

*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

vector<int> tree[MAXN];
vector<int> subtree_size;
int n, k;
vector<long long> factorial, inv_factorial;

long long binom(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD;
}

void precompute_factorials(int N) {
  factorial.resize(N + 1, 1);
  inv_factorial.resize(N + 1, 1);
  for (int i = 1; i <= N; ++i)
    factorial[i] = factorial[i - 1] * i % MOD;
  inv_factorial[N] = powmod(factorial[N], MOD - 2);
  for (int i = N - 1; i >= 0; --i)
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
}

// DFS to compute subtree sizes.
void dfs(int u, int p) {
  subtree_size[u] = 1;
  for (int v : tree[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    subtree_size[u] += subtree_size[v];
  }
}

int main() {
  int t;
  cin >> t;
  precompute_factorials(MAXN);
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      tree[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    long long total = 0;
    for (int root = 1; root <= n; ++root) {
      subtree_size.assign(n + 1, 0);
      dfs(root, -1);

      // For current root, get cuteness in O(n):
      // For every node, use binomial combinatorics to count valid k-subsets
      // whose LCA is this node. Use "total - invalid" principle with
      // combinatorics.
      vector<int> subsizes;
      for (int v : tree[root])
        subsizes.push_back(subtree_size[v]);
      // compute using inclusion-exclusion
      // etc.

      // Placeholder: for cuteness calculation
      int cuteness = ...;
      total += cuteness;
    }
    cout << total << '\n';
  }
}
