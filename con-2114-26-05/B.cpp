/* B. Not Quite a Palindromic String
time limit per test2 seconds
memory limit per test256 megabytes
Vlad found a binary string∗
 𝑠
 of even length 𝑛
. He considers a pair of indices (𝑖,𝑛−𝑖+1
), where 1≤𝑖<𝑛−𝑖+1
, to be good if 𝑠𝑖=𝑠𝑛−𝑖+1
 holds true.

For example, in the string '010001' there is only 1
 good pair, since 𝑠1≠𝑠6
, 𝑠2≠𝑠5
, and 𝑠3=𝑠4
. In the string '0101' there are no good pairs.

Vlad loves palindromes, but not too much, so he wants to rearrange some
characters of the string so that there are exactly 𝑘 good pairs of indices.

Determine whether it is possible to rearrange the characters in the given string
so that there are exactly 𝑘 good pairs of indices (𝑖,𝑛−𝑖+1
).

∗
A string 𝑠
 is called binary if it consists only of the characters '0' and '1'

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105
, 0≤𝑘≤𝑛2
, 𝑛
 is even) — the length of the string and the required number of good pairs.

The second line of each test case contains a binary string 𝑠
 of length 𝑛
.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if there is a way to rearrange the characters
of the string so that there are exactly 𝑘 good pairs, otherwise output "NO".

You may output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
6
6 2
000000
2 1
01
4 1
1011
10 2
1101011001
10 1
1101011001
2 1
11
OutputCopy
NO
NO
YES
NO
YES
YES

*/

#include <bits/stdc++.h>
using namespace std;

bool possible(int n, int k, const string &s) {
  //(i,n-i+1) is good if s[i]=s[n-i+1]
  // true if string can be rearranged to make good
  // else false
  if (k > n / 2)
    return false;

  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'a']++;

  int total_pairs = 0;
  for (int f : freq)
    total_pairs += f / 2;

  return k <= total_pairs;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // cout YES if there is way to rearrange the characters of the string so
    // that there are exactly k good pairs else cout NO
    cout << (possible(n, k, s) ? "YES" : "NO") << endl;
  }
  return 0;
}
