/* A. New World, New Me, New Array
time limit per test1 second
memory limit per test256 megabytes
Natsume Akito has just woken up in a new world and immediately received his
first quest! The system provided him with an array 𝑎 of 𝑛 zeros, an integer 𝑘,
and an integer 𝑝.

In one operation, Akito chooses two integers 𝑖 and 𝑥 such that 1≤𝑖≤𝑛 and −𝑝≤𝑥≤𝑝,
and performs the assignment 𝑎𝑖=𝑥.

Akito is still not fully accustomed to controlling his new body, so help him
calculate the minimum number of operations required to make the sum of all
elements in the array equal to 𝑘, or tell him that it is impossible.

Input
The first line of input contains one integer 𝑡 (1≤𝑡≤1000) — the number of test
cases.

The only line of each test case contains three integers 𝑛, 𝑘, 𝑝 (1≤𝑛≤50,
−2500≤𝑘≤2500, 1≤𝑝≤50) — the length of the array, the required sum, and the
boundary of the segment from which numbers can be replaced.

Output
For each test case, output the minimum number of operations to achieve the final
sum 𝑘 in the array, or −1 if it is impossible to achieve the sum 𝑘.

Example
InputCopy
8
21 100 10
9 -420 42
5 -7 2
13 37 7
10 0 49
1 10 9
7 -7 7
20 31 1
OutputCopy
10
-1
4
6
0
-1
1
-1
Note
In the fifth example, the sum of the array is initially zero, so no operations
are needed.

In the sixth example, the maximum sum in the array that we can achieve is 9 (by
assigning the number 9 to the single element), so the sum 10 cannot be obtained
by any operations.

In the seventh example, only one operation 𝑎3=−7 is needed.
*/

#include <cmath>
#include <iostream>

using namespace std;

void solve(int n, int k, int p) {

  // We need to distribute 'k' among 'n' elements where each element is in range
  // [-p, p]

  int max_possible_sum = n * p;  // find max possible sum
  int min_possible_sum = -n * p; // find min possible sum

  // If k is outside this range, it's impossible
  if (k < min_possible_sum || k > max_possible_sum) {
    cout << -1 << endl;
  } else {
    // We can achieve k by using ceil(abs(k) / p) operations
    cout << (abs(k) + p - 1) / p << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k, p;
    cin >> n >> k >> p;
    solve(n, k, p);
  }

  return 0;
}
// sub: https://codeforces.com/contest/2072/submission/307765892
