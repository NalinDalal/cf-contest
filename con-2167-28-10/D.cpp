/*D. Yet Another Array Problem
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑛
 and an array 𝑎
 of length 𝑛
.

Find the smallest integer 𝑥
 (2≤𝑥≤1018
) such that there exists an index 𝑖
 (1≤𝑖≤𝑛
) with gcd
∗
(𝑎𝑖,𝑥)=1
. If no such 𝑥
 exists within the range [2,1018]
, output −1
.

∗
gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each of the following 𝑡
 test cases consists of two lines:

The first line contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array.

The second line contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1018
).

It is guaranteed that the total sum of 𝑛
 across all test cases does not exceed 105
.

Output
For each test case, output a single integer: the smallest 𝑥
 (2≤𝑥≤1018
) such that there exists an index 𝑖
 with gcd(𝑎𝑖,𝑥)=1
. If there is no such 𝑥
 in the range [2,1018]
, print −1
.

Example
InputCopy
4
1
1
4
6 6 12 12
3
24 120 210
4
2 4 6 10
OutputCopy
2
5
5
3
Note
In the first test case, gcd(2,1)=1
, which is the smallest number satisfying the condition.

In the second test case:

gcd(2,6)=2
, gcd(2,12)=2
, so 2
 cannot be the answer.
gcd(3,6)=3
, gcd(3,12)=3
, so 3
 cannot be the answer.
gcd(4,6)=2
, gcd(4,12)=4
, so 4
 cannot be the answer.
gcd(5,6)=1
, so the answer is 5
.
In the third test case:

gcd(2,24)=2
, gcd(2,120)=2
, gcd(2,210)=2
, so 2
 cannot be the answer.
gcd(3,24)=3
, gcd(3,120)=3
, gcd(3,210)=3
, so 3
 cannot be the answer.
gcd(4,24)=4
, gcd(4,120)=4
, gcd(4,210)=2
, so 4
 cannot be the answer.
gcd(5,24)=1
, so the answer is 5
.
In the fourth test case:

gcd(2,2)=2
, gcd(2,4)=2
, gcd(2,6)=2
, gcd(2,10)=2
, so 2
 cannot be the answer.
gcd(3,2)=1
, so the answer is 3
.
*/

// find ans such that gcd(a[i],ans)=1 else ans=-1
/*If g > 1, then every a[i] is divisible by g,
so no number (in any range) that shares that factor can be coprime with all —
except numbers not divisible by that factor.

But the problem gives a finite range [2, 10¹⁸], not infinite.

So we need to find one integer in that range that is coprime to all a[i].
    */
/*Compute the gcd of all elements.
    If g > 1, print -1.

Else, try small numbers ans in [2, 100] — find one that has gcd(ans, a[i]) == 1
for all i. If found → print it. Else → -1.

Since n ≤ 2e5, this is efficient.
*/
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64> a(n);
    for (auto &x : a)
      cin >> x;

    int64 g = a[0];
    for (int i = 1; i < n; i++)
      g = gcd(g, a[i]);

    if (g > 1) {
      cout << -1 << "\n";
      continue;
    }

    // find a number between [2, 1e18] coprime with all a[i]
    bool found = false;
    for (int64 candidate = 2; candidate <= 100; candidate++) {
      bool ok = true;
      for (auto x : a) {
        if (gcd(candidate, x) != 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << candidate << "\n";
        found = true;
        break;
      }
    }

    if (!found)
      cout << -1 << "\n";
  }

  return 0;
}
