/*A. Homework
time limit per test1 second
memory limit per test256 megabytes
Vlad and Dima have been assigned a task in school for their English class. They
were given two strings 𝑎 and 𝑏 and asked to append all characters from 𝑏 to
string 𝑎 in any order. The guys decided to divide the work between themselves
and, after lengthy negotiations, determined who would add each character from
string 𝑏 to 𝑎
.

Due to his peculiarities, Vlad can only add characters to the beginning of the
word, while Dima can only add them to the end. They add characters in the order
they appear in string 𝑏 . Your task is to determine what string Vlad and Dima
will end up with.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test
cases follows.

The first line contains an integer 𝑛
 (1≤𝑛≤10
) — the length of the string 𝑎
.

The second line contains the string 𝑎
, consisting of lowercase letters of the English alphabet.

The third line contains an integer 𝑚
 (1≤𝑚≤10
) — the length of the strings 𝑏
 and 𝑐
.

The fourth line contains the string 𝑏
, consisting of lowercase letters of the English alphabet.

The fifth line contains the string 𝑐
, consisting of the characters 'V' and 'D' — the distribution of the characters
of string 𝑏 between Dima and Vlad. If 𝑐𝑖 = 'V', then the 𝑖 -th letter is added
by Vlad; otherwise, it is added by Dima.

Output
For each test case, output the string that will result
f[48;56;204;1792;2856trom Dima and Vlad's work.

Example
InputCopy
4
2
ot
2
ad
DV
3
efo
7
rdcoecs
DVDVDVD
3
aca
4
bbaa
DVDV
3
biz
4
abon
VVDD
OutputCopy
dota
codeforces
abacaba
babizon
Note
In the first test case, there is initially a string 𝑜𝑡
. Then Dima appends the character 𝑎
 to the end of the string, resulting in 𝑜𝑡𝑎
, and Vlad appends the last character, resulting in 𝑑𝑜𝑡𝑎
.

In the second test case, the string will change as follows:
𝑒𝑓𝑜→𝑒𝑓𝑜𝑟→𝑑𝑒𝑓𝑜𝑟→𝑑𝑒𝑓𝑜𝑟𝑐→𝑜𝑑𝑒𝑓𝑜𝑟𝑐→𝑜𝑑𝑒𝑓𝑜𝑟𝑐𝑒→𝑐𝑜𝑑𝑒𝑓𝑜𝑟𝑐𝑒→𝑐𝑜𝑑𝑒𝑓𝑜𝑟𝑐𝑒𝑠

In the third test case: 𝑎𝑐𝑎→𝑎𝑐𝑎𝑏→𝑏𝑎𝑐𝑎𝑏→𝑏𝑎𝑐𝑎𝑏𝑎→𝑎𝑏𝑎𝑐𝑎𝑏𝑎

In the fourth test case: 𝑏𝑖𝑧→𝑎𝑏𝑖𝑧→𝑏𝑎𝑏𝑖𝑧→𝑏𝑎𝑏𝑖𝑧𝑜→𝑏𝑎𝑏𝑖𝑧𝑜𝑛



*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n; // n is length of string a
    string a;
    cin >> a;
    int m;
    cin >> m; // m is length of string b,c
    string b;
    cin >> b;
    string c;
    cin >> c; // c is order of characters to add from

    // append characters from b to a in any order
    // string c-> c[i]=V then vlad else Dina
    // vlad can add only at beginning of word
    // dina can add only at end
    // They add characters in the order they appear in string 𝑏
    // Your task is to determine what string Vlad and Dima will end up with.
    // n-i from b
    // i from a
    string ans = a; // start with a

    /*like given -> aca, bbaa, DVDV
     * aca-> aca+b=acab
     * b+acab=bacab
     * bacab+a=bacaba
     * a+bacaba=abacaba
     */
    for (int i = 0; i < m; i++) {
      if (c[i] == 'V') {
        ans = b[i] + ans; // Vlad → prepend
      } else {
        ans = ans + b[i]; // Dima → append
      }
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2132/submission/334837847
