
//- -> x    //hyphon
//_ -> y    //underscore
// ans=xC2*y
//=x(x-1)*y/2

/*   int n = 0, y = 0;
   for (int i = 0; i < s.length(); i++) {
     if (s[i] == '-')
       n++;
     else
       y++;
   }
   if (n % 2 == 0) {
     cout << (n / 2) * (n / 2) * y;
   } else {
     cout << ((n + 1) / 2) * (n / 2) * y;
   }
 */
// nume = x ^ 2 *y - xy ans = nume / 2
/*
#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dash_count = 0, underscore_count = 0;

    // Count occurrences of '-' and '_'
    for (char c : s) {
      if (c == '-')
        dash_count++;
      else
        underscore_count++;
    }

    // If there are not enough '-' or no '_', it's impossible
    if (dash_count < 2 || underscore_count == 0) {
      cout << 0 << endl;
    } else {
      // Compute the maximum number of "-_-" subsequences
      long long max_sequences =
          (1LL * dash_count * (dash_count - 1) / 2) * underscore_count;
      cout << max_sequences << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
*/

#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int dash_count = 0, underscore_count = 0;

    // Count occurrences of '-' and '_'
    for (char c : s) {
      if (c == '-')
        dash_count++;
      else
        underscore_count++;
    }

    // If there are not enough '-' or no '_', it's impossible
    if (dash_count < 2 || underscore_count == 0) {
      cout << 0 << endl;
    } else {
      // Split dashes into two groups for max subsequences
      int left_dash = dash_count / 2;
      int right_dash = dash_count - left_dash;
      long long max_sequences = 1LL * left_dash * right_dash * underscore_count;
      cout << max_sequences << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
// done
