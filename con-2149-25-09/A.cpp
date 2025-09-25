/*A. Be Positive
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎
 of 𝑛
 elements, where each element is equal to −1
, 0
, or 1
. In one operation, you can choose an index 𝑖
 and increase 𝑎𝑖
 by 1
 (that is, assign 𝑎𝑖:=𝑎𝑖+1
). Operations can be performed any number of times, choosing any indices.

The goal is to make the product of all elements in the array strictly positive
with the minimum number of operations, that is, 𝑎1⋅𝑎2⋅𝑎3⋅…⋅𝑎𝑛>0 . Find the
minimum number of operations.

It is guaranteed that this is always possible.

Input
Each test consists of several test cases.

The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤8
) — the length of the array 𝑎
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
, where −1≤𝑎𝑖≤1
 — the elements of the array 𝑎
.

Output
For each test case, output one integer — the minimum number of operations
required to make the product of the elements in the array strictly positive.

Example
InputCopy
3
3
-1 0 1
4
-1 -1 0 1
5
-1 -1 -1 0 0
OutputCopy
3
1
4
Note
In the first test case: from [−1,0,1]
, you can obtain [1,1,1]
 in 3
 operations.

In the second test case: it is enough to perform 0→1
 (1 operation). In the resulting array 𝑎=[−1,−1,1,1]
, the product of all elements is 1
.

In the third test case: turning two zeros into ones (2 operations), and one −1
 into 1
 (another 2 operations), for a total of 4
.



*/

#include <bits/stdc++>
using namespace std;

// given a vector of integers, make it's product strictly +ve
// if(a[i]==0)opr++
// else if(a[i]==-1)opr+=2
// one thing i noticed, if it has even no of -1 then no need to do anything,
// cause they will cancel out
// but for every zero needs to be accounted, speaking of countZero, add it's
// count to opr
// if odd no of -1, then add 2 to opr
/*For positives x > 0:
To make them 1, you need (x - 1) increments if x > 1.
If x = 1, cost = 0.

For zeros:
Must become 1. Cost = 1.

For negatives x < 0:
You must keep them odd number of negatives → bad.
But since you can only increment, every negative must be incremented up to -1 at
minimum. Cost = (-1 - x).

Example: -3 → -1 takes 2 increments.

Final check (parity of negatives):

If number of negatives is even, product is positive → done.

If odd negatives, we must flip one -1 into +1.
That costs 2 extra increments (-1 → 0 → 1).*/

long long makeAllPositive(const vector<int> &a) {
  long long ops = 0;
  int negCount = 0;

  for (int x : a) {
    if (x < 0) {
      negCount++;
      ops += (-1 - x); // bring up to -1
    } else if (x == 0) {
      ops += 1; // 0 -> 1
    } else {
      ops += (x - 1); // >0 -> 1
    }
  }

  // Odd negatives => flip one -1 into +1 (cost 2)
  if (negCount % 2 == 1) {
    ops += 2;
  }

  return ops;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << makeAllPositive(a) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/contest/2149/submission/340417430
