/*E. Hidden Knowledge of the Ancients
time limit per test2 seconds
memory limit per test256 megabytes
In the world of Deepwoken, there exists an ancient artifact — Tablet of Infinite
Knowledge, on which a sequence of 𝑛 mysterious symbols (each symbol is an
integer) is engraved.

It is said that the true power of the artifact can only be revealed by finding
all sacred fragments — continuous segments of the tablet that contain exactly 𝑘
 distinct numbers, and their length must be between 𝑙
 and 𝑟
 (inclusive).

Formally: Given a sequence 𝑎
 of length 𝑛
 and integers 𝑘
, 𝑙
, 𝑟
. You need to find the number of such boundaries 𝑏
 and 𝑐
 such that:

1≤𝑏≤𝑐≤𝑛
;
among the elements [𝑎𝑏,𝑎𝑏+1,…,𝑎𝑐
] there are exactly 𝑘
 distinct numbers;
𝑙≤𝑐−𝑏+1≤𝑟
.
Input
Each test consists of several test cases.

The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The following describes the test cases.

The first line of each test case contains four integers: 𝑛
, 𝑘
, 𝑙
, and 𝑟
 (1≤𝑘≤𝑛≤2⋅105,1≤𝑙≤𝑟≤𝑛)
.

The second line contains 𝑛
 numbers 𝑎𝑖
 (1≤𝑎𝑖≤109)
 — the mysterious symbols.

It is guaranteed that the total value of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test, output a single integer on a separate line — the number of
continuous subarrays that meet the specified conditions.

Example
InputCopy
5
1 1 1 1
5
5 2 2 3
1 2 1 3 2
6 3 1 6
1 2 3 1 2 3
4 1 1 2
7 7 7 7
7 3 2 4
1 2 1 2 3 2 1
OutputCopy
1
5
10
7
5
Note
In the first test case 𝑎=[5]
, there is only one subarray [5]
, which has a length of 1 and contains exactly 1
 distinct number.

In the fourth test case 𝑎=[7,7,7,7]
, any subarray of identical numbers gives exactly 1
 distinct number. The start and end of possible subarrays are:

Length 1
: [1,1]
, [2,2]
, [3,3]
, [4,4]
.
Length 2
: [1,2]
, [2,3]
, [3,4]
.
In total: 7
.
In the fifth test case 𝑎=[1,2,1,2,3,2,1]
:

Length 2
: all subarrays have only 2
 distinct numbers.
Length 3
: [3,5]
, [5,7]
.
Length 4
: [2,5]
, [3,6]
, [4,7]
.
In total: 5
.


*/

// gives tle:
#include <bits/stdc++.h>
using namespace std;

int solve_for_char(string s, char target) {
  int n = s.length();
  vector<int> positions;

  // Find all positions of target character
  for (int i = 0; i < n; i++) {
    if (s[i] == target) {
      positions.push_back(i);
    }
  }

  int count = positions.size();
  if (count == 0 || count == n)
    return 0;

  int min_cost = INT_MAX;

  // Try placing all target characters in each possible contiguous segment
  for (int start = 0; start + count <= n; start++) {
    int cost = 0;

    // Calculate cost to move each target character to the segment [start,
    // start+count-1]
    for (int i = 0; i < count; i++) {
      int current_pos = positions[i];
      int target_pos = start + i;
      cost += abs(current_pos - target_pos);
    }

    min_cost = min(min_cost, cost);
  }

  return min_cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Try grouping all 'a's together
    int cost_a = solve_for_char(s, 'a');

    // Try grouping all 'b's together
    int cost_b = solve_for_char(s, 'b');

    cout << min(cost_a, cost_b) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/contest/2149/submission/340487359
