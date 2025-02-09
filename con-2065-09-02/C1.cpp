/* https://codeforces.com/contest/2065/problem/C1
C1. Skibidus and Fanum Tax (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the easy version of the problem. In this version, 𝑚=1.

Skibidus has obtained two arrays 𝑎 and 𝑏, containing 𝑛 and 𝑚 elements
respectively. For each integer 𝑖 from 1 to 𝑛, he is allowed to perform the
operation at most once:

Choose an integer 𝑗 such that 1≤𝑗≤𝑚. Set 𝑎𝑖:=𝑏𝑗−𝑎𝑖. Note that 𝑎𝑖 may become
non-positive as a result of this operation. Skibidus needs your help determining
whether he can sort 𝑎 in non-decreasing order∗ by performing the above operation
some number of times.

∗𝑎 is sorted in non-decreasing order if 𝑎1≤𝑎2≤…≤𝑎𝑛.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛≤2⋅105, 𝐦 =
1).

The following line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).

The following line of each test case contains 𝑚 integers 𝑏1,𝑏2,…,𝑏𝑚 (1≤𝑏𝑖≤109).

It is guaranteed that the sum of 𝑛 and the sum of 𝑚 over all test cases does not
exceed 2⋅105.

Output
For each test case, if it is possible to sort 𝑎 in non-decreasing order, print
"YES" on a new line. Otherwise, print "NO" on a new line.

You can output the answer in any case. For example, the strings "yEs", "yes",
and "Yes" will also be recognized as positive responses.

Example
InputCopy
5
1 1
5
9
3 1
1 4 3
3
4 1
1 4 2 5
6
4 1
5 4 10 5
4
3 1
9 8 7
8
OutputCopy
YES
NO
YES
NO
YES
Note
In the first test case, [5] is already sorted.

In the second test case, it can be shown that it is impossible.

In the third test case, we can set 𝑎3:=𝑏1−𝑎3=6−2=4. The sequence [1,4,4,5] is in
nondecreasing order. In the last case, we can apply operations on each index.
The sequence becomes [−1,0,1], which is in nondecreasing order.

*/

#include <iostream>
#include <vector>
using std::cin, std::cout, std::vector, std::endl;
bool canSort(vector<int> a, vector<int> b) {
  // choose j such that 1<=j<=m
  // set a[i]=b[j]-a[i]
  // if a becomes in ascending order return true
  int n = a.size(), m = b.size();

  // Try all values in b[j] (1-based index)
  for (int j = 0; j < m; j++) {
    vector<int> temp = a; // Copy of a to try modifications

    // Modify each element: a[i] = b[j] - a[i]
    for (int i = 0; i < n; i++) {
      temp[i] = b[j] - temp[i];
    }

    // Check if temp is sorted in ascending order
    if (is_sorted(temp.begin(), temp.end())) {
      return true; // Found a valid transformation
    }
  }

  return false; // No valid transformation found
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++)
      cin >> b[i];

    if (canSort(a, b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
