#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    vector<int> freq(10, 0); // Frequency of digits
    int n = s.size();

    // Traverse the string from right to left
    for (int i = n - 1; i >= 0; --i) {
      int digit = s[i] - '0';
      // If possible to reduce and shift, increase the count for (digit + 1)
      if (i > 0 && digit < 9) {
        freq[digit + 1]++;
      } else {
        freq[digit]++;
      }
    }

    // Construct the result
    string result = "";
    for (int d = 9; d >= 0; --d) {
      result.append(freq[d], '0' + d);
    }

    cout << result << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
