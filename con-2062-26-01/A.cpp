/* https://codeforces.com/contest/2062/problem/A
A. String
time limit per test1 second
memory limit per test512 megabytes
You are given a string 𝑠 of length 𝑛 consisting of 𝟶 and/or 𝟷. In one operation,
you can select a non-empty subsequence 𝑡 from 𝑠 such that any two adjacent
characters in 𝑡 are different. Then, you flip each character of 𝑡 (𝟶 becomes 𝟷
and 𝟷 becomes 𝟶). For example, if 𝑠=𝟶⎯⎯𝟶𝟷𝟶𝟷⎯⎯⎯⎯⎯⎯ and 𝑡=𝑠1𝑠3𝑠4𝑠5=𝟶𝟷𝟶𝟷, after the
operation, 𝑠 becomes 𝟷⎯⎯𝟶𝟶𝟷𝟶⎯⎯⎯⎯⎯⎯.

Calculate the minimum number of operations required to change all characters in
𝑠 to 𝟶.

Recall that for a string 𝑠=𝑠1𝑠2…𝑠𝑛, any string 𝑡=𝑠𝑖1𝑠𝑖2…𝑠𝑖𝑘 (𝑘≥1) where
1≤𝑖1<𝑖2<…<𝑖𝑘≤𝑛 is a subsequence of 𝑠.

Input
The first line of input contains a single integer 𝑡 (1≤𝑡≤104) — the number of
input test cases.

The only line of each test case contains the string 𝑠 (1≤|𝑠|≤50), where |𝑠|
represents the length of 𝑠.

Output
For each test case, output the minimum number of operations required to change
all characters in 𝑠 to 𝟶.

Example
InputCopy
5
1
000
1001
10101
01100101011101
OutputCopy
1
0
2
3
8
Note
In the first test case, you can flip 𝑠1. Then 𝑠 becomes 𝟶, so the answer is 1.

In the fourth test case, you can perform the following three operations in
order:

Flip 𝑠1𝑠2𝑠3𝑠4𝑠5. Then 𝑠 becomes 𝟶𝟷𝟶𝟷𝟶⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯.
Flip 𝑠2𝑠3𝑠4. Then 𝑠 becomes 𝟶𝟶𝟷𝟶⎯⎯⎯⎯⎯⎯𝟶.
Flip 𝑠3. Then 𝑠 becomes 𝟶𝟶𝟶⎯⎯𝟶𝟶.
It can be shown that you can not change all characters in 𝑠 to 𝟶 in less than
three operations, so the answer is 3.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  // it is subsequence
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int countOne = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1')
        countOne++;
    }
    cout << countOne << endl;
  }
  return 0;
}

// sub:https://codeforces.com/contest/2062/submission/303063859
