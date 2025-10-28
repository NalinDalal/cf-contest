/*E. khba Loves to Sleep!
time limit per test3 seconds
memory limit per test256 megabytes
khba has 𝑛
 friends, each standing on a line at position 𝑎𝑖
, and each of them is in the range [0,𝑥]
.

They all want to come to him. One of his friends, Isamatdin, gave him 𝑘
 teleports. Each friend will walk to the nearest teleport (choosing the shortest
distance). Once a friend reaches a teleport, khba and the friend can instantly
meet .

But khba is so tired that he'll be sleeping while his friends are walking toward
him. Now he wants to choose 𝑘 teleport positions so that their positions are
distinct and lie within the range [0,𝑥] , in order to maximize the time it takes
for the first friend who reaches a teleport to reach it. Assume that friends
move at the same speed.

Since khba isn't good at calculations, you should output the 𝑘
 chosen teleport positions.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case contains three integers 𝑛
, 𝑘
, and 𝑥
 (1≤𝑛,𝑘≤2⋅105
, 𝑘−1≤𝑥≤109
) — the number of friends, the number of teleports, and the range of possible
positions for the teleports.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑥
) — the positions of khba's friends.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

It is guaranteed that the sum of 𝑘
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single line containing 𝑘
 integers — the 𝑘
 chosen teleport positions. The positions must be distinct and lie within the
range [0,𝑥] . The positions may be output in any order.

If there are multiple optimal choices, output any of them.

Example
InputCopy
10
4 1 4
1 0 2 4
5 5 4
0 1 2 3 4
2 1 4
4 0
3 4 6
2 4 3
3 2 12
6 12 0
4 3 12
8 12 0 4
1 1 1000000000
0
1 1 1000000000
1000000000
3 4 9
8 7 9
3 4 9
2 0 1
OutputCopy
3
0 1 2 3 4
2
0 1 5 6
3 9
2 6 10
1000000000
0
0 1 2 3
6 7 8 9
Note
Sample 1. Friends at positions [1,0,2,4]
. Chosen teleport position: [3]
.

Nearest teleport for each friend is in 3
, minimal times for friends are [2,3,1,1]
, respectively.

Sample 2. Friends at positions [0,1,2,3,4]
. Chosen teleport positions: [0,1,2,3,4]
.

Minimal times for friends are [0,0,0,0,0]
, respectively.

Sample 3. Friends at positions [4,0]
. Chosen teleport position: [2]
.

Minimal times for friends are [2,2]
, respectively.

Sample 4. Friends at positions [2,4,3]
. Chosen teleport positions: [0,1,5,6]
.

Minimal times for friends are [1,1,2]
, respectively.

Sample 5. Friends at positions [6,12,0]
. Chosen teleport positions: [3,9]
.

Minimal times for friends are [3,3,3]
, respectively.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a.begin(), a.end());

    vector<pair<long long, long long>> gaps;
    // Beginning gap
    gaps.push_back({a[0], 0});
    // Middle gaps
    for (int i = 1; i < n; ++i) {
      long long mid = (a[i - 1] + a[i]) / 2;
      gaps.push_back({mid - a[i - 1], a[i - 1]});
    }
    // Ending gap
    gaps.push_back({x - a[n - 1], a[n - 1]});

    // Sort gaps by size descending, pick k largest
    sort(gaps.rbegin(), gaps.rend());
    vector<long long> teleports;
    for (int i = 0; i < k; ++i) {
      long long pos = gaps[i].second + gaps[i].first;
      teleports.push_back(pos);
    }

    for (int i = 0; i < (int)teleports.size(); ++i)
      cout << teleports[i] << " \n"[i + 1 == (int)teleports.size()];
  }
  return 0;
}
// sub: https://codeforces.com/contest/2167/submission/346297528
