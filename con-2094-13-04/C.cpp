/* C. Brr Brrr Patapim
time limit per test2 seconds
memory limit per test256 megabytes
Brr Brrr Patapim is trying to learn of Tiramisù's secret passcode, which is a
permutation∗ of 2⋅𝑛 elements. To help Patapim guess, Tiramisù gave him an 𝑛×𝑛
 grid 𝐺
, in which 𝐺𝑖,𝑗
 (or the element in the 𝑖
-th row and 𝑗
-th column of the grid) contains 𝑝𝑖+𝑗
, or the (𝑖+𝑗)
-th element in the permutation.

Given this grid, please help Patapim crack the forgotten code. It is guaranteed
that the permutation exists, and it can be shown that the permutation can be
determined uniquely.

∗
A permutation of 𝑚
 integers is a sequence of 𝑚
 integers which contains each of 1,2,…,𝑚
 exactly once. For example, [1,3,2]
 and [2,1]
 are permutations, while [1,2,4]
 and [1,3,2,3]
 are not.

Input
The first line contains an integer 𝑡
 — the number of test cases (1≤𝑡≤200
).

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤800
).

Each of the following 𝑛
 lines contains 𝑛
 integers, giving the grid 𝐺
. The first of these lines contains 𝐺1,1,𝐺1,2,…,𝐺1,𝑛
; the second of these lines contains 𝐺2,1,𝐺2,2,…,𝐺2,𝑛
, and so on. (1≤𝐺𝑖,𝑗≤2⋅𝑛
).

It is guaranteed that the grid encodes a valid permutation, and the sum of 𝑛
 over all test cases does not exceed 800
.

Output
For each test case, please output 2𝑛
 numbers on a new line: 𝑝1,𝑝2,…,𝑝2𝑛
.

Example
InputCopy
3
3
1 6 2
6 2 4
2 4 3
1
1
2
2 3
3 4
OutputCopy
5 1 6 2 4 3
2 1
1 2 3 4


*/
/* noticed one thing like if conf is:
1 6 2
6 2 4
2 4 3

then ans is 5 1 6 2 4 3
which is like the no not present then row wise traversal, print the element not
present, else mpve ahead
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    unordered_set<int> present;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
        present.insert(v[i][j]);
      }
    }

    // Find the missing number from 1 to 2n (this will be p[1])
    int missing = -1;
    for (int i = 1; i <= 2 * n; i++) {
      if (!present.count(i)) {
        missing = i;
        break;
      }
    }

    cout << missing << " ";

    // Now, traverse the matrix row-wise and output unique elements
    unordered_set<int> printed;
    printed.insert(missing); // Don't repeat the missing one
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int val = v[i][j];
        if (!printed.count(val)) {
          cout << val << " ";
          printed.insert(val);
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/contest/2094/submission/315402546
