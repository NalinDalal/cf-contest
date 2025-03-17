/*A. To Zero
time limit per test2 seconds
memory limit per test512 megabytes
You are given two integers 𝑛
 and 𝑘
; 𝑘
 is an odd number not less than 3
. Your task is to turn 𝑛
 into 0
.

To do this, you can perform the following operation any number of times: choose
a number 𝑥 from 1 to 𝑘 and subtract it from 𝑛 . However, if the current value of
𝑛 is even (divisible by 2
), then 𝑥
 must also be even, and if the current value of 𝑛
 is odd (not divisible by 2
), then 𝑥
 must be odd.

In different operations, you can choose the same values of 𝑥
, but you don't have to. So, there are no limitations on using the same value of
𝑥
.

Calculate the minimum number of operations required to turn 𝑛
 into 0
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤10000
) — the number of test cases.

Each test case consists of one line containing two integers 𝑛
 and 𝑘
 (3≤𝑘≤𝑛≤109
, 𝑘
 is odd).

Output
For each test case, output one integer — the minimum number of operations
required to turn 𝑛 into 0
.

Example
InputCopy
8
39 7
9 3
6 3
999967802 3
5 5
6 5
999999999 3
1000000000 3
OutputCopy
7
4
3
499983901
1
2
499999999
500000000
Note
In the first example from the statement, you can first subtract 5
 from 39
 to get 34
. Then subtract 6
 five times to get 4
. Finally, subtract 4
 to get 0
.

In the second example, you can subtract 3
 once, and then subtract 2
 three times.

In the third example, you can subtract 2
 three times.


*/

// turn n to 0, k is always greater than 3, odd no
// choose any num x from 1 to k
// subtract it from n, but if n is even then x must also be even
// and if n is odd then x must be odd
// return minOpr to turn n into 0
#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;

    int operations = 0;

    while (n > 0) {
      if (n % 2 == 1) {
        // If n is odd, subtract the largest odd number (k)
        n -= k;
      } else {
        // If n is even, subtract the largest even number <= k
        n -= (k - 1);
      }
      operations++;
    }

    cout << operations << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
