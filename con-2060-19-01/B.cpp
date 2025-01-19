/* B. Farmer John's Card Game
time limit per test2 seconds
memory limit per test256 megabytes

Farmer John's 𝑛 cows are playing a card game! Farmer John has a deck of 𝑛⋅𝑚
cards numbered from 0 to 𝑛⋅𝑚−1. He distributes 𝑚 cards to each of his 𝑛 cows.

Farmer John wants the game to be fair, so each cow should only be able to play 1
card per round. He decides to determine a turn order, determined by a
permutation∗ 𝑝 of length 𝑛 , such that the 𝑝𝑖'th cow will be the 𝑖'th cow to
place a card on top of the center pile in a round.

In other words, the following events happen in order in each round:

The 𝑝1'th cow places any card from their deck on top of the center pile.
The 𝑝2'th cow places any card from their deck on top of the center pile.
...
The 𝑝𝑛'th cow places any card from their deck on top of the center pile.
There is a catch. Initially, the center pile contains a card numbered −1. In
order to place a card, the number of the card must be greater than the number of
the card on top of the center pile. Then, the newly placed card becomes the top
card of the center pile. If a cow cannot place any card in their deck, the game
is considered to be lost.

Farmer John wonders: does there exist 𝑝 such that it is possible for all of his
cows to empty their deck after playing all 𝑚 rounds of the game? If so, output
any valid 𝑝. Otherwise, output −1.

∗A permutation of length 𝑛 contains each integer from 1 to 𝑛 exactly once

Input
The first line contains an integer 𝑡 (1≤𝑡≤400) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛⋅𝑚≤2000) —
the number of cows and the number of cards each cow receives.

The following 𝑛 lines contain 𝑚 integers each – the cards received by each cow.
It is guaranteed all given numbers (across all 𝑛 lines) are distinct and in the
range from 0 to 𝑛⋅𝑚−1, inclusive.

It is guaranteed the sum of 𝑛⋅𝑚 over all test cases does not exceed 2000.

Output
For each test case, output the following on a new line:

If 𝑝 exists, output 𝑛 space-separated integers 𝑝1,𝑝2,…,𝑝𝑛.
Otherwise, output −1.

Example
InputCopy
4
2 3
0 4 2
1 5 3
1 1
0
2 2
1 2
0 3
4 1
1
2
0
3
OutputCopy
1 2
1
-1
3 1 2 4
Note
In the first test case, one turn order that allows all cards to be played is by
having the first cow go before the second cow. The cards played will be
0→1→2→3→4→5
.

In the second test case, there is only one cow, so having the cow play all of
her cards in increasing order will empty the deck.

In the third test case, it can be shown there is no valid turn order that allows
all cards to be played.


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve() {
  // n cow, n*m no of cards
  // each cow has m cards; pth cow plays pth card
  // 1 card per round
  // ith cow plays ith card on top of center pile
  // newCard>stack.top(), stack.pop(), then stack.push(newCard)
  // if(newCard<stack.top()){game is lost}
  int n, m;
  cin >> n >> m;
  // Read cards for each cow
  vector<vector<int>> cards(n);
  for (int i = 0; i < n; i++) {
    cards[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> cards[i][j];
    }
    // Sort each cow's cards in increasing order
    sort(cards[i].begin(), cards[i].end());
  }
  // Pair each cow's smallest card with its index
  vector<pair<int, int>> smallest;
  for (int i = 0; i < n; i++) {
    smallest.push_back({cards[i][0], i});
  }

  // Sort cows by their smallest cards
  sort(smallest.begin(), smallest.end());

  // Extract the order of cows
  vector<int> order;
  for (auto &p : smallest) {
    order.push_back(p.second); // +1 for 1-based indexing
  }

  // Simulate the game
  int topCard = -1; // Initial card on the pile
  for (int round = 0; round < m; round++) {
    for (int idx : order) {
      if (cards[idx][round] <= topCard) {
        cout << -1 << endl;
        return;
      }
      topCard = cards[idx - 1][round]; // Update the top card
    }
  }

  // If valid, output the order
  for (int i = 0; i < n; i++) {
    cout << order[i] << " ";
  }
  cout << endl;
  // output all p or -1 if game is lost
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// solved
