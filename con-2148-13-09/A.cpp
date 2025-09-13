/*A. Sublime Sequence
time limit per test1 second
memory limit per test256 megabytes
Farmer John has an integer 𝑥
. He creates a sequence of length 𝑛
 by alternating integers 𝑥
 and −𝑥
, starting with 𝑥
.

For example, if 𝑛=5
, the sequence looks like: 𝑥,−𝑥,𝑥,−𝑥,𝑥
.

He asks you to find the sum of all integers in the sequence.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
)  — the number of test cases.

The only line of input for each test case is two integers 𝑥
 and 𝑛
 (1≤𝑥,𝑛≤10
).

Output
For each test case, output the sum of all integers in the sequence.

Example
InputCopy
4
1 4
2 5
3 6
4 7
OutputCopy
0
2
0
4
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int x, n;
    cin >> x >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      if (i % 2)
        v[i] = -x;
      else
        v[i] = x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += v[i];
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2148/submission/338388883
