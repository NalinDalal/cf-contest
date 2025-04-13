/* A. Trippi Troppi
time limit per test1 second
memory limit per test256 megabytes
Trippi Troppi resides in a strange world. The ancient name of each country
consists of three strings. The first letter of each string is concatenated to
form the country's modern name.

Given the country's ancient name, please output the modern name.

Input
The first line contains an integer 𝑡
 – the number of independent test cases (1≤𝑡≤100
).

The following 𝑡
 lines each contain three space-separated strings. Each string has a length of
no more than 10 , and contains only lowercase Latin characters.

Output
For each test case, output the string formed by concatenating the first letter
of each word.

Example
InputCopy
7
united states america
oh my god
i cant lie
binary indexed tree
believe in yourself
skibidi slay sigma
god bless america
OutputCopy
usa
omg
icl
bit
biy
sss
gba

*/

#include <iostream>
#include <string>

// given a string, return the first letter of each word concatenated

using namespace std;

// given a string, return the first letter of each word concatenated
string ans(const string &str) {
  string first_letter = "";
  for (int i = 0; i < str.length(); i++) {
    if (i == 0) {
      first_letter += str[i];
    } else if (str[i] == ' ' && i + 1 < str.length()) {
      first_letter += str[i + 1];
    }
  }
  return first_letter;
}

int main() {
  int t;
  cin >> t;
  cin.ignore(); // to consume the newline after number input

  while (t--) {
    string s;
    getline(cin, s); // read full line with spaces
    cout << ans(s) << endl;
  }

  return 0;
}
// sub: https://codeforces.com/contest/2094/submission/315327344
