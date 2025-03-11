/* C. XOR and Triangle
time limit per test2 seconds
memory limit per test256 megabytes
This time, the pink soldiers have given you an integer 𝑥
 (𝑥≥2
).

Please determine if there exists a positive integer 𝑦
 that satisfies the following conditions.

𝑦
 is strictly less than 𝑥
.
There exists a non-degenerate triangle∗
 with side lengths 𝑥
, 𝑦
, 𝑥⊕𝑦
. Here, ⊕
 denotes the bitwise XOR operation.
Additionally, if there exists such an integer 𝑦
, output any.

∗
A triangle with side lengths 𝑎
, 𝑏
, 𝑐
 is non-degenerate when 𝑎+𝑏>𝑐
, 𝑎+𝑐>𝑏
, 𝑏+𝑐>𝑎
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2000
). The description of the test cases follows.

The only line of each test case contains a single integer 𝑥
 (2≤𝑥≤109
).

Output
For each test case, print one integer on a separate line. The integer you must
output is as follows:

If there exists an integer 𝑦
 satisfying the conditions, output the value of 𝑦
 (1≤𝑦<𝑥
);
Otherwise, output −1
.
If there exist multiple integers that satisfy the conditions, you may output
any.

Example
InputCopy
7
5
2
6
3
69
4
420
OutputCopy
3
-1
5
-1
66
-1
320
Note
In the first test case, there exists a non-degenerate triangle with side lengths
3 , 5 , and 3⊕5=6 . Therefore, 𝑦=3 is a valid answer.

In the second test case, 1
 is the only possible candidate for 𝑦
, but it cannot make a non-degenerate triangle. Therefore, the answer is −1
.


*/
#include <iostream>
using namespace std;
// find y such that 1<=y<x ; x,y,xbitwise XOR y form a triangle
// let c=xbitwise XOR y
// so condition: x+y>c,x+c>y,y+c>x

// tle one->
void solve() {
  int x;
  cin >> x;

  for (int y = x - 1; y >= 1; y--) {
    int z = x ^ y; // Compute XOR result
    if (z > 0 && y + z > x && x + z > y && x + y > z) {
      cout << y << "\n";
      return;
    }
  }

  cout << "-1\n"; // No valid y found
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
// check later
