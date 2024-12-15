/* H. Hard Demon Problem
time limit per test3.5 seconds
memory limit per test512 megabytes
Swing is opening a pancake factory! A good pancake factory must be good at
flattening things, so Swing is going to test his new equipment on 2D matrices.

Swing is given an 𝑛×𝑛
 matrix 𝑀
 containing positive integers. He has 𝑞
 queries to ask you.

For each query, he gives you four integers 𝑥1
, 𝑦1
, 𝑥2
, 𝑦2
 and asks you to flatten the submatrix bounded by (𝑥1,𝑦1)
 and (𝑥2,𝑦2)
 into an array 𝐴
. Formally,
𝐴=[𝑀(𝑥1,𝑦1),𝑀(𝑥1,𝑦1+1),…,𝑀(𝑥1,𝑦2),𝑀(𝑥1+1,𝑦1),𝑀(𝑥1+1,𝑦1+1),…,𝑀(𝑥2,𝑦2)]
.

The following image depicts the flattening of a submatrix bounded by the red
dotted lines. The orange arrows denote the direction that the elements of the
submatrix are appended to the back of 𝐴 , and 𝐴 is shown at the bottom of the
image.


Afterwards, he asks you for the value of ∑|𝐴|𝑖=1𝐴𝑖⋅𝑖
 (sum of 𝐴𝑖⋅𝑖
 over all 𝑖
).

Input
The first line contains an integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

The first line of each test contains two integers 𝑛
 and 𝑞
 (1≤𝑛≤2000,1≤𝑞≤106
) — the length of 𝑀
 and the number of queries.

The following 𝑛
 lines contain 𝑛
 integers each, the 𝑖
'th of which contains 𝑀(𝑖,1),𝑀(𝑖,2),…,𝑀(𝑖,𝑛)
 (1≤𝑀(𝑖,𝑗)≤106
).

The following 𝑞
 lines contain four integers 𝑥1
, 𝑦1
, 𝑥2
, and 𝑦2
 (1≤𝑥1≤𝑥2≤𝑛,1≤𝑦1≤𝑦2≤𝑛
) — the bounds of the query.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2000
 and the sum of 𝑞
 over all test cases does not exceed 106
.

Output
For each test case, output the results of the 𝑞
 queries on a new line.

Example
InputCopy
2
4 3
1 5 2 4
4 9 5 3
4 5 2 3
1 5 5 2
1 1 4 4
2 2 3 3
1 2 4 3
3 3
1 2 3
4 5 6
7 8 9
1 1 1 3
1 3 3 3
2 2 2 2
OutputCopy
500 42 168
14 42 5
Note
In the second query of the first test case, 𝐴=[9,5,5,2]
. Therefore, the sum is 1⋅9+2⋅5+3⋅5+4⋅2=42
.


*/

#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    vector<vector<long long>> prefix(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> M[i][j];
      }
    }

    // Precompute weighted prefix sums
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        long long weight = M[i][j] * (static_cast<long long>((i - 1) * n + j));
        prefix[i][j] =
            weight + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
      }
    }

    // Process queries
    while (q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      long long result = prefix[x2][y2] - (x1 > 1 ? prefix[x1 - 1][y2] : 0) -
                         (y1 > 1 ? prefix[x2][y1 - 1] : 0) +
                         (x1 > 1 && y1 > 1 ? prefix[x1 - 1][y1 - 1] : 0);
      cout << result << " ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
