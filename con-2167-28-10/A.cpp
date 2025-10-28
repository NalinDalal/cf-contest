/*A. Square?
time limit per test1 second
memory limit per test256 megabytes
You are given 4
 sticks of lengths 𝑎
, 𝑏
, 𝑐
, and 𝑑
. You can not break or bend them.

Determine whether it is possible to form a square∗
 using the given sticks.

∗
A square is defined as a polygon consisting of 4
 vertices, of which all sides have equal length and all inner angles are equal.
No two edges of the polygon may intersect each other.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains four integers 𝑎
, 𝑏
, 𝑐
, and 𝑑
 (1≤𝑎,𝑏,𝑐,𝑑≤10
) — the lengths of the sticks.

Output
For each test case, print "YES" if it is possible to form a square using the
given sticks, and "NO" otherwise.

You may print each letter in any case (uppercase or lowercase). For example, the
strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive
answer.

Example
InputCopy
7
1 2 3 4
1 1 1 1
2 2 2 2
1 2 1 2
1 1 5 5
5 5 5 5
4 10 5 9
OutputCopy
NO
YES
YES
NO
NO
YES
NO
Note
In the first test case, we can prove that we can't make a square.

In the second, third, and sixth test cases, we can make a square like this:





*/

// just check if a,b,c,d are all equal
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b && b == c && c == d && d == a)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2167/submission/346207707
