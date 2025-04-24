/*D. Flower Boy
time limit per test2 seconds
memory limit per test256 megabytes
Flower boy has a garden of 𝑛
 flowers that can be represented as an integer sequence 𝑎1,𝑎2,…,𝑎𝑛
, where 𝑎𝑖
 is the beauty of the 𝑖
-th flower from the left.

Igor wants to collect exactly 𝑚
 flowers. To do so, he will walk the garden from left to right and choose
whether to collect the flower at his current position. The 𝑖 -th flower among
ones he collects must have a beauty of at least 𝑏𝑖
.

Igor noticed that it might be impossible to collect 𝑚
 flowers that satisfy his beauty requirements, so before he starts collecting
flowers, he can pick any integer 𝑘 and use his magic wand to grow a new flower
with beauty 𝑘 and place it anywhere in the garden (between two flowers, before
the first flower, or after the last flower). Because his magic abilities are
limited, he may do this at most once.

Output the minimum integer 𝑘
 Igor must pick when he performs the aforementioned operation to ensure that he
can collect 𝑚 flowers. If he can collect 𝑚 flowers without using the operation,
output 0 . If it is impossible to collect 𝑚 flowers despite using the operation,
output −1
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases.

The first line of each test case contains exactly two integers 𝑛
 and 𝑚
 (1≤𝑚≤𝑛≤2⋅105)
 — the number of flowers in the garden and the number of flowers Igor wants to
collect, respectively.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,...,𝑎𝑛
 (1≤𝑎𝑖≤109)
 — where 𝑎𝑖
 is the beauty of the 𝑖
-th flower from the left in the garden.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,...,𝑏𝑚
 (1≤𝑏𝑖≤109)
 — where 𝑏𝑖
 is the minimum beauty the 𝑖
-th flower must have that Igor will collect.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, on a separate line, output the minimum integer 𝑘
 Igor must pick when he performs the aforementioned operation to ensure that he
can collect 𝑚 flowers. If he can collect 𝑚 flowers without using the operation,
output 0 . If it is impossible to collect 𝑚 flowers despite using the operation,
output −1
.

Example
InputCopy
7
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6
6 3
1 2 6 8 2 1
5 4 3
5 3
4 3 5 4 3
7 4 5
6 3
8 4 2 1 2 5
6 1 4
5 5
1 2 3 4 5
5 4 3 2 1
6 3
1 2 3 4 5 6
9 8 7
5 5
7 7 6 7 7
7 7 7 7 7
OutputCopy
6
3
7
0
-1
-1
7
Note
In the first test case, suppose Igor grows a flower of beauty 6
 and places it between the third and the fourth flowers. Then, the garden will
look like the following: [3,5,2,6,3,3,5,8,1,2] . Then, he can select the second,
fourth, sixth, seventh, and eighth flowers with beauties [5,6,3,5,8]
.

In the third test case, he can grow a flower of beauty 7
 and place it before the first flower. The garden will look like the following:
[7,4,3,5,4,3] . Now, he can choose the first, second, and fourth flowers.

In the fourth test case, Igor does not need to use the operation, so the answer
is 0
.

In the sixth test case, no matter how Igor performs the operation, he cannot
collect 3 flowers such that the 𝑖 -th flower he collects has a beauty of at
least 𝑏𝑖 , therefore the answer is −1
.
*/

/*#include <iostream>
#include <vector>
using namespace std;
bool canMatch(const vector<int> &a, const vector<int> &b) {
  int i = 0;
  for (int x : a) {
    if (i < b.size() && x >= b[i])
      i++;
  }
  return i == b.size();
}

/*bool canMatchWithInsertion(const vector<int> &a, const vector<int> &b, int k)
{ for (int i = 0; i <= a.size(); ++i) { vector<int> a_new = a;
    a_new.insert(a_new.begin() + i, k);
    if (canMatch(a_new, b))
      return true;
  }
  return false;
}*/
/*
bool canMatchWithInsertion(const vector<int> &a, const vector<int> &b, int k) {
  int n = a.size(), m = b.size();
  for (int pos = 0; pos <= n; ++pos) {
    int i = 0, j = 0;
    while (j < m && i <= n) {
      int current = (i == pos) ? k : a[i < pos ? i : i - 1];
      if (current >= b[j])
        j++;
      i++;
    }
    if (j == m)
      return true;
  }
  return false;
}

int findMinK(vector<int> &a, vector<int> &b) {
  if (canMatch(a, b))
    return 0;

  int lo = 0, hi = 1e9, ans = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (canMatchWithInsertion(a, b, mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i]; // beauty of n flowers
    for (int i = 0; i < m; i++)
      cin >> b[i]; // desired minimum beauty levels for m flowers you must
                   // collect in order.

    // Insert one flower with beauty k at any position in a.

    // goal:Find the minimum such k that allows you to collect the sequence
    // b[1..m] (in order) while walking from left to right in the modified a.

    int ans = findMinK(a, b);
    cout << ans << endl;
  }
  return 0;
}*/
/* Precompute prefix/suffix matches to avoid redundant checks:

Prefix Array (left[]): left[i] = max elements of b matched by the first i
elements of a.

Suffix Array (right[]): right[i] = max elements of b matched by the last i
elements of a.

*/
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool canMatch(const vector<int> &a, const vector<int> &b) {
  int i = 0;
  for (int x : a) {
    if (i < b.size() && x >= b[i])
      i++;
  }
  return i == b.size();
}

int findMinK(const vector<int> &a, const vector<int> &b) {
  int n = a.size(), m = b.size();
  if (m == 0)
    return 0;
  if (canMatch(a, b))
    return 0;

  vector<int> left(n + 1, 0), right(n + 1, 0);

  // Compute prefix matches (left array)
  for (int i = 0; i < n; ++i) {
    left[i + 1] = left[i];
    if (left[i + 1] < m && a[i] >= b[left[i + 1]])
      left[i + 1]++;
  }

  // Compute suffix matches (right array)
  for (int i = n - 1; i >= 0; --i) {
    right[n - i] = right[n - i - 1];
    int idx = m - 1 - right[n - i];
    if (idx >= 0 && a[i] >= b[idx])
      right[n - i]++;
  }

  int min_k = INT_MAX;
  for (int pos = 0; pos <= n; ++pos) {
    int l = left[pos];
    int r = (pos == n) ? right[0] : right[n - pos];
    if (l + r >= m) {
      // No need to insert if already covered
      continue;
    }
    if (l + r >= m - 1) {
      if (l < m) {
        int required = b[l];
        min_k = min(min_k, required);
      }
    }
  }

  return (min_k != INT_MAX) ? min_k : -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    cout << findMinK(a, b) << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/contest/2106/submission/317067184
