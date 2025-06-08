/* E. Lost Soul
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integer arrays 𝑎
 and 𝑏
, each of length 𝑛
.

You may perform the following operation any number of times:

Choose an index 𝑖
 (1≤𝑖≤𝑛−1)
, and set 𝑎𝑖:=𝑏𝑖+1
, or set 𝑏𝑖:=𝑎𝑖+1
.
Before performing any operations, you are allowed to choose an index 𝑖
 (1≤𝑖≤𝑛)
 and remove both 𝑎𝑖
 and 𝑏𝑖
 from the arrays. This removal can be done at most once.

Let the number of matches between two arrays 𝑐
 and 𝑑
 of length 𝑚
 be the number of positions 𝑗
 (1≤𝑗≤𝑚)
 such that 𝑐𝑗=𝑑𝑗
.

Your task is to compute the maximum number of matches you can achieve.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of each test case follows.

The first line contains an integer 𝑛
 (2≤𝑛≤2⋅105)
 — the length of 𝑎
 and 𝑏
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛)
 — the elements of 𝑎
.

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤𝑛)
 — the elements of 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the answer for the test case.

Example
InputCopy
10
4
1 3 1 4
4 3 2 2
6
2 1 5 3 6 4
3 2 4 5 1 6
2
1 2
2 1
6
2 5 1 3 6 4
3 5 2 3 4 6
4
1 3 2 2
2 1 3 4
8
3 1 4 6 2 2 5 7
4 2 3 7 1 1 6 5
10
5 1 2 7 3 9 4 10 6 8
6 2 3 6 4 10 5 1 7 9
5
3 2 4 1 5
2 4 5 1 3
7
2 2 6 4 1 3 5
3 1 6 5 1 4 2
5
4 1 3 2 5
3 2 1 5 4
OutputCopy
3
3
0
4
3
5
6
4
5
2
Note
In the first test case, we can do the following:

We will choose not to remove any index.
Choose index 3
, and set 𝑎3:=𝑏4
. The arrays become: 𝑎=[1,3,2,4]
, 𝑏=[4,3,2,2]
.
Choose index 1
, and set 𝑎1:=𝑏2
. The arrays become: 𝑎=[3,3,2,4]
, 𝑏=[4,3,2,2]
.
Choose index 1
, and set 𝑏1:=𝑎2
. The arrays become: 𝑎=[3,3,2,4]
, 𝑏=[3,3,2,2]
. Notice that you can perform 𝑎𝑖:=𝑏𝑖+1
 and 𝑏𝑖:=𝑎𝑖+1
 on the same index 𝑖
.
The number of matches is 3
. It can be shown that this is the maximum answer we can achieve.

In the second test case, we can do the following to achieve a maximum of 3
:

Let's choose to remove index 5
. The arrays become: 𝑎=[2,1,5,3,4]
, 𝑏=[3,2,4,5,6]
.
Choose index 4
, and set 𝑏4:=𝑎5
. The arrays become: 𝑎=[2,1,5,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 3
, and set 𝑎3:=𝑏4
. The arrays become: 𝑎=[2,1,4,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 2
, and set 𝑎2:=𝑏3
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[3,2,4,4,6]
.
Choose index 1
, and set 𝑏1:=𝑎2
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[4,2,4,4,6]
.
Choose index 2
, and set 𝑏2:=𝑎3
. The arrays become: 𝑎=[2,4,4,3,4]
, 𝑏=[4,4,4,4,6]
.
Choose index 1
, and set 𝑎1:=𝑏2
. The arrays become: 𝑎=[4,4,4,3,4]
, 𝑏=[4,4,4,4,6]
.
In the third test case, it can be shown that we can not get any matches.
Therefore, the answer is 0
.



*/
/* You can remove any index (or none) from both arrays.

For any index i (1 ≤ i ≤ n-1), you can set a[i] = b[i+1] or b[i] = a[i+1] (and
repeat as many times as you want).

After all operations, you want to maximize the number of positions where a[j] ==
b[j].

*/

/*Compute the initial number of matches.

For each index i, if a[i] == b[i], removing i reduces the match count by 1,
otherwise it doesn't.

So, the answer is max(matches, matches - 1 + 1) = matches (if you remove a
match, you lose one; if you remove a mismatch, matches stay the same).


----
For each i, count the number of matches after removing i.

For each i, matches = total_matches - (a[i] == b[i]) + (a[i+1] == b[i+1]) (if
i+1 < n).

But that's not correct for all cases. The best way is:

For each i, remove index i, then count matches in the new arrays.


*/

#include <iostream>
#include <vector>
using namespace std;

int maxMatches(vector<int> a, vector<int> b) {
  int n = a.size();
  int max_match = 0;
  // Try removing each index i
  for (int rem = 0; rem < n; ++rem) {
    int match = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      if (i == rem)
        continue;
      if (a[i] == b[i])
        match++;
    }
    max_match = max(max_match, match);
  }
  return max_match;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    cout << maxMatches(a, b) << endl;
  }
  return 0;
}
