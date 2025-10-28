/*C. Isamatdin and His Magic Wand!
time limit per test2 seconds
memory limit per test256 megabytes
Isamatdin has 𝑛
 toys arranged in a row. The 𝑖
-th toy has an integer 𝑎𝑖
. He wanted to sort them because otherwise, his mother would scold him.

However, Isamatdin never liked arranging toys in order, so his friend JahonaliX
gave him a magic wand to help. Unfortunately, JahonaliX made a small mistake
while creating the wand.

But Isamatdin couldn't wait any longer and decided to use the broken wand
anyway. The wand can only swap two toys if their integers have different parity
(one is even, the other is odd). In other words, you can swap toys in positions
(𝑖,𝑗) only if 𝑎𝑖mod2≠𝑎𝑗mod2 , where mod — is the remainder of integer division.

Now he wants to know the lexicographically smallest∗
 arrangement he can achieve using this broken wand.

∗
A sequence 𝑝
 is lexicographically smaller than a sequence 𝑞
 if there exists an index 𝑖
 such that 𝑝𝑗=𝑞𝑗
 for all 𝑗<𝑖
, and 𝑝𝑖<𝑞𝑖
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of toys.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the integers of the toys.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers — the lexicographically smallest sequence that can be obtained using
the described operation.

Example
InputCopy
7
4
2 3 1 4
5
3 2 1 3 4
4
3 7 5 1
2
1000000000 2
3
1 3 5
5
2 5 3 1 7
4
2 4 8 6
OutputCopy
1 2 3 4
1 2 3 3 4
3 7 5 1
1000000000 2
1 3 5
1 2 3 5 7
2 4 8 6
Note
In the first test case, we can swap positions (1,3)
 and then (2,3)
.

In the second test case, we can swap positions (1,2)
, (1,3)
, and then (2,3)
.

In the third and fourth test cases, we can't swap any positions because all toy
integers have the same parity.



*/

// given a vector a, find it's lexicographically smallest arrangement so
// that
// swap 2 places only if they have different parity
// can swap i,j only if a[i]%2!=a[j]%2
// find lexicographically smallest arrangement
/*Check if both even and odd numbers exist.

If yes → sort entire array.

Else → print array as is.

If there are both even and odd numbers → you can achieve full sorting.

Otherwise (all even or all odd) → you cannot swap anything → keep as-is.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    bool hasEven = false, hasOdd = false;
    for (int x : a) {
      if (x % 2 == 0)
        hasEven = true;
      else
        hasOdd = true;
    }

    if (hasEven && hasOdd)
      sort(a.begin(), a.end());

    for (int x : a)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}
