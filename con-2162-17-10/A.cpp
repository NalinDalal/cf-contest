/*A. Beautiful Average
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 of length 𝑛
.

Your task is to find the maximum possible average value of any subarray∗
 of the array 𝑎
.

Formally, for any indices 𝑙,𝑟
 such that 1≤𝑙≤𝑟≤𝑛
, define the average of the subarray 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟
 as the sum of elements divided by the number of elements or:
𝚊𝚟𝚐(𝑙,𝑟)=1𝑟−𝑙+1∑𝑖=𝑙𝑟𝑎𝑖
Output the maximum value of 𝚊𝚟𝚐(𝑙,𝑟)
 over all choices of 𝑙,𝑟
.

∗
An array 𝑏
 is a subarray of an array 𝑎
 if 𝑏
 can be obtained from 𝑎
 by deletion of several (possibly, zero or all) elements from the beginning and
several (possibly, zero or all) elements from the end. In particular, an array
is a subarray of itself.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤10
) — the length of the array 𝑎
.

The second line of each testcase contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤10
) — the elements of the array.

Output
For each testcase, output a single integer — the maximum average of any subarray
of the given array.

It can be shown that the answer is always an integer.

Example
InputCopy
3
4
3 3 3 3
5
7 1 6 9 9
5
3 4 4 4 3
OutputCopy
3
9
4


*/

#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;         // length of array
    vector<int> a(n); // array decl
    for (int i = 0; i < n; i++)
      cin >> a[i]; // input array

    // find max avg of any subarray

    // Compute sum of first k elements

    double ans = -1e9; // store maximum average found
    for (int i = 0; i < n; i++) {
      double sum = 0;
      for (int j = i; j < n; j++) {
        sum += a[j];
        double avg = sum / (j - i + 1);
        ans = max(ans, avg);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2162/submission/344226793
