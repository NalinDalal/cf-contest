/* A. False Alarm
time limit per test1 second
memory limit per test256 megabytes
Yousef is at the entrance of a long hallway with 𝑛
 doors in a row, numbered from 1
 to 𝑛
. He needs to pass through all the doors from 1
 to 𝑛
 in order of numbering and reach the exit (past door 𝑛
).

Each door can be open or closed. If a door is open, Yousef passes through it in
1 second. If the door is closed, Yousef can't pass through it.

However, Yousef has a special button which he can use at most once at any
moment. This button makes all closed doors become open for 𝑥 seconds.

Your task is to determine if Yousef can pass through all the doors if he can use
the button at most once.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains two integers 𝑛,𝑥
 (1≤𝑛,𝑥≤10
) — the number of doors and the number of seconds of the button, respectively.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,...,𝑎𝑛
 (𝑎𝑖∈{0,1}
) — the state of each door. Open doors are represented by '0', while closed
doors are represented by '1'.

It is guaranteed that each test case contains at least one closed door.

Output
For each test case, output "YES" if Yousef can reach the exit, and "NO"
otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
7
4 2
0 1 1 0
6 3
1 0 1 1 0 0
8 8
1 1 1 0 0 1 1 1
1 2
1
5 1
1 0 1 0 1
7 4
0 0 0 1 1 0 1
10 3
0 1 0 0 1 0 0 1 0 0
OutputCopy
YES
NO
YES
YES
NO
YES
NO
Note
In the first test case, the optimal way is as follows:

At time 0
, the door is open, so Yousef passes.
At time 1
, the door is closed, Yousef can use the button now and pass through the door.
At time 2
, the button's effect is still on, so Yousef can still pass.
At time 3
, the button's effect has finished, but the door is open. Yousef passes and
reaches the exit. In the second test case, Yousef has a 3-second button, but he
would need at least a 4-second button to reach the exit. Therefore, the answer
is NO.

In the third test case, Yousef can turn on the button before starting to move.
All the doors will stay open until he reaches the exit.
*/

/* Traverse the doors
keep walking till door are open (0)
hit a closed door(1)->
    if button not used
        use the button
        if within x door hit hallway->yes
        else no
    else
        no
*/

/* Track timeSpent

Allow using the button once

When button is used, start timer = x

Decrement the timer each second

After timer ends, he can only pass if the door is 0

If he hits a 1 with no button (or timer = 0), then he's stuck*/

#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    bool usedButton = false;
    int timeRemaining = 0;
    bool canReach = true;

    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        if (timeRemaining > 0)
          --timeRemaining;
        continue;
      }

      // a[i] == 1 (closed)
      if (timeRemaining > 0) {
        --timeRemaining;
        continue;
      }

      // If we reach a closed door and can't pass, press button (if not used)
      if (!usedButton) {
        usedButton = true;
        timeRemaining = x - 1; // use 1 second now
      } else {
        // Already used button and can't pass
        canReach = false;
        break;
      }
    }

    std::cout << (canReach ? "YES" : "NO") << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/contest/2117/submission/323442456
