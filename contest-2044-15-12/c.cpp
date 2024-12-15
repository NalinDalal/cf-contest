/* C. Hard Problem
time limit per test1 second
memory limit per test256 megabytes
Ball is the teacher in Paperfold University. The seats of his classroom are
arranged in 2 rows with 𝑚 seats each.

Ball is teaching 𝑎+𝑏+𝑐
 monkeys, and he wants to assign as many monkeys to a seat as possible. Ball
knows that 𝑎 of them only want to sit in row 1 , 𝑏 of them only want to sit in
row 2 , and 𝑐 of them have no preference. Only one monkey may sit in each seat,
and each monkey's preference must be followed if it is seated.

What is the maximum number of monkeys that Ball can seat?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case contains four integers 𝑚
, 𝑎
, 𝑏
, and 𝑐
 (1≤𝑚,𝑎,𝑏,𝑐≤108
).

Output
For each test case, output the maximum number of monkeys you can seat.

Example
InputCopy
5
10 5 5 10
3 6 1 1
15 14 12 4
1 1 1 1
420 6 9 69
OutputCopy
20
5
30
2
84
Note
In the second test case, 6
 monkeys want to sit in the front row, but only 3
 seats are available. The monkeys that have no preference and the monkeys who
prefer sitting in the second row can sit in the second row together. Thus, the
answer is 3+2=5
.


*/

/*2 rows m seats each
 * a + b + c monkeys a in 1st row b in 2nd row c in 1, 2,3

max number of monkeys to be seated
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >› c;
    int ans = 0;
    if (a > 0) {
      ans += a;
    }
    if (b > 0) {
      ans += b;
    }
    if (c > 0) {
      ans += c;
    }
    cout << ans << endl;
  }
  return 0;
}
