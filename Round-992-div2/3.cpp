/*#include <iostream>

int main() {
  int t, n;
  std::cin >> t;
  while (t--) {
    for (int l = 0; l < n; l++) {
      for (int r = l; r < l; r <= n; r++) {
        min = min(min + arr[l] + arr[r], min);
      }
    }
  }
  return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout.precision(numeric_limits<double>::max_digits10);

#define int long long

void func(int i, int l, int r, int k, vector<int> &ans) {
  if (l == r) {
    ans[l] = i;
    return;
  }
  int sz = r - l - 1;
  if (sz < 60 && (1LL << sz) < k) {
    ans[r] = i;
    func(i + 1, l, r - 1, k - (1LL << sz), ans);
  } else {
    ans[l] = i;
    func(i + 1, l + 1, r, k, ans);
  }
} // n

void CoderAbhi27() {
  int n, k;
  cin >> n >> k;
  if (n - 1 < 60 && (1LL << (n - 1)) < k) {
    cout << "-1\n";
    return;
  }
  vector<int> ans(n);
  func(1, 0, n - 1, k, ans); // n

  for (auto i : ans)
    cout << i << ' '; // n
  cout << '\n';
}

// tc -> O(n)
// sc->O(n)

int32_t main() {
  fastIO;

  int t = 1;
  cin >> t;
  while (t--) {
    CoderAbhi27();
  }
  return 0;
}

/* Base case: If l == r, place i at index l in ans.
Compute the size of the remaining range (sz = r - l - 1).
Check whether k exceeds the permutations of the remaining sequence ((1LL <<
sz)).
- If k is larger, place i at the end (r) and adjust k.
- Otherwise, place i at the start (l) and proceed recursively.
*/
