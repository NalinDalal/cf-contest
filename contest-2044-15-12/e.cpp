/* E. Insane Problem
time limit per test2 seconds
memory limit per test256 megabytes
Wave is given five integers 𝑘, 𝑙1, 𝑟1, 𝑙2, and 𝑟2. Wave wants you to help her
count the number of ordered pairs (𝑥,𝑦) such that all of the following are
satisfied:
- 𝑙1≤𝑥≤𝑟1
- 𝑙2≤𝑦≤𝑟2
- There exists a non-negative integer 𝑛 such that 𝑦𝑥=𝑘𝑛.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The only line of each test case contains five integers 𝑘, 𝑙1, 𝑟1, 𝑙2, and 𝑟2
(2≤𝑘≤109,1≤𝑙1≤𝑟1≤109,1≤𝑙2≤𝑟2≤109).

Output
For each test case, output the number of matching ordered pairs (𝑥,𝑦) on a new
line.

Example
InputCopy
5
2 2 6 2 12
2 1 1000000000 1 1000000000
3 5 7 15 63
1000000000 1 5 6 1000000000
15 17 78 2596 20914861
OutputCopy
12
1999999987
6
1
197
Note
In the third test case, the matching ordered pairs are the following:

(5,15)
(5,45)
(6,18)
(6,54)
(7,21)
(7,63)
In the fourth test case, the only valid ordered pair is (1,1000000000)


*/

/*
#include <iostream>
#include <vector>

//l1≤x≤r1
//l2≤y≤r2
//y/x=k^n

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int 𝑘, l1, 𝑟1, l2, 𝑟2;
    std::cin >> k >> l1 >> r1 >> l2 >> r2;
    std::vector<int> v;
    for (int i = 1; i < k; i++) {
      int x, y;
      cin >> x >> y;
      v.push_back(x);
      v.push_back(y);
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i + 2) {
      if (v[i] <= l1 && v[i + 1] >= l2) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
*/

#include <cmath>
#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    long long count = 0;

    // Iterate over all possible x in range [l1, r1]
    for (long long x = l1; x <= r1; x++) {
      long long power = 1; // Start with k^0 = 1
      while (true) {
        long long y = x * power;
        if (y > r2)
          break; // Stop if y exceeds r2
        if (y >= l2)
          count++; // Count valid (x, y)
        if (power > r2 / k)
          break;    // Prevent overflow for power * k
        power *= k; // Move to the next power of k
      }
    }

    cout << count << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
