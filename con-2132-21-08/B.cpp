/*B. The Secret Number
time limit per test2 seconds
memory limit per test256 megabytes
Vadim has thought of a number 𝑥
. To ensure that no one can guess it, he appended a positive number of zeros to
the right of it, thus obtaining a new number 𝑦 . However, as a precaution, Vadim
decided to spread the number 𝑛=𝑥+𝑦 . Find all suitable 𝑥 that Vadim could have
thought of for the given 𝑛
.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104) — the number of test cases. The following lines describe the
test cases.

In a single line of each test case, there is an integer 𝑛
 — the number spread by Vadim (11≤𝑛≤1018)
.

Output
For each number 𝑛
, output 0
 if there are no suitable 𝑥
. Otherwise, output the number of suitable 𝑥
, followed by all suitable 𝑥
 in ascending order.

Example
InputCopy
5
1111
12
55
999999999999999999
1000000000000000000
OutputCopy
2
11 101
0
1
5
3
999999999 999000999000999 90909090909090909
0
Note
In the first sample, to 11
 one can append two zeros to the right, then 11+1100=1111
, and to 101
 one can append one zero to the right, then 101+1010=1111
.

In the second sample, it is impossible to obtain 12
 through the described actions.
*/

/*given no x
 you get no y which is like adding 0's after x
 n=y+x
 find all suitable x from n in ascending order
 else output 0
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;

    vector<unsigned long long> ans;
    unsigned long long d = 11; // d = 10^k + 1, start with k = 1

    while (d <= n) {
      if (n % d == 0) {
        ans.push_back(n / d);
      }
      // Prevent overflow: stop if next d would exceed 1e18
      if (d > (ULLONG_MAX - 9) / 10)
        break;
      d = d * 10 - 9;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    if (!ans.empty()) {
      for (size_t i = 0; i < ans.size(); ++i) {
        if (i)
          cout << ' ';
        cout << ans[i];
      }
      cout << '\n';
    }
  }
  return 0;
}

// output 0 if not exists
// else output no of suitable x followed by all suitable x

// check divisors of form (10^k + 1)
// move to next power of 10
// sub: https://codeforces.com/contest/2132/submission/334855788
