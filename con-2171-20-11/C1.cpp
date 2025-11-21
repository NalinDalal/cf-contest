/*C1. Renako Amaori and XOR Game (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
Yup. I couldn't do this any longer. No. Freaking. Way.
— Renako Amaori
This is the easy version of the problem. The only difference between the easy
and hard versions is that in the easy version, 𝑎𝑖,𝑏𝑖≤1
.

Renako is stuck between a rock and a hard place... and by that, of course, I
mean Ajisai and Mai! Both of them want to hang out with her, and she just can't
decide! So Ajisai and Mai have decided to play the XOR game.

Ajisai and Mai are given arrays 𝑎
 and 𝑏
 of length 𝑛
 (0≤𝑎𝑖,𝑏𝑖≤1
). They will play a game that lasts for 𝑛
 turns, where Ajisai moves on odd-numbered turns and Mai moves on even-numbered
turns. On the 𝑖 -th turn, the player to move may choose to swap 𝑎𝑖 and 𝑏𝑖 , or
pass.

Note that if a swap occurs, the index that is being swapped must match the turn
number. For example, on the first turn, Ajisai may choose to swap 𝑎1 and 𝑏1 , or
pass. On the second turn, Mai may choose to swap 𝑎2 and 𝑏2 , or pass. This
continues for 𝑛 turns. Thus, only Ajisai can swap odd indices, and only Mai can
swap even indices.

At the end of the game, Ajisai achieves a score of 𝑎1⊕𝑎2⊕⋯⊕𝑎𝑛
, and Mai achieves a score of 𝑏1⊕𝑏2⊕⋯⊕𝑏𝑛
∗
. The player with the higher score wins. If the players have the same score, the
game ends in a tie.

Determine the outcome of the game with optimal play. More formally, one player
is considered to win with optimal play if there exists a strategy for them such
that they always win, regardless of their opponent's choices. The game is
considered a tie with optimal play if neither player has such a strategy.

∗
⊕
 denotes the bitwise XOR operation

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers, 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤1
).

The third line of each test case contains 𝑛
 integers, 𝑏1,𝑏2,…,𝑏𝑛
 (0≤𝑏𝑖≤1
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "Ajisai" if Ajisai wins with optimal
play, "Mai" if Mai wins with optimal play, or "Tie" if the game ends in a tie
with optimal play.

You may output the answer in any case (upper or lower). For example, the strings
"mAi", "mai", "MAI", and "maI" will be recognized as "Mai".

Example
InputCopy
6
4
1 0 0 1
1 0 1 1
6
0 1 1 1 1 0
0 0 1 0 1 1
4
0 0 1 0
1 0 1 1
5
1 0 1 1 1
0 1 1 1 0
6
1 1 1 1 1 1
1 1 1 1 1 1
5
0 1 0 0 1
1 0 0 1 1
OutputCopy
Ajisai
Mai
Tie
Ajisai
Tie
Mai
Note
In the first example, one way the game might play out is as follows:

On turn 1, Ajisai chooses to swap 𝑎1
 and 𝑏1
. Now the arrays are 𝑎=[1,0,0,1]
 and 𝑏=[1,0,1,1]
.

On turn 2, Mai chooses to pass.

On turn 3, Ajisai chooses to swap 𝑎3
 and 𝑏3
. Now the arrays are 𝑎=[1,0,1,1]
 and 𝑏=[1,0,0,1]
.

On turn 4, Mai chooses to swap 𝑎4
 and 𝑏4
. Now the arrays are 𝑎=[1,0,1,1]
 and 𝑏=[1,0,0,1]
.

Now, Ajisai's final score is 1⊕0⊕1⊕1=1
 and Mai's final score is 1⊕0⊕0⊕1=0
. Therefore, Ajisai wins the game.

It is not guaranteed that the above description is representative of optimal
play.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans;

    if (a > b)
      ans = 1;
    else if (a == b)
      ans = 0;
    else
      ans = -1;

    if (ans == 1)
      cout << "Ajisai" << endl;
    else if (ans == 0)
      cout << "Tie" << endl;
    else
      cout << "Mai" << endl;
  }
  return 0;
}
