/* F. Trulimero Trulicina
time limit per test2 seconds
memory limit per test256 megabytes
Trulicina gives you integers 𝑛
, 𝑚
, and 𝑘
. It is guaranteed that 𝑘≥2
 and 𝑛⋅𝑚≡0(mod𝑘)
.

Output a 𝑛
 by 𝑚
 grid of integers such that each of the following criteria hold:

Each integer in the grid is between 1
 and 𝑘
, inclusive.
Each integer from 1
 to 𝑘
 appears an equal number of times.
No two cells that share an edge have the same integer.
It can be shown that such a grid always exists. If there are multiple solutions,
output any.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains three integers 𝑛
, 𝑚
, and 𝑘
 (2≤𝑛⋅𝑚≤2⋅105,2≤𝑘≤𝑛⋅𝑚,𝑛⋅𝑚≡0(mod𝑘)
.

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 lines, each containing 𝑚
 integers that satisfy the criteria. If there are multiple solutions, output
any.

Example
InputCopy
3
2 2 2
3 4 6
5 5 25
OutputCopy
1 2
2 1
1 6 1 6
2 5 2 5
3 4 3 4
17 2 12 25 14
3 1 6 19 11
8 20 23 24 4
9 10 5 13 21
22 7 15 18 16
*/
/* We are given the task of creating an n × m grid filled with integers from 1
to k, such that:

Each number from 1 to k appears exactly the same number of times.

No two adjacent (edge-sharing) cells have the same value.

n * m % k == 0, so it's guaranteed the distribution is fair.

Constraints allow us to do this efficiently: ∑(n⋅m) ≤ 2×10⁵

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> colors;
    for (int i = 1; i <= k; ++i)
      colors.push_back(i);

    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        for (int j = 0; j < m; ++j) {
          grid[i][j] = colors[cur];
          cur = (cur + 1) % k;
        }
      } else {
        for (int j = m - 1; j >= 0; --j) {
          grid[i][j] = colors[cur];
          cur = (cur + 1) % k;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << grid[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
