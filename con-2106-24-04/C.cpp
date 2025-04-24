/* C. Cherry Bomb
time limit per test2 seconds
memory limit per test256 megabytes
Two integer arrays 𝑎
 and 𝑏
 of size 𝑛
 are complementary if there exists an integer 𝑥
 such that 𝑎𝑖+𝑏𝑖=𝑥
 over all 1≤𝑖≤𝑛
. For example, the arrays 𝑎=[2,1,4]
 and 𝑏=[3,4,1]
 are complementary, since 𝑎𝑖+𝑏𝑖=5
 over all 1≤𝑖≤3
. However, the arrays 𝑎=[1,3]
 and 𝑏=[2,1]
 are not complementary.

Cow the Nerd thinks everybody is interested in math, so he gave Cherry Bomb two
complementary integer arrays 𝑎 and 𝑏 . It is known that 𝑎 and 𝑏 both contain 𝑛
 non-negative integers at most 𝑘
.

Unfortunately, Cherry Bomb has lost some elements in 𝑏
. Lost elements in 𝑏
 are denoted with −1
. Help Cherry Bomb count the number of possible arrays 𝑏
 such that:

𝑎
 and 𝑏
 are complementary.
All lost elements are replaced with non-negative integers no more than 𝑘
.
Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
, 0≤𝑘≤109
) — the size of the arrays and the maximum possible value of their elements.

The second line contains 𝑛
 integers 𝑎1,𝑎2,...,𝑎𝑛
 (0≤𝑎𝑖≤𝑘
).

The third line contains 𝑛
 integers 𝑏1,𝑏2,...,𝑏𝑛
 (−1≤𝑏𝑖≤𝑘
). If 𝑏𝑖=−1
, then this element is missing.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
Output exactly one integer, the number of ways Cherry Bomb can fill in the
missing elements from 𝑏 such that 𝑎 and 𝑏 are complementary.

Example
InputCopy
7
3 10
1 3 2
-1 -1 1
5 1
0 1 0 0 1
-1 0 1 0 -1
5 1
0 1 0 0 1
-1 1 -1 1 -1
5 10
1 3 2 5 4
-1 -1 -1 -1 -1
5 4
1 3 2 1 3
1 -1 -1 1 -1
5 4
1 3 2 1 3
2 -1 -1 2 0
5 5
5 0 5 4 3
5 -1 -1 -1 -1
OutputCopy
1
0
0
7
0
1
0
Note
In the first example, the only way to fill in the missing elements in 𝑏
 such that 𝑎
 and 𝑏
 are complementary is if 𝑏=[2,0,1]
.

In the second example, there is no way to fill in the missing elements of 𝑏
 such that 𝑎
 and 𝑏
 are complementary.

In the fourth example, some 𝑏 arrays that are complementary to 𝑎 are:
[4,2,3,0,1],[7,5,6,3,4], and [9,7,8,5,6].*/

/* given two arrays a and b of size n, where:

Some elements of b are missing (represented as -1).

The arrays are complementary if there exists one constant x such
that:a[i]+b[i]== x

for all i Your task: 👉 Count how many ways the missing
elements in b can be filled (with numbers between 0 and k) so that the condition
holds.
*/

// given 2 vector a,b
// a[i]+b[i] is always x
// but some elements of b are missed, denoted by -1
// b[i]<=k
/* Find possible values of x
Count how many values of x are compatible with:
All known (a[i] + b[i])
And for each unknown b[i] = x - a[i], it must be in [0, k]*/

/* Step 1: Find valid x from known pairs
If b[i] != -1, then x = a[i] + b[i].
Every such sum must match — otherwise, impossible.

Step 2: Try all such valid x
If no known values ⇒ we can try all x from a[i] + 0 to a[i] + k

For each candidate x, do:
- For every unknown b[i] = x - a[i]:
    - Check if 0 ≤ b[i] ≤ k
- If all valid → count this x*/

// final
/*1. Find all valid x candidates:
- If some b[i] != -1: only one x = a[i] + b[i] is allowed
- If all b[i] == -1: try all x in [max(a) .. max(a)+k]

2. For each candidate x, check:
- For each unknown: is x - a[i] in [0..k]?

3. Count valid `x`*/

/*#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    set<long long> x_candidates;

    // Step 1: find possible x values from known b[i]
    bool has_known = false;
    long long fixed_x = -1;
    bool invalid = false;

    for (int i = 0; i < n; i++) {
      if (b[i] != -1) {
        has_known = true;
        long long current_x = a[i] + b[i];
        if (fixed_x == -1)
          fixed_x = current_x;
        else if (fixed_x != current_x) {
          invalid = true;
          break;
        }
      }
    }

    if (invalid) {
      cout << 0 << "\n";
      continue;
    }

    // Step 2: if we have fixed x, check if we can fill in unknowns
    if (has_known) {
      bool possible = true;
      for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
          long long bi = fixed_x - a[i];
          if (bi < 0 || bi > k) {
            possible = false;
            break;
          }
        }
      }
      cout << (possible ? 1 : 0) << "\n";
    } else {
      // No fixed x — try all x values from max(a) to max(a) + k
      long long max_a = *max_element(a.begin(), a.end());
      long long count = 0;

      for (long long x = max_a; x <= max_a + k; x++) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
          long long bi = x - a[i];
          if (bi < 0 || bi > k) {
            valid = false;
            break;
          }
        }
        if (valid)
          count++;
      }
      cout << count << "\n";
    }
  }

  return 0;
}*/

// all elements in a, x must lie in: [max(a[i]), min(a[i] + k)]
// valid x values are in the range:[ max(a[i]), min(a[i] + k) ] for all i

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    set<long long> x_candidates;

    // Step 1: find possible x values from known b[i]
    bool has_known = false;
    long long fixed_x = -1;
    bool invalid = false;

    for (int i = 0; i < n; i++) {
      if (b[i] != -1) {
        has_known = true;
        long long current_x = a[i] + b[i];
        if (fixed_x == -1)
          fixed_x = current_x;
        else if (fixed_x != current_x) {
          invalid = true;
          break;
        }
      }
    }

    if (invalid) {
      cout << 0 << "\n";
      continue;
    }

    // Step 2: if we have fixed x, check if we can fill in unknowns
    if (has_known) {
      bool possible = true;
      for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
          long long bi = fixed_x - a[i];
          if (bi < 0 || bi > k) {
            possible = false;
            break;
          }
        }
      }
      cout << (possible ? 1 : 0) << "\n";
    } else {
      long long lower_bound = 0;
      long long upper_bound = LLONG_MAX;

      for (int i = 0; i < n; i++) {
        lower_bound = max(lower_bound, a[i]);
        upper_bound = min(upper_bound, a[i] + k);
      }

      long long count = max(0LL, upper_bound - lower_bound + 1);
      cout << count << "\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/contest/2106/submission/317053920
