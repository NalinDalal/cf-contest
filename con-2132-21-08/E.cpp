/*E. Arithmetics Competition
time limit per test3 seconds
memory limit per test256 megabytes
In the arithmetic competition, participants need to achieve the highest possible
sum from the cards they have. In the team "fst_ezik", Vadim has 𝑛 cards with
numbers 𝑎𝑖 , and Kostya has 𝑚 cards with numbers 𝑏𝑖 . In each of the 𝑞 rounds,
they want to win, but this time the rules of the competition are slightly
different from the usual ones.

In each round, the participants are given three numbers 𝑥𝑖
, 𝑦𝑖
, and 𝑧𝑖
. The team "fst_ezik" must choose exactly 𝑧𝑖
 cards from all the cards they have, but Vadim can choose no more than 𝑥𝑖
 cards from his set, and Kostya can choose no more than 𝑦𝑖
 cards from his set. Help them find the highest possible sum for each of the 𝑞
 rounds.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104) — the number of test cases. The descriptions of the test
cases follow.

In the first line of each test case, three integers 𝑛
, 𝑚
, 𝑞
 are given (1≤𝑛,𝑚≤2⋅105,1≤𝑞≤105)
 — the number of cards Vadim has, the number of cards Kostya has, and the number
of rounds in the competition.

The second line contains 𝑛
 integers 𝑎𝑖
 — the numbers on Vadim's cards (1≤𝑎𝑖≤109)
.

The third line contains 𝑚
 integers 𝑏𝑖
 — the numbers on Kostya's cards (1≤𝑏𝑖≤109)
.

The following 𝑞
 lines describe the rounds with three integers 𝑥𝑖
, 𝑦𝑖
, 𝑧𝑖
 (0≤𝑥𝑖≤𝑛,0≤𝑦𝑖≤𝑚,0≤𝑧𝑖≤𝑥𝑖+𝑦𝑖)
 — the limit on the number of cards Vadim can choose, the limit on the number of
cards Kostya can choose, and the number of cards they need to select together.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
, the sum of 𝑚
 across all test cases does not exceed 2⋅105
, and the sum of 𝑞
 across all test cases does not exceed 105
.

Output
For each test case, output 𝑞
 numbers — the highest possible sum for the corresponding round.

Example
InputCopy
4
3 4 5
10 20 30
1 2 3 4
0 0 0
3 4 7
3 4 4
1 4 4
2 2 4
5 5 2
500000000 300000000 100000000 900000000 700000000
800000000 400000000 1000000000 600000000 200000000
1 4 3
5 2 6
4 4 1
100 100 20 20
100 100 20 20
4 4 5
3 3 6
2 363 711
286 121 102
1 1 1
3 1 1
1 2 0
1 3 2
0 1 0
3 3 3
OutputCopy
0
70
64
39
57
2700000000
4200000000
420
711
711
0
997
0
1360
*/

/* Vadim has n cards a[i], Kostya has m cards b[i].
For each round, we are given (x, y, z):
    - Need to pick exactly z cards in total.
    - Can pick at most x from Vadim’s set, at most y from Kostya’s set.
We want the maximum sum of chosen cards.
*/

/*1. sort both arrays in descending order
2. find prefixSum of A,B
    - prefA[i] = sum of top i elements of a
    - prefB[i] = sum of top i elements of b
3. for query(x,y,z):
    - pick total z cards
    i = number picked from A, j = number picked from B.
pick i from A and z - i from B, with i ∈ [L, U] where
L = max(0, z - y) and U = min(z, x).

Let f(i) = prefA[i] + prefB[z - i].
f(i) is unimodal (since f(i+1) - f(i) = a[i] - b[z - i - 1] with sorted
non-increasing a, b). So we can find the maximum with a binary search on the
peak by comparing f(mid) vs f(mid+1).
*/

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> a(n), b(m);
    for (auto &x : a)
      cin >> x;
    for (auto &x : b)
      cin >> x;

    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end(), greater<long long>());

    // prefix sums: prefX[t] = sum of top t elements (t in [0..size])
    vector<long long> prefA(n + 1, 0), prefB(m + 1, 0);
    for (int i = 0; i < n; ++i)
      prefA[i + 1] = prefA[i] + a[i];
    for (int i = 0; i < m; ++i)
      prefB[i + 1] = prefB[i] + b[i];

    auto F = [&](int i, int z) -> long long {
      // i in [0..n], z-i in [0..m]
      return prefA[i] + prefB[z - i];
    };

    while (q--) {
      int x, y, z;
      cin >> x >> y >> z;

      // feasible i range
      int L = max(0, z - y);
      int U = min(z, x);

      // also cap by available counts (though x<=n, y<=m per input)
      L = max(L, 0);
      U = min(U, n);
      if (z - L > m)
        L = z - m; // ensure z-i <= m
      if (z - U < 0)
        U = z; // ensure z-i >= 0

      if (L > U) {
        cout << 0 << '\n'; // impossible under given limits
        continue;
      }

      // Handle z - i bounds as well
      if (z - L < 0 || z - U > m) {
        cout << 0 << '\n';
        continue;
      }

      // Discrete ternary/binary search on unimodal f(i)
      int lo = L, hi = U;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        long long fmid = F(mid, z);
        long long fmid1 = F(mid + 1, z); // mid+1 is valid since mid < hi
        if (fmid <= fmid1)
          lo = mid + 1;
        else
          hi = mid;
      }
      cout << F(lo, z) << '\n';
    }
  }
  return 0;
}
// sub: https://codeforces.com/contest/2132/submission/334914879
