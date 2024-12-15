/* F. Easy Demon Problem
time limit per test4 seconds
memory limit per test256 megabytes
For an arbitrary grid, Robot defines its beauty to be the sum of elements in the
grid.

Robot gives you an array 𝑎
 of length 𝑛
 and an array 𝑏
 of length 𝑚
. You construct a 𝑛
 by 𝑚
 grid 𝑀
 such that 𝑀𝑖,𝑗=𝑎𝑖⋅𝑏𝑗
 for all 1≤𝑖≤𝑛
 and 1≤𝑗≤𝑚
.

Then, Robot gives you 𝑞
 queries, each consisting of a single integer 𝑥
. For each query, determine whether or not it is possible to perform the
following operation exactly once so that 𝑀 has a beauty of 𝑥
:

Choose integers 𝑟
 and 𝑐
 such that 1≤𝑟≤𝑛
 and 1≤𝑐≤𝑚
Set 𝑀𝑖,𝑗
 to be 0
 for all ordered pairs (𝑖,𝑗)
 such that 𝑖=𝑟
, 𝑗=𝑐
, or both.
Note that queries are not persistent, meaning that you do not actually set any
elements to 0 in the process — you are only required to output if it is possible
to find 𝑟 and 𝑐 such that if the above operation is performed, the beauty of the
grid will be 𝑥 . Also, note that you must perform the operation for each query,
even if the beauty of the original grid is already 𝑥
.

Input
The first line contains three integers 𝑛
, 𝑚
, and 𝑞
 (1≤𝑛,𝑚≤2⋅105,1≤𝑞≤5⋅104
) — the length of 𝑎
, the length of 𝑏
, and the number of queries respectively.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤|𝑎𝑖|≤𝑛
).

The third line contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (0≤|𝑏𝑖|≤𝑚
).

The following 𝑞
 lines each contain a single integer 𝑥
 (1≤|𝑥|≤2⋅105
), the beauty of the grid you wish to achieve by setting all elements in a row
and a column to 0
.

Output
For each testcase, output "YES" (without quotes) if there is a way to perform
the aforementioned operation such that the beauty is 𝑥 , and "NO" (without
quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and
"Yes" will be recognized as a positive response).

Examples
InputCopy
3 3 6
-2 3 -3
-2 2 -1
-1
1
-2
2
-3
3
OutputCopy
NO
YES
NO
NO
YES
NO
InputCopy
5 5 6
1 -2 3 0 0
0 -2 5 0 -3
4
-3
5
2
-1
2
OutputCopy
YES
YES
YES
YES
NO
YES
Note
In the second example, the grid is

0 -2 5 0 -3

0 4 -10 0 6

0 -6 15 0 -9

0 0 0 0 0

0 0 0 0 0

By performing the operation with 𝑟=4
 and 𝑐=2
, we create the following grid:

0 0 5 0 -3

0 0 -10 0 6

0 0 15 0 -9

0 0 0 0 0

0 0 0 0 0

which has beauty 4
. Thus, we output YES.

In the second query, selecting 𝑟=3
 and 𝑐=5
 creates a grid with beauty −3
.

In the third query, selecting 𝑟=3
 and 𝑐=3
 creates a grid with beauty 5
.


*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<long long> a(n), b(m);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int j = 0; j < m; ++j)
    cin >> b[j];

  vector<long long> queries(q);
  for (int i = 0; i < q; ++i)
    cin >> queries[i];

  // Precompute
  long long sumA = 0, sumB = 0;
  for (int i = 0; i < n; ++i)
    sumA += a[i];
  for (int j = 0; j < m; ++j)
    sumB += b[j];

  long long totalBeauty = sumA * sumB;

  unordered_map<long long, int> rowContributions, colContributions;
  for (int i = 0; i < n; ++i)
    rowContributions[a[i] * sumB]++;
  for (int j = 0; j < m; ++j)
    colContributions[b[j] * sumA]++;

  // Process Queries
  for (auto x : queries) {
    bool possible = false;

    // Check if there exists a valid r, c pair
    for (auto [rowValue, freqR] : rowContributions) {
      long long neededColumn = totalBeauty - rowValue - x;
      if (colContributions.count(neededColumn)) {
        possible = true;
        break;
      }
    }

    cout << (possible ? "YES" : "NO") << endl;
  }

  return 0;
}
