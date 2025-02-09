/* B. Skibidus and Ohio
time limit per test1 second
memory limit per test256 megabytes
Skibidus is given a string 𝑠 that consists of lowercase Latin letters. If 𝑠
contains more than 1 letter, he can:

Choose an index 𝑖 (1≤𝑖≤|𝑠|−1, |𝑠| denotes the current length of 𝑠) such that
𝑠𝑖=𝑠𝑖+1. Replace 𝑠𝑖 with any lowercase Latin letter of his choice. Remove 𝑠𝑖+1
from the string. Skibidus must determine the minimum possible length he can
achieve through any number of operations.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The only line of each test case contains a string 𝑠 (1≤|𝑠|≤100). It is
guaranteed 𝑠 only contains lowercase Latin letters.

Output
For each test case, output an integer on the new line, the minimum achievable
length of 𝑠.

Example
InputCopy
4
baa
skibidus
cc
ohio
OutputCopy
1
8
1
4
Note
In the first test case, Skibidus can:

Perform an operation on 𝑖=2. He replaces 𝑠2 with b and removes 𝑠3 from the
string. Then, 𝑠 becomes bb.Perform an operation on 𝑖=1. He replaces 𝑠1 with b
and removes 𝑠2 from the string. Then, 𝑠 becomes b.Because 𝑠 only contains 1
letter, Skibidus cannot perform any more operations. Therefore, the answer is 1
for the first test case.

In the second test case, he cannot perform an operation on any index. Therefore,
the answer is still the length of the initial string, 8.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
  std::srand(std::time(0)); // Seed for randomness
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;

    int i = 0;
    while (i < static_cast<int>(s.length()) - 1) { // Ensure valid index
      if (s[i] == s[i + 1]) {
        // replace s[i] with any lowercase Latin letter of his choice.
        // remove si+1 from string
        s[i] = 'a' + rand() % 26; // Replace with a random lowercase letter
        s.erase(i + 1, 1);        // Remove duplicate character
        // Do NOT increment `i`, check the new character at `i` again
      } else {
        i++; // Move forward only if no deletion happened
      }
    }

    std::cout << s.length() << std::endl;
  }
  return 0;
}
