/*D. Counting Points
* time limit per test2 seconds
memory limit per test256 megabytes
The pink soldiers drew 𝑛
 circles with their center on the 𝑥
-axis of the plane. Also, they have told that the sum of radii is exactly 𝑚
∗
.

Please find the number of integer points inside or on the border of at least one
circle. Formally, the problem is defined as follows.

You are given an integer sequence 𝑥1,𝑥2,…,𝑥𝑛
 and a positive integer sequence 𝑟1,𝑟2,…,𝑟𝑛
, where it is known that ∑𝑛𝑖=1𝑟𝑖=𝑚
.

You must count the number of integer pairs (𝑥,𝑦)
 that satisfy the following condition.

There exists an index 𝑖
 such that (𝑥−𝑥𝑖)2+𝑦2≤𝑟2𝑖
 (1≤𝑖≤𝑛
).
∗
Is this information really useful? Don't ask me; I don't really know.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤𝑚≤2⋅105
).

The second line of each test case contains 𝑥1,𝑥2,…,𝑥𝑛
 — the centers of the circles (−109≤𝑥𝑖≤109
).

The third line of each test case contains 𝑟1,𝑟2,…,𝑟𝑛
 — the radii of the circles (1≤𝑟𝑖
, ∑𝑛𝑖=1𝑟𝑖=𝑚
).

It is guaranteed that the sum of 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the number of integer points satisfying the condition
on a separate line.

Example
InputCopy
4
2 3
0 0
1 2
2 3
0 2
1 2
3 3
0 2 5
1 1 1
4 8
0 5 10 15
2 2 2 2
OutputCopy
13
16
14
52
Note
On the first test case, the circle with 𝑟1=1
 is completely inside the circle with 𝑟2=2
. Therefore, you only have to count the number of integer points inside the
latter. There are 13 integer points such that 𝑥2+𝑦2≤22 , so the answer is 13
.

On the second test case, the circle with 𝑟1=1
 is not completely inside the circle with 𝑟2=2
. There are 3
 additional points that are inside the first circle but not inside the second
circle, so the answer is 3+13=16
.*/

#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;

int count_points(int x_center, int r) {
  int count = 0;
  for (int y = -r; y <= r; y++) {
    int max_x_offset = (int)floor(sqrt(r * r - y * y));
    count += 2 * max_x_offset + 1;
  }
  return count;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    cin >> r[i];

  unordered_set<pair<int, int>, hash<pair<int, int>>> seen;
  ll total_count = 0;

  for (int i = 0; i < n; i++) {
    int xi = x[i], ri = r[i];
    for (int y = -ri; y <= ri; y++) {
      int max_x_offset = (int)floor(sqrt(ri * ri - y * y));
      for (int dx = -max_x_offset; dx <= max_x_offset; dx++) {
        int x_val = xi + dx;
        if (seen.insert({x_val, y}).second) {
          total_count++;
        }
      }
    }
  }

  cout << total_count << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
