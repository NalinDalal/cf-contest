/* G2. Medium Demon Problem (hard version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the hard version of the problem. The key difference between the two
versions is highlighted in bold.

A group of 𝑛
 spiders has come together to exchange plushies. Initially, each spider has 1
 plushie. Every year, if spider 𝑖
 has at least one plushie, he will give exactly one plushie to spider 𝑟𝑖
. Otherwise, he will do nothing. Note that all plushie transfers happen at the
same time. In this version, each spider is allowed to have more than 1 plushie
at any point in time.

The process is stable in the current year if each spider has the same number of
plushies (before the current year's exchange) as he did the previous year
(before the previous year's exchange). Note that year 1 can never be stable.

Find the first year in which the process becomes stable.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of spiders.

The following line contains 𝑛
 integers 𝑟1,𝑟2,…,𝑟𝑛
 (1≤𝑟𝑖≤𝑛,𝑟𝑖≠𝑖
) — the recipient of the plushie of each spider.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer on a new line, the first year in which the
process becomes stable.

Example
InputCopy
5
2
2 1
5
2 3 4 5 1
5
2 1 4 2 3
5
4 1 1 5 4
10
4 3 9 1 6 7 9 10 10 3
OutputCopy
2
2
5
5
5
Note
For the second test case:

At year 1
, the following array shows the number of plushies each spider has: [1,1,1,1,1]
. Then, year 1
's exchange happens.
At year 2
, the following array shows the number of plushies each spider has: [1,1,1,1,1]
. Since this array is the same as the previous year, this year is stable.
For the third test case:

At year 1
, the following array shows the number of plushies each spider has: [1,1,1,1,1]
. Then, year 1
's exchange happens.
At year 2
, the following array shows the number of plushies each spider has: [1,2,1,1,0]
. Then, year 2
's exchange happens.
At year 3
, the following array shows the number of plushies each spider has: [1,3,0,1,0]
. Then, year 3
's exchange happens.
At year 4
, the following array shows the number of plushies each spider has: [1,4,0,0,0]
. Then, year 4
's exchange happens.
At year 5
, the following array shows the number of plushies each spider has: [1,4,0,0,0]
. Since this array is the same as the previous year, this year is stable.

*/

/*Algorithm
Parse the input.
For each test case:
Initialize a visited array.
Traverse the graph using DFS or BFS to find cycles and their lengths.
Compute the LCM of the cycle lengths.
Output the stabilization year for each test case.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute GCD
ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

// Function to compute LCM
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      cin >> r[i];
      r[i]--; // Convert to 0-based indexing
    }

    vector<bool> visited(n, false);
    ll result = 1;

    // Finding all cycles
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        int current = i, length = 0;
        // Traverse the cycle
        while (!visited[current]) {
          visited[current] = true;
          current = r[current];
          length++;
        }
        // Update the LCM of cycle lengths
        result = lcm(result, length);
      }
    }

    // Output the result for this test case
    cout << result << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
