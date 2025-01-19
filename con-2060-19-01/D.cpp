/* https://codeforces.com/contest/2060/problem/D

D. Subtract Min Sort
time limit per test2 seconds
memory limit per test256 megabytes

You are given a sequence 𝑎 consisting of 𝑛 positive integers.

You can perform the following operation any number of times.

Select an index 𝑖 (1≤𝑖<𝑛), and subtract min(𝑎𝑖,𝑎𝑖+1) from both 𝑎𝑖 and 𝑎𝑖+1.
Determine if it is possible to make the sequence non-decreasing by using the
operation any number of times.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (2≤𝑛≤2⋅105).

The second line of each test case contains 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
If it is possible to make the sequence non-decreasing, print "YES" on a new
line. Otherwise, print "NO" on a new line.

You can output the answer in any case. For example, the strings "yEs", "yes",
and "Yes" will also be recognized as positive responses.

Example
InputCopy
5
5
1 2 3 4 5
4
4 3 2 1
4
4 5 2 3
8
4 5 4 5 4 5 4 5
9
9 9 8 2 4 4 3 5 3
OutputCopy
YES
NO
YES
YES
NO
Note
In the first test case, the array is already sorted.

In the second test case, we can show that it is impossible.

In the third test case, after performing an operation on 𝑖=1, the array becomes
[0,1,2,3], which is now in nondecreasing order.



*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(vector<int> a, int n) {
  // for index i a[i]=a[i]-min(a[i],a[i+1])
  // a[i+1]=a[i+1]-min(a[i],a[i+1])
  // if vector is non-decreasing then return YES
  // else return NO
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      a[i] = a[i] - min(a[i], a[i + 1]);
    }
  }
  // Check if the array is non-decreasing
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return "NO";
    }
  }

  return "YES";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << solve(v, n) << endl;
  }
  return 0;
}

// later
