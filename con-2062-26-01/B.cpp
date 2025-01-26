/* https://codeforces.com/contest/2062/problem/B
B. Clockwork
time limit per test1.5 seconds
memory limit per test512 megabytes
You have a sequence of 𝑛
 time clocks arranged in a line, where the initial time on the 𝑖
-th clock is 𝑎𝑖
. In each second, the following happens in order:

Each clock's time decreases by 1
. If any clock's time reaches 0
, you lose immediately.
You can choose to move to an adjacent clock or stay at the clock you are
currently on. You can reset the time of the clock you are on back to its initial
value 𝑎𝑖
.
Note that the above events happen in order. If the time of a clock reaches 0
 in a certain second, even if you can move to this clock and reset its time
during that second, you will still lose.

You can start from any clock. Determine if it is possible to continue this
process indefinitely without losing.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

For each test case, the first line contains a single integer 𝑛
 (2≤𝑛≤5⋅105
) — the number of time clocks.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the initial times set on the clocks.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5⋅105
.

Output
For each test case, print "YES" (without quotes) if it is possible to continue
this process indefinitely, or "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and
"Yes" will be recognized as a positive response).

Example
InputCopy
5
2
4 10
2
2 2
3
4 10 5
3
5 3 5
5
12 13 25 17 30
OutputCopy
YES
NO
NO
YES
YES
Note
In the first test case, you can move back and forth between the two clocks,
resetting them repeatedly.

In the third test case, assuming that you start from clock 1
 and follow the strategy below:

Initially, 𝑎=[4,10,5]
.

𝑎
 becomes [3,9,4]
. You move to clock 2
 and reset its time, resulting in 𝑎=[3,10,4]
.
𝑎
 becomes [2,9,3]
. You move to clock 3
 and reset its time, resulting in 𝑎=[2,9,5]
.
𝑎
 becomes [1,8,4]
. You move to clock 2
 and reset its time, resulting in 𝑎=[1,10,4]
.
𝑎
 becomes [0,9,3]
. You move to clock 1, but you lose because 𝑎1 reaches 0.
It can be proven that no other strategy allows you to continue this process
indefinitely.
*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // yes if process runs indefinitely
    // no if not i.e. any of item reaches 0
  }
}
