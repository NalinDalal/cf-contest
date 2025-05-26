/* A. Square Year
time limit per test1 second
memory limit per test256 megabytes
One can notice the following remarkable mathematical fact: the number 2025
 can be represented as (20+25)2
.

You are given a year represented by a string 𝑠
, consisting of exactly 4
 characters. Thus, leading zeros are allowed in the year representation. For
example, "0001", "0185", "1375" are valid year representations. You need to
express it in the form (𝑎+𝑏)2 , where 𝑎 and 𝑏 are non-negative integers, or
determine that it is impossible.

For example, if 𝑠
 = "0001", you can choose 𝑎=0
, 𝑏=1
, and write the year as (0+1)2=1
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The following lines describe the test cases.

The only line of each test case contains a string 𝑠
, consisting of exactly 4
 characters. Each character is a digit from 0
 to 9
.

Output
On a separate line for each test case, output:

Two numbers 𝑎
 and 𝑏
 (𝑎,𝑏≥0
) such that (𝑎+𝑏)2=𝑠
, if they exist.
The number −1
 otherwise.
Example
InputCopy
5
0001
1001
1000
4900
2025
OutputCopy
0 1
-1
-1
34 36
20 25

*/

#include <iostream>
#include <string>
using namespace std;

string sol(int yr) {
  // if yr can be represented as (a+b)^2
  // then return a,b else return -1
  int root = sqrt(yr);
  if (root * root != yr) {
    return "-1";
  }

  // Now we want to find a pair (a, b) such that a + b == root
  // You can pick any such a and b (e.g., a = 1, b = root - 1)
  // convert s to integer, check if perfect square
  return to_string(0) + " " + to_string(root);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int yr = stoi(s);
    // if yr can be represented as (a+b)^2
    // then return a,b else return -1
    cout << sol(yr) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2114/submission/321403921
