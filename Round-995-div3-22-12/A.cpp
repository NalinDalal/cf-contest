/* A. Preparing for the Olympiad
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp and Stereocarp are preparing for the Olympiad. There are 𝑛
 days left until the Olympiad. On the 𝑖
-th day, if Monocarp plans to practice, he will solve 𝑎𝑖
 problems. Similarly, if Stereocarp plans to practice on the same day, he will
solve 𝑏𝑖 problems.

Monocarp can train on any day he wants. However, Stereocarp watches Monocarp and
follows a different schedule: if Monocarp trained on day 𝑖 and 𝑖<𝑛 , then
Stereocarp will train on day (𝑖+1)
.

Monocarp wants to organize his training process in a way that the difference
between the number of problems he solves and the number of problems Stereocarp
solves is as large as possible. Formally, Monocarp wants to maximize the value
of (𝑚−𝑠) , where 𝑚 is the number of problems he solves, and 𝑠 is the number of
problems Stereocarp solves. Help Monocarp determine the maximum possible
difference in the number of solved problems between them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
).

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤100
).

Output
For each test case, print a single integer — the maximum possible difference
between the number of problems Monocarp solves and the number of problems
Stereocarp solves.

Example
InputCopy
4
2
3 2
2 1
1
5
8
3
1 1 1
2 2 2
6
8 2 5 6 2 6
8 2 7 4 3 4
OutputCopy
4
5
1
16
Note
Let's analyze the example from the statement:

In the first test case, it is optimal for Monocarp to train both days; then
Stereocarp will train on day 2
.
In the second test case, it is optimal for Monocarp to train on the only day,
and Stereocarp will not train at all. In the third test case, it is optimal for
Monocarp to train on the last day (and only on that day). In the fourth test
case, it is optimal for Monocarp to train on days 1,3,4,6 ; then Stereocarp will
train on days 2,4,5
.

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    int max_diff = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int m = 0, s = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) { // Monocarp trains on day i
          m += a[i];
          if (i + 1 < n)
            s += b[i + 1]; // Stereocarp trains on day i+1
        }
      }
      max_diff = max(max_diff, m - s);
    }
    cout << max_diff << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
