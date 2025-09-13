/*B. Lasers
time limit per test2 seconds
memory limit per test256 megabytes
There is a 2D-coordinate plane that ranges from (0,0)
 to (𝑥,𝑦)
. You are located at (0,0)
 and want to head to (𝑥,𝑦)
.

However, there are 𝑛
 horizontal lasers, with the 𝑖
-th laser continuously spanning (0,𝑎𝑖)
 to (𝑥,𝑎𝑖)
. Additionally, there are also 𝑚
 vertical lasers, with the 𝑖
-th laser continuously spanning (𝑏𝑖,0)
 to (𝑏𝑖,𝑦)
.

You may move in any direction to reach (𝑥,𝑦)
, but your movement must be a continuous curve that lies inside the plane. Every
time you cross a vertical or a horizontal laser, it counts as one crossing.
Particularly, if you pass through an intersection point between two lasers, it
counts as two crossings.

For example, if 𝑥=𝑦=2[48;54;204;1728;2856t
, 𝑛=𝑚=1
, 𝑎=[1]
, 𝑏=[1]
, the movement can be as follows:


What is the minimum number of crossings necessary to reach (𝑥,𝑦)
?

Input
The first line contains 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains four integers 𝑛
, 𝑚
, 𝑥
, and 𝑦
 (1≤𝑛,𝑚≤2⋅105,2≤𝑥,𝑦≤109
).

The following line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0<𝑎𝑖<𝑦
)  — the y-coordinates of the horizontal lasers. It is guaranteed that 𝑎𝑖>𝑎𝑖−1
 for all 𝑖>1
.

The following line contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (0<𝑏𝑖<𝑥
)  — the x-coordinates of the vertical lasers. It is guaranteed that 𝑏𝑖>𝑏𝑖−1
 for all 𝑖>1
.

It is guaranteed that the sum of 𝑛
 and 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum number of crossings necessary to reach
(𝑥,𝑦)
.

Example
InputCopy
2
1 1 2 2
1
1
2 1 100000 100000
42 58
32
OutputCopy
2
3
*/

/*originally at (0,0)
 want to reach (x,y)

 n laser -> (0,ai) to (x,ai)=> block ai for x=0 to x=x
 m laser-> (bi,0) to (bi,y) => block bi for y=0 to y=y

 min crossing to reach (x,y)

 so we need to find what start and end point ke beech me kin jagah pr lasers h
 if at border, no crossing needed

 min 2 crossing needed, so like 0 to x,ai<y=> ans++
 like 0 to y,bi<x=> ans++
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];

    int ans = 0; // min crossing to reach (x,y)
                 // count horizontal lasers that block path
    for (int ai : a) {
      if (ai > 0 && ai < y)
        ans++;
    }

    // count vertical lasers that block path
    for (int bi : b) {
      if (bi > 0 && bi < x)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2148/submission/338403849
