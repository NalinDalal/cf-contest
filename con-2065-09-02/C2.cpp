/* https://codeforces.com/contest/2065/problem/C2
C2. Skibidus and Fanum Tax (hard version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the hard version of the problem. In this version, 𝑚≤2⋅105.

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

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛≤2⋅105,
1≤𝑚≤2⋅105).

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
1 3
5
9 1 1000000000
3 2
1 4 3
3 4
4 3
2 4 6 5
6 1 8
5 2
6 4 5 4 5
4 1000
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

In the third test case, we can set 𝑎2:=𝑏1−𝑎2=6−4=2 and 𝑎3:=𝑏3−𝑎3=8−6=2. The
sequence [2,2,2,5] is in nondecreasing order.

In the last case, we can apply operations on each index. The sequence becomes
[−1,0,1], which is in nondecreasing order.

*/

#include <iostream>
#include <vector>
using namespace std;

bool isTrue(const vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < a[i + 1])
      return true;
  }

  return false;
}
int opr(vector<int> a, vector<int> b) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      a[i] = b[j] - a[i];
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    // input a[n] and b[m] array
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];

    // apply only once following operation
    // 1<=j<=m
    // set a[i]=b[j]-a[i]
    //

    if (isTrue(a)) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
    // if it is possible to sort a in ascending return true
    // else return false
    // if(bool)cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
  }
  return 0;
}
