/* D. Skibidus and Sigma
time limit per test2 seconds
memory limit per test256 megabytes
Let's denote the score of an array 𝑏
 with 𝑘
 elements as ∑𝑘𝑖=1(∑𝑖𝑗=1𝑏𝑗)
. In other words, let 𝑆𝑖
 denote the sum of the first 𝑖
 elements of 𝑏
. Then, the score can be denoted as 𝑆1+𝑆2+…+𝑆𝑘
.

Skibidus is given 𝑛
 arrays 𝑎1,𝑎2,…,𝑎𝑛
, each of which contains 𝑚
 elements. Being the sigma that he is, he would like to concatenate them in any
order to form a single array containing 𝑛⋅𝑚 elements. Please find the maximum
possible score Skibidus can achieve with his concatenated array!

Formally, among all possible permutations∗
 𝑝
 of length 𝑛
, output the maximum score of 𝑎𝑝1+𝑎𝑝2+⋯+𝑎𝑝𝑛
, where +
 represents concatenation†
.

∗
A permutation of length 𝑛
 contains all integers from 1
 to 𝑛
 exactly once.

†
The concatenation of two arrays 𝑐
 and 𝑑
 with lengths 𝑒
 and 𝑓
 respectively (i.e. 𝑐+𝑑
) is 𝑐1,𝑐2,…,𝑐𝑒,𝑑1,𝑑2,…𝑑𝑓
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛⋅𝑚≤2⋅105
) — the number of arrays and the length of each array.

The 𝑖
'th of the next 𝑛
 lines contains 𝑚
 integers 𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚
 (1≤𝑎𝑖,𝑗≤106
) — the elements of the 𝑖
'th array.

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum score among all possible permutations 𝑝
 on a new line.

Example
InputCopy
3
2 2
4 4
6 1
3 4
2 2 2 2
3 2 1 2
4 1 2 1
2 3
3 4 5
1 1 9
OutputCopy
41
162
72
Note
For the first test case, there are two possibilities for 𝑝
:

𝑝=[1,2]
. Then, 𝑎𝑝1+𝑎𝑝2=[4,4,6,1]
. Its score is 4+(4+4)+(4+4+6)+(4+4+6+1)=41
.
𝑝=[2,1]
. Then, 𝑎𝑝1+𝑎𝑝2=[6,1,4,4]
. Its score is 6+(6+1)+(6+1+4)+(6+1+4+4)=39
.
The maximum possible score is 41
.

In the second test case, one optimal arrangement of the final concatenated array
is [4,1,2,1,2,2,2,2,3,2,1,2] . We can calculate that the score is 162
.


*/
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;
long long computeScore(const vector<int> &arr) {
  long long prefixSum = 0, totalSum = 0;
  for (int num : arr) {
    prefixSum += num;
    totalSum += prefixSum;
  }
  return totalSum;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m; // n-no of array, m - length of each array
    std::cin >> n >> m;
    vector<vector<int>> arrays(n);
    for (int i = 0; i < n; i++) {
      arrays[i].resize(m);

      for (int j = 0; j < m; j++) {
        std::cin >> arrays[i][j];
      }
      sort(arrays[i].begin(),
           arrays[i].end()); // Sort each subarray in ascending order
    }
    // just output the solution here itself
    // solution->maximum score among all possible permutations 𝑝

    sort(arrays.begin(), arrays.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return computeScore(a) > computeScore(b);
         });

    // Compute final score
    long long prefixSum = 0, totalSum = 0;
    for (const auto &arr : arrays) {
      for (int num : arr) {
        prefixSum += num;
        totalSum += prefixSum;
      }
    }

    cout << totalSum << endl;
  }
  return 0;
}
