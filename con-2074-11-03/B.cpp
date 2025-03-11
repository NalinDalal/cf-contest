/*B. The Third Side
time limit per test2 seconds
memory limit per test256 megabytes
The pink soldiers have given you a sequence 𝑎
 consisting of 𝑛
 positive integers.

You must repeatedly perform the following operation until there is only 1
 element left.

Choose two distinct indices 𝑖
 and 𝑗
.
Then, choose a positive integer value 𝑥
 such that there exists a non-degenerate triangle∗
 with side lengths 𝑎𝑖
, 𝑎𝑗
, and 𝑥
.
Finally, remove two elements 𝑎𝑖
 and 𝑎𝑗
, and append 𝑥
 to the end of 𝑎
.
Please find the maximum possible value of the only last element in the sequence
𝑎
.

∗
A triangle with side lengths 𝑎
, 𝑏
, 𝑐
 is non-degenerate when 𝑎+𝑏>𝑐
, 𝑎+𝑐>𝑏
, 𝑏+𝑐>𝑎
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1000
) — the elements of the sequence 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum possible value of the only last element
on a separate line.

Example
InputCopy
4
1
10
3
998 244 353
5
1 2 3 4 5
9
9 9 8 2 4 4 3 5 3
OutputCopy
10
1593
11
39
Note
On the first test case, there is already only one element. The value of the only
last element is 10
.

On the second test case, 𝑎
 is initially [998,244,353]
. The following series of operations is valid:

Erase 𝑎2=244
 and 𝑎3=353
, and append 596
 to the end of 𝑎
. 𝑎
 is now [998,596]
.
Erase 𝑎1=998
 and 𝑎2=596
, and append 1593
 to the end of 𝑎
. 𝑎
 is now [1593]
.
It can be shown that the only last element cannot be greater than 1593
. Therefore, the answer is 1593
.


*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue<int> pq;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }

  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    pq.push(a + b - 1);
  }

  cout << pq.top() << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
// sub: https://codeforces.com/contest/2074/submission/310092671
