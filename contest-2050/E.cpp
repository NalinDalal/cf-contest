#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t; // Number of test cases

  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        int k = i + j;
        if (k > c.size())
          continue;

        if (i > 0 && c[k - 1] == a[i - 1]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
        if (i > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        }
        if (j > 0 && c[k - 1] == b[j - 1]) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
        if (j > 0) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
      }
    }

    cout << dp[n][m] << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
