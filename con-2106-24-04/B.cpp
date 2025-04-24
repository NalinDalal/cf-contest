/*B. St. Chroma
time limit per test2 seconds
memory limit per test256 megabytes
Given a permutation∗
 𝑝
 of length 𝑛
 that contains every integer from 0
 to 𝑛−1
 and a strip of 𝑛
 cells, St. Chroma will paint the 𝑖
-th cell of the strip in the color MEX(𝑝1,𝑝2,...,𝑝𝑖)
†
.

For example, suppose 𝑝=[1,0,3,2]
. Then, St. Chroma will paint the cells of the strip in the following way:
[0,2,2,4]
.

You have been given two integers 𝑛
 and 𝑥
. Because St. Chroma loves color 𝑥
, construct a permutation 𝑝
 such that the number of cells in the strip that are painted color 𝑥
 is maximized.

∗
A permutation of length 𝑛
 is a sequence of 𝑛
 elements that contains every integer from 0
 to 𝑛−1
 exactly once. For example, [0,3,1,2]
 is a permutation, but [1,2,0,1]
 isn't since 1
 appears twice, and [1,3,2]
 isn't since 0
 does not appear at all.

†
The MEX
 of a sequence is defined as the first non-negative integer that does not appear
in it. For example, MEX(1,3,0,2)=4 , and MEX(3,1,2)=0
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤4000
) — the number of test cases.

The only line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105
, 0≤𝑥≤𝑛
) — the number of cells and the color you want to maximize.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
Output a permutation 𝑝
 of length 𝑛
 such that the number of cells in the strip that are painted color 𝑥
 is maximized. If there exist multiple such permutations, output any of them.

Example
InputCopy
7
4 2
4 0
5 0
1 1
3 3
1 0
4 3
OutputCopy
1 0 3 2
2 3 1 0
3 2 4 1 0
0
0 2 1
0
1 2 0 3
Note
The first example is explained in the statement. It can be shown that 2
 is the maximum amount of cells that can be painted in color 2
. Note that another correct answer would be the permutation [0,1,3,2]
.

In the second example, the permutation gives the coloring [0,0,0,4]
, so 3
 cells are painted in color 0
, which can be shown to be maximum.
*/

#include <iostream>
#include <vector>

using namespace std; /* given:
 n-size of permutation
 x-color
 painting as: MEX(p₁, p₂, ..., pᵢ)
 MEX: smallest non-negative number not in the prefix.

to do:
- Construct a permutation p of [0, 1, ..., n-1]

- Such that the number of times MEX(...) == x is maximized.


 */
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;

    // output will contain n integers
    // Output a permutation p of length n such that the number of cells in the
    // strip that are painted color x is maximized
    vector<int> p(n);

    // Add numbers greater than x first (x+1 to n-1)
    for (int i = x + 1; i < n; i++) {
      p.push_back(i);
    }

    // Then add 0 to x
    for (int i = 0; i <= x; i++) {
      p.push_back(i);
    }

    // Output the permutation
    for (int val : p) {
      cout << val << " ";
    }
    cout << "\n";
  }

  return 0;
}
