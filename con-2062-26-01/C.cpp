/* https://codeforces.com/contest/2062/problem/C
C. Cirno and Operations
time limit per test2 seconds
memory limit per test512 megabytes
Cirno has a sequence 𝑎
 of length 𝑛
. She can perform either of the following two operations for any (possibly,
zero) times unless the current length of 𝑎 is 1
:

Reverse the sequence. Formally, [𝑎1,𝑎2,…,𝑎𝑛]
 becomes [𝑎𝑛,𝑎𝑛−1,…,𝑎1]
 after the operation.
Replace the sequence with its difference sequence. Formally, [𝑎1,𝑎2,…,𝑎𝑛]
 becomes [𝑎2−𝑎1,𝑎3−𝑎2,…,𝑎𝑛−𝑎𝑛−1]
 after the operation.
Find the maximum possible sum of elements of 𝑎
 after all operations.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of input test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the length of sequence 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (|𝑎𝑖|≤1000
) — the sequence 𝑎
.

Output
For each test case, print an integer representing the maximum possible sum.

Example
InputCopy
5
1
-1000
2
5 -3
2
1000 1
9
9 7 9 -9 9 -8 7 -8 9
11
678 201 340 444 453 922 128 987 127 752 0
OutputCopy
-1000
8
1001
2056
269891
Note
In the first test case, Cirno can not perform any operation, so the answer is
−1000
.

In the second test case, Cirno firstly reverses the sequence, then replaces the
sequence with its difference sequence: [5,−3]→[−3,5]→[8] . It can be proven that
this maximizes the sum, so the answer is 8
.

In the third test case, Cirno can choose not to operate, so the answer is 1001
.




*/
// mine
/*
#include <iostream>
#include <vector>
using namespace std;

int sol(vector<int> a(n)) {
  while (a.size() > 1) {
    a.reverse();
    for (int i = 0; i < n; i++) {
      a[i] = a[i + 1] - a[i];
    }
  }
  return
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sol(a(n));
  }
  return 0;
}*/

// gpt
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to solve for one test case
int solve(vector<int> &a) {
  // Sort the sequence in non-decreasing order
  sort(a.begin(), a.end());

  // Calculate the difference sequence until only one element is left
  while (a.size() > 1) {
    vector<int> diff;
    for (size_t i = 1; i < a.size(); i++) {
      diff.push_back(a[i] - a[i - 1]);
    }
    a = diff; // Replace `a` with the difference sequence
  }
  return a[0]; // The remaining single element
}

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n;
    cin >> n; // Length of the sequence
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve(a) << endl;
  }
  return 0;
}
