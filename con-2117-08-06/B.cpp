/*B. Shrink
time limit per test2 seconds
memory limit per test256 megabytes
A shrink operation on an array 𝑎
 of size 𝑚
 is defined as follows:

Choose an index 𝑖
 (2≤𝑖≤𝑚−1
) such that 𝑎𝑖>𝑎𝑖−1
 and 𝑎𝑖>𝑎𝑖+1
.
Remove 𝑎𝑖
 from the array.
Define the score of a permutation∗
 𝑝
 as the maximum number of times that you can perform the shrink operation on 𝑝
.

Yousef has given you a single integer 𝑛
. Construct a permutation 𝑝
 of length 𝑛
 with the maximum possible score. If there are multiple answers, you can output
any of them.

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

Each test case contains an integer 𝑛
 (3≤𝑛≤2⋅105
) — the size of the permutation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output any permutation 𝑝1,𝑝2,…,𝑝𝑛
 that maximizes the number of shrink operations.

Example
InputCopy
2
3
6
OutputCopy
1 3 2
2 3 6 4 5 1
Note
In the first test case:

We choose 𝑝=[1,3,2]
.
Choose index 2
, and remove 𝑝2
 from the array. The array becomes 𝑝=[1,2]
.
It can be shown that the maximum number of operations we can perform is 1
. Another valid answer is 𝑝=[2,3,1]
.

In the second test case:

We choose 𝑝=[2,3,6,4,5,1]
.
Choose index 5
, and remove 𝑝5
 from the array. The array becomes 𝑝=[2,3,6,4,1]
.
Choose index 3
, and remove 𝑝3
 from the array. The array becomes 𝑝=[2,3,4,1]
.
Choose index 3
, and remove 𝑝3
 from the array. The array becomes 𝑝=[2,3,1]
.
Choose index 2
, and remove 𝑝2
 from the array. The array becomes 𝑝=[2,1]
.
The maximum number of operations we can perform is 4
. Any permutation with a score of 4
 is valid.



*/

// maximise local peak i.e. p[i]>p[i-1],p[i+1]
// want to maximize the number of times this operation can be applied.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> perm(n);
    int mid = (n + 1) / 2;
    vector<int> order;
    order.push_back(mid);
    int offset = 1;
    bool right = true;
    while ((int)order.size() < n) {
      if (right) {
        int pos = mid + offset;
        if (pos <= n)
          order.push_back(pos);
        right = false;
      } else {
        int pos = mid - offset;
        if (pos >= 1)
          order.push_back(pos);
        right = true;
        offset++;
      }
    }
    int val = n;
    for (int i = 0; i < n; ++i) {
      perm[order[i] - 1] = val--;
    }
    for (int i = 0; i < n; ++i) {
      cout << perm[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/contest/2117/submission/323483293
