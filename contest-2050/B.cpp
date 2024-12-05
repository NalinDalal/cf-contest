#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Length of the array
    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }

    // Check if the total sum is divisible by n
    if (sum % n != 0) {
      cout << "NO" << endl;
      continue;
    }

    long long target = sum / n;
    bool possible = true;

    // Check if each element can be adjusted to target
    for (int i = 0; i < n; ++i) {
      if (a[i] < target) {
        possible = false;
        break;
      }
    }

    cout << (possible ? "YES" : "NO") << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
