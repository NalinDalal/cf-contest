/* G. Snakes
time limit per test3 seconds
memory limit per test512 megabytes
Suppose you play a game where the game field looks like a strip of 1×109 square
cells, numbered from 1 to 109.

You have 𝑛 snakes (numbered from 1 to 𝑛) you need to place into some cells.
Initially, each snake occupies exactly one cell, and you can't place more than
one snake into one cell. After that, the game starts.

The game lasts for 𝑞 seconds. There are two types of events that may happen each
second: snake 𝑠𝑖 enlarges: if snake 𝑠𝑖 occupied cells [𝑙,𝑟], it enlarges to a
segment [𝑙,𝑟+1]; snake 𝑠𝑖 shrinks: if snake 𝑠𝑖 occupied cells [𝑙,𝑟], it shrinks
to a segment [𝑙+1,𝑟].

Each second, exactly one of the events happens.

If at any moment of time, any snake runs into some obstacle (either another
snake or the end of the strip), you lose. Otherwise, you win with the score
equal to the maximum cell occupied by any snake so far.

What is the minimum possible score you can achieve?

Input
The first line contains two integers 𝑛 and 𝑞 (1≤𝑛≤20; 1≤𝑞≤2⋅105) — the number of
snakes and the number of events. Next 𝑞 lines contain the description of events
— one per line.

The 𝑖-th line contains either "𝑠𝑖 +" (1≤𝑠𝑖≤𝑛) meaning that the 𝑠𝑖-th snake
enlargesor "𝑠𝑖 -" (1≤𝑠𝑖≤𝑛) meaning that the 𝑠𝑖-th snake shrinks. Additional
constraint on the input: the given sequence of events is valid, i. e. a snake of
length 1 never shrinks.

Output
Print one integer — the minimum possible score.

Examples
InputCopy
3 6
1 +
1 -
3 +
3 -
2 +
2 -
OutputCopy
4
InputCopy
5 13
5 +
3 +
5 -
2 +
4 +
3 +
5 +
5 -
2 +
3 -
3 +
3 -
2 +
OutputCopy
11

Note
In the first test, the optimal strategy is to place the second snake at cell 1,
the third snake — at 2, and the first one — at 3. The maximum occupied cell is
cell 4, and it's the minimum possible score.

In the second test, one of the optimal strategies is to place:
snake 2 at position 1;
snake 3 at position 4;
snake 5 at position 6;
snake 1 at position 9;
snake 4 at position 10.
*/

// n size array{n=10^9}
// n snakes, each snake per square
// time: q seconds
// either enlarge or shrink
// enlarge: [l,r] to [l,r+1]
// shrink: [l,r] to [l+1,r]

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Event {
  int snake;
  char type; // '+' for enlarge, '-' for shrink
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<Event> events(q);
  for (int i = 0; i < q; i++) {
    int s;
    char type;
    cin >> s >> type;
    events[i] = {s - 1, type}; // Convert to 0-based indexing
  }

  vector<int> minStart(n, 0);  // Minimum starting position for each snake
  vector<int> lengths(n, 1);   // Initial lengths of snakes
  vector<int> positions(n, 0); // Starting positions (to be calculated)

  // Backward simulation to determine minimum starting positions
  for (int i = q - 1; i >= 0; i--) {
    int s = events[i].snake;
    if (events[i].type == '-') {
      lengths[s]++; // Snake shrinks: it must have been larger before
    } else if (events[i].type == '+') {
      lengths[s]--; // Snake enlarges: reduce the required length
    }
  }

  // Calculate initial positions to minimize the maximum cell
  int currentPos = 1;
  for (int i = 0; i < n; i++) {
    positions[i] = currentPos;
    currentPos += lengths[i];
  }

  // Forward simulation to determine the maximum occupied cell
  vector<int> left = positions;
  vector<int> right = positions;
  for (int i = 0; i < n; i++) {
    right[i] += lengths[i] - 1;
  }

  int maxCell = 0;
  for (const auto &event : events) {
    int s = event.snake;
    if (event.type == '+') {
      right[s]++;
    } else if (event.type == '-') {
      left[s]++;
    }
    // Update maximum cell occupied
    for (int i = 0; i < n; i++) {
      maxCell = max(maxCell, right[i]);
    }
  }

  cout << maxCell << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
