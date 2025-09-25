/*C. MEX rose
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of length 𝑛
 and a number 𝑘
, where 0≤𝑘≤𝑛
.

In one operation, you can choose any index 𝑖
 (1≤𝑖≤𝑛
) and set 𝑎𝑖
 to any integer value 𝑥
 from the range [0,𝑛]
.

Find the minimum number of such operations required to satisfy the condition:
MEX(𝑎) ∗ =𝑘

∗
The minimum excluded (MEX) of a set of numbers 𝑎1,𝑎2,…,𝑎𝑛
 is the smallest non-negative integer 𝑥
 that does not appear among the 𝑎𝑖
.

Input
Each test consists of several sets of input data.

The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of sets of input data. The description of the sets of input data
follows.

The first line of each set of input data contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105,0≤𝑘≤𝑛
) — the length of the array 𝑎
 and the required MEX(𝑎)
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛
) — the elements of the array 𝑎
.

It is guaranteed that the sum of the values of 𝑛
 across all sets of input data does not exceed 2⋅105
.

Output
For each set of input data, output one integer — the minimum number of
operations required to satisfy the condition MEX(𝑎)=𝑘
.

Example
InputCopy
5
1 0
0
3 1
0 2 3
5 5
0 1 2 3 4
6 2
0 3 4 2 6 2
7 4
0 1 5 4 4 7 3
OutputCopy
1
0
0
2
2
Note
In the first set of input data, the array 𝑎=[0]
, so MEX=1
.By removing zero (replacing it with any 𝑥∈[1,𝑛]
), we get MEX=0
.Thus, exactly one operation is required.

In the third set of input data, the array contains all the numbers 0,1,2,3,4
, so MEX(𝑎)=5
 from the start.

Since this matches the required 𝑘
, no changes are needed and the minimum number of operations is 0
.
*/

// we have to set whole array from 0 to k-1, except k
// We need to ensure k is not in the array (if it exists, we must change it)
// Any number > k can stay as is (they don't affect MEX)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> count(n + 1, 0); // count[i] = how many times i appears

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] <= n) {
        count[a[i]]++;
      }
    }

    int operations = 0;

    // For MEX = k, we need 0, 1, 2, ..., k-1 to exist
    // and k should not exist

    // Check if we have all numbers from 0 to k-1
    for (int i = 0; i < k; i++) {
      if (count[i] == 0) {
        operations++; // Need to add this number
      }
    }

    // If k exists in array, we need to remove it
    if (k <= n && count[k] > 0) {
      operations++; // Need to change k to something else
    }

    cout << operations;
  }

  return 0;
}
// not solved
