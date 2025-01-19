/* A. Fibonacciness
time limit per test1 second
memory limit per test256 megabytes
There is an array of 5 integers. Initially, you only know 𝑎1,𝑎2,𝑎4,𝑎5. You may
set 𝑎3 to any positive integer, negative integer, or zero. The Fibonacciness of
the array is the number of integers 𝑖 (1≤𝑖≤3) such that 𝑎𝑖+2=𝑎𝑖+𝑎𝑖+1. Find the
maximum Fibonacciness over all integer values of 𝑎3.

Input
The first line contains an integer 𝑡 (1≤𝑡≤500) — the number of test cases.

The only line of each test case contains four integers 𝑎1,𝑎2,𝑎4,𝑎5 (1≤𝑎𝑖≤100).

Output
For each test case, output the maximum Fibonacciness on a new line.

Example
InputCopy
6
1 1 3 5
1 3 2 1
8 10 28 100
100 1 100 1
1 100 1 100
100 100 100 100
OutputCopy
3
2
2
1
1
2

Note
In the first test case, we can set 𝑎3 to 2 to achieve the maximal Fibonacciness
of 3.

In the third test case, it can be shown that 2 is the maximum Fibonacciness that
can be achieved. This can be done by setting 𝑎3 to 18.*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int calculateFibonacciness(int a1, int a2, int a3, int a4, int a5) {
  int fibCount = 0;
  if (a3 == a1 + a2)
    fibCount++; // Check a3 = a1 + a2
  if (a4 == a2 + a3)
    fibCount++; // Check a4 = a2 + a3
  if (a5 == a3 + a4)
    fibCount++; // Check a5 = a3 + a4
  return fibCount;
}
int solve() {
  vector<int> v(5);
  cin >> v[0] >> v[1] >> v[3] >> v[4];
  // fibonacci condition: v[i+2]=v[i]+v[i+1] for 1<=i<=3
  // if fibonacci increase count
  int a1 = v[0], a2 = v[1], a4 = v[3], a5 = v[4];
  int maxFib = 0;

  // but we have to check for v[2] also; v[2] can be anything
  // v[2]=v[4]-v[2];v[3]=v[1]+v[2];v[5]=v[3]+v[4];
  // Try setting a3 to ensure the conditions involving a4 and a5
  int possibleA3[] = {a1 + a2, a4 - a2, a5 - a4};
  for (int a3 : possibleA3) {
    maxFib = max(maxFib, calculateFibonacciness(a1, a2, a3, a4, a5));
  }
  cout << maxFib << endl;
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
