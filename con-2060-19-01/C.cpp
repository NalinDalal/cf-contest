/* https://codeforces.com/contest/2060/problem/C

C. Game of Mathletes
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob are playing a game. There are 𝑛 (𝑛 is even) integers written on a
blackboard, represented by 𝑥1,𝑥2,…,𝑥𝑛. There is also a given integer 𝑘 and an
integer score that is initially 0. The game lasts for 𝑛2 turns, in which the
following events happen sequentially:

Alice selects an integer from the blackboard and erases it. Let's call Alice's
chosen integer 𝑎. Bob selects an integer from the blackboard and erases it.
Let's call Bob's chosen integer 𝑏. If 𝑎+𝑏=𝑘, add 1 to score. Alice is playing to
minimize the score while Bob is playing to maximize the score. Assuming both
players use optimal strategies, what is the score after the game ends?

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑘
(2≤𝑛≤2⋅105,1≤𝑘≤2⋅𝑛, 𝑛 is even).

The second line of each test case contains 𝑛 integers 𝑥1,𝑥2,…,𝑥𝑛 (1≤𝑥𝑖≤𝑛) — the
integers on the blackboard.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output the score if both players play optimally.

Example
InputCopy
4
4 4
1 2 3 2
8 15
1 2 3 4 5 6 7 8
6 1
1 1 1 1 1 1
16 9
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
OutputCopy
2
1
0
4
Note
In the first test case, one way the game may go is as follows:

Alice selects 1 and Bob selects 3. The score increases as 1+3=4. Now the two
integers remaining on the blackboard are 2 and 2. Alice and Bob both select 2.
The score increases as 2+2=4. The game ends as the blackboard now has no
integers. In the third test case, it is impossible for the sum of Alice and
Bob's selected integers to be 1, so we answer 0.

Note that this is just an example of how the game may proceed for demonstration
purposes. This may not be Alice or Bob's most optimal strategies.
*/

#include <bits/stdc++.h>

using namespace std;

// if a+b==k then score++
// a is chosen by alice, b by bob
// after each round pop the values already chosen
// alic is minimizing score, bob is maximize score
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  unordered_map<int, int> freq;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    freq[v[i]]++;
  }

  int score = 0;
  for (auto &num : v) {
    int complement = k - num;
    if (freq[num] > 0 && freq[complement] > 0) {
      if (num == complement && freq[num] < 2) {
        continue; // Not enough occurrences to form a pair
      }
      // Form a pair
      score++;
      freq[num]--;
      freq[complement]--;
    }
  }

  cout << score << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// done
