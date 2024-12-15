/* D. Harder Problem
time limit per test2 seconds
memory limit per test256 megabytes
Given a sequence of positive integers, a positive integer is called a mode of
the sequence if it occurs the maximum number of times that any positive integer
occurs. For example, the mode of [2,2,3] is 2 . Any of 9 , 8 , or 7 can be
considered to be a mode of the sequence [9,9,8,8,7,7]
.

You gave UFO an array 𝑎
 of length 𝑛
. To thank you, UFO decides to construct another array 𝑏
 of length 𝑛
 such that 𝑎𝑖
 is a mode of the sequence [𝑏1,𝑏2,…,𝑏𝑖]
 for all 1≤𝑖≤𝑛
.

However, UFO doesn't know how to construct array 𝑏
, so you must help her. Note that 1≤𝑏𝑖≤𝑛
 must hold for your array for all 1≤𝑖≤𝑛
.

Input
The first line contains 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of 𝑎
.

The following line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 numbers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛
) on a new line. It can be shown that 𝑏
 can always be constructed. If there are multiple possible arrays, you may print
any.

Example
InputCopy
4
2
1 2
4
1 1 1 2
8
4 5 5 5 1 1 2 1
10
1 1 2 2 1 1 3 3 1 1
OutputCopy
1 2
1 1 2 2
4 5 5 1 1 2 2 3
1 8 2 2 1 3 3 9 1 1
Note
Let's verify the correctness for our sample output in test case 2
.

At 𝑖=1
, 1
 is the only possible mode of [1]
.
At 𝑖=2
, 1
 is the only possible mode of [1,1]
.
At 𝑖=3
, 1
 is the only possible mode of [1,1,2]
.
At 𝑖=4
, 1
 or 2
 are both modes of [1,1,2,2]
. Since 𝑎𝑖=2
, this array is valid.

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> b(n);
    unordered_map<int, int> freq; // Frequency map to count occurrences
    int current_mode_freq = 0;    // Frequency of the current mode

    for (int i = 0; i < n; i++) {
      freq[a[i]]++; // Increment frequency of a[i]
      b[i] = a[i];  // Assign a[i] to b[i]
      current_mode_freq = max(current_mode_freq, freq[a[i]]);
    }

    // Output the constructed array b
    for (int i = 0; i < n; i++)
      cout << b[i] << " ";
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
