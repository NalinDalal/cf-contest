#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int t; // Number of test cases
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Calculate modulo values
    unordered_map<int, int> mod_count; // Track modulo frequencies
    vector<int> mod_values(n);
    for (int i = 0; i < n; i++) {
      mod_values[i] = a[i] % k;
      mod_count[mod_values[i]]++;
    }

    if (mod_count.size() == 1) {
      // All elements have the same modulo -> impossible to win
      cout << "NO" << endl;
    } else {
      // Possible to win
      cout << "YES" << endl;
      // Find any index with a unique modulo (or just the first index)
      cout << 1 << endl; // 1-based index
    }
  }

  return 0;
}
