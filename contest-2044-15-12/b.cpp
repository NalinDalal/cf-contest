/* B. Normal Problem
time limit per test1 second
memory limit per test256 megabytes
A string consisting of only characters 'p', 'q', and 'w' is painted on a glass
window of a store. Ship walks past the store, standing directly in front of the
glass window, and observes string 𝑎 . Ship then heads inside the store, looks
directly at the same glass window, and observes string 𝑏
.

Ship gives you string 𝑎
. Your job is to find and output 𝑏
.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The only line of each test case contains a string 𝑎 (1≤|𝑎|≤100) — the string
Ship observes from outside the store. It is guaranteed that 𝑎 only contains
characters 'p', 'q', and 'w'.

Output
For each test case, output string 𝑏
, the string Ship observes from inside the store, on a new line.

Example
InputCopy
5
qwq
ppppp
pppwwwqqq
wqpqwpqwwqp
pqpqpqpq
OutputCopy
pwp
qqqqq
pppwwwqqq
qpwwpqwpqpw
pqpqpqpq

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin >> t; // testcases input
  while (t--) {
    string a;
    cin >> a;
    string b = a;

    // convert the string a to string b
    for (int i = 0; i < a.length(); i++) {
      if (a[i] == 'p')
        b[i] = 'q';
      else if (a[i] == 'q')
        b[i] = 'p';
      else if (a[i] == 'w')
        b[i] = 'w';
    }
    cout << b << endl;
  }
  return 0;
}

// for t testcases
// a is string given by user consisting only p,q,r
// b is output string
// so basically for each char in string, convert p to q; q to p; w to w;
