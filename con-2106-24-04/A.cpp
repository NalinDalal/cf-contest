/*A. Dr. TC
time limit per test1 second
memory limit per test256 megabytes
In order to test his patients' intelligence, Dr. TC created the following test.

First, he creates a binary string∗
 𝑠
 having 𝑛
 characters. Then, he creates 𝑛
 binary strings 𝑎1,𝑎2,…,𝑎𝑛
. It is known that 𝑎𝑖
 is created by first copying 𝑠
, then flipping the 𝑖
'th character (𝟷
 becomes 𝟶
 and vice versa). After creating all 𝑛
 strings, he arranges them into a grid where the 𝑖
'th row is 𝑎𝑖
.

For example,

If 𝑠=𝟷𝟶𝟷
, 𝑎=[𝟶𝟶𝟷,𝟷𝟷𝟷,𝟷𝟶𝟶]
.
If 𝑠=𝟶𝟶𝟶𝟶
, 𝑎=[𝟷𝟶𝟶𝟶,𝟶𝟷𝟶𝟶,𝟶𝟶𝟷𝟶,𝟶𝟶𝟶𝟷]
.
The patient needs to count the number of 1
s written on the board in less than a second. Can you pass the test?

∗
A binary string is a string that only consists of characters 𝟷
 and 𝟶
.

Input
The first line of the input consists of a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤10
) — the length of the binary string 𝑠
.

The second line of each test case contains a single binary string 𝑠
 of size 𝑛
.

Output
For each test case, output a single integer, the number of 𝟷
s on the board.

Example
InputCopy
5
3
101
1
1
5
00000
2
11
3
010
OutputCopy
5
0
5
2
4
Note
The first example is explained in the statement.

For the second example, the only string written on the board will be the string
𝟶 ; therefore, the answer is 0
.

In the third example, the following strings will be written on the board:
[𝟷𝟶𝟶𝟶𝟶,𝟶𝟷𝟶𝟶𝟶,𝟶𝟶𝟷𝟶𝟶,𝟶𝟶𝟶𝟷𝟶,𝟶𝟶𝟶𝟶𝟷] ; so there are five 𝟷 s written on the board.*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> v(s.size());
    for (int i = 0; i < n; i++) {
      string temp = s;
      // Flip the i-th character: '0' -> '1' and '1' -> '0'
      temp[i] = (temp[i] == '0') ? '1' : '0';
      v[i] = temp;
      // v[i] = copy s and flip it's ith char;
    }

    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == '1')
          count++;
      }
    }

    cout << count << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2106/submission/317003910
