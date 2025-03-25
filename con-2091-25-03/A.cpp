/*A. Olympiad Date
time limit per test1 second
memory limit per test256 megabytes
The final of the first Olympiad by IT Campus "NEIMARK" is scheduled for March 1,
2025. A nameless intern was tasked with forming the date of the Olympiad using
digits — 01.03.2025.

To accomplish this, the intern took a large bag of digits and began drawing them
one by one. In total, he drew 𝑛 digits — the digit 𝑎𝑖 was drawn in the 𝑖 -th
turn.

You suspect that the intern did extra work. Determine at which step the intern
could have first assembled the digits to form the date of the Olympiad (the
separating dots can be ignored), or report that it is impossible to form this
date from the drawn digits. Note that leading zeros must be displayed.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤20
).

The second line of each test case contains 𝑛
 integers 𝑎𝑖
 (0≤𝑎𝑖≤9
) — the numbers that the intern pulled out in chronological order.

Output
For each test case, output the minimum number of digits that the intern could
pull out. If all the digits cannot be used to make a date, output the number 0
.

Example
InputCopy
4
10
2 0 1 2 3 2 5 0 0 1
8
2 0 1 2 3 2 5 0
8
2 0 1 0 3 2 5 0
16
2 3 1 2 3 0 1 9 2 1 0 3 5 4 0 3
OutputCopy
9
0
8
15



*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    // no i think we need to form date: 01.03.2025
    // find how many digits we need to form a date
    // uhh date is -> 01.03.2025
    // changed to 01032025
    // changed to 00012235
    // now do like traverse the digit from date and input, now as you
    // encounter digits from input, if you find them in date, then nothing
    // return index at which our date will end
    // ex: 2 0 1 2 3 2 5 0 0 1
    // ans: 9
    int ans = 0;
    string target = "01032025";
    int target_index = 0;
    for (int i = 0; i < n; i++) {
      if (target[target_index] == v[i] + '0') { // convert int to char
        target_index++;
      }
      if (target_index == target.size()) {
        ans = i + 1; // +1 because i is zero-indexed
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
