/*B. Unconventional Pairs
time limit per test2 seconds
memory limit per test256 megabytes
A popular reality show Unconventional Pairs has been launched in the city.
According to the rules of the show, participants are paired in an unusual way:
with an even number of people, all participants must be in pairs.

Petya has an array of 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
. It is known that 𝑛
 is even. Petya must divide the participants (numbers) into exactly 𝑛2
 pairs (𝑎𝑝1,𝑎𝑞1),(𝑎𝑝2,𝑎𝑞2),…(𝑎𝑝𝑛2,𝑎𝑞𝑛2)
. Each index can be included in no more than one pair.

For a pair (𝑥,𝑦)
, its difference is defined as |𝑥−𝑦|
. Petya wants to form unconventional pairs such that the maximum difference
among all pairs is minimized.

Determine the minimum possible value of this maximum difference.

Input
Each test consists of several test cases.

The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one even number 𝑛
 (2≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−109≤𝑎𝑖≤109)
 — the elements of the array 𝑎
.

It is guaranteed that the sum of the values of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single number — the minimum possible maximum
difference between the elements in pairs.

Example
InputCopy
5
2
1 2
4
10 1 2 9
6
3 8 9 3 3 2
8
5 5 5 5 5 5 5 5
4
-5 -1 2 6
OutputCopy
1
1
1
0
4
Note
In the first test case, the array is: [1,2]
. The only possible (and therefore optimal) pair is (1,2)
, its difference is |1−2|=1
, the answer is 1
.

In the second test case, the array is: [10,1,2,9]
. We can choose pairs — (1,2)
 and (9,10)
: both differences are equal to 1
, therefore, the maximum difference is 1
.

In the third test case, the array is: [3,8,9,3,3,2]
. We can choose pairs: (2,3)
, (3,3)
, (8,9)
. The differences are: 1,0,1
 — the largest is 1
.
*/

/*given a vector, find n/2 pair, then pair up the elements
 * (x,y)-> abs(x-y)
 * find min possible max diff
from 1 to n/2 find min(a[i+n/2]-a[i])

Sort array a.

Pair a[i] with a[i + n/2] for i = 0 to n/2-1
 * The answer is the maximum difference among these pairs
 *
 * Why this works: After sorting, pairing first half with second half
 * ensures we don't create unnecessarily large gaps

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    // Pair adjacent elements and find maximum difference
    for (int i = 0; i < n; i += 2) {
      ans = max(ans, a[i + 1] - a[i]);
    }

    cout << ans << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/contest/2149/submission/340467276
