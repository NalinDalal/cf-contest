/*D. Retaliation
time limit per test2 seconds
memory limit per test256 megabytes
Yousef wants to explode an array 𝑎1,𝑎2,…,𝑎𝑛
. An array gets exploded when all of its elements become equal to zero.

In one operation, Yousef can do exactly one of the following:

For every index 𝑖
 in 𝑎
, decrease 𝑎𝑖
 by 𝑖
.
For every index 𝑖
 in 𝑎
, decrease 𝑎𝑖
 by 𝑛−𝑖+1
.
Your task is to help Yousef determine if it is possible to explode the array
using any number of operations.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the size of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print "YES" if Yousef can explode the array, otherwise
output "NO".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
4
3 6 6 3
5
21 18 15 12 9
10
2 6 10 2 5 5 1 2 4 10
7
10 2 16 12 8 20 4
2
52 101
2
10 2
OutputCopy
NO
YES
NO
NO
YES
NO
Note
In the second test case, we can do the following:

Perform 1
 operation of the first type. The array becomes [20,16,12,8,4]
.
Perform 4
 operations of the second type. The array becomes [0,0,0,0,0]
.
In the first, third, fourth, and sixth test cases, it can be proven that it is
impossible to make all elements equal to zero using any number of operations.*/

/* Compute y = (a[n] - a*n) / (1 - n^2)

Compute x = a - y*n

Both x and y must be integers and non-negative.

For all i from 1 to n, check that a[i] == x*i + y*(n-i+1)*/

#include <iostream>
#include <vector>
using namespace std;
bool canExplode(const vector<int> &v) {
  int n = v.size();
  long long denom = 1LL - 1LL * n * n;
  long long numer = 1LL * v[n - 1] - 1LL * v[0] * n;

  // denom is negative, so numer must be negative or zero for y to be
  // non-negative
  if (denom == 0)
    return false; // n == 1, but n >= 2 by constraints

  if (numer % denom != 0)
    return false;
  long long y = numer / denom;
  if (y < 0)
    return false;
  long long x = 1LL * v[0] - y * n;
  if (x < 0)
    return false;

  // Check all elements
  for (int i = 0; i < n; ++i) {
    long long want = x * (i + 1) + y * (n - i);
    if (want != v[i])
      return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    if (canExplode(v))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2117/submission/323497264
