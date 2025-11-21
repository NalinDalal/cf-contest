/*B. Yuu Koito and Minimum Absolute Sum
time limit per test2 seconds
memory limit per test256 megabytes
The words in shoujo manga and love songs... they're always sparkling brightly. I
don't need a dictionary to understand the meaning... but I've never felt them
for myself. — Yuu Koito Yuu is trying out the student council! Unfortunately,
she is being forced to do clerical work... Touko wants her to fill out the
blanks in various student council documents.

You are given a partially filled array of nonnegative integers 𝑎1,𝑎2,…,𝑎𝑛
, where blank elements are denoted with −1
. You would like to fill in the blank elements with nonnegative integers, such
that the absolute value of the sum of the elements in its difference array is
minimized.

More formally, let 𝑏
 be the array of length 𝑛−1
 such that 𝑏𝑖=𝑎𝑖+1−𝑎𝑖
 for all 1≤𝑖≤𝑛−1
. Find the minimum possible value of |𝑏1+𝑏2+⋯+𝑏𝑛−1|
, across all possible ways to fill in the blank elements of 𝑎
.

Additionally, output the array that achieves this minimum. If there are multiple
such arrays, output the one that is lexicographically smallest∗
.

∗
For two arbitrary arrays 𝑐
 and 𝑑
 of length 𝑛
, we say that 𝑐
 is lexicographically smaller than 𝑑
 if there exists an index 𝑖
 (1≤𝑖≤𝑛
) such that 𝑐𝑗=𝑑𝑗
 for all 𝑗<𝑖
, and 𝑐𝑖<𝑑𝑖
. In other words, 𝑐
 and 𝑑
 differ in at least one index, and at the first index at which they differ, 𝑐𝑖
 is smaller than 𝑑𝑖
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers, 𝑎1,𝑎2,…,𝑎𝑛
 (−1≤𝑎𝑖≤106
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, on the first line, output the minimum possible value of
|𝑏1+𝑏2+⋯+𝑏𝑛−1| . Then, on the second line, output 𝑛 integers, the values of
𝑎1,𝑎2,…,𝑎𝑛 in the lexicographically smallest array achieving this minimum.

Example
InputCopy
6
4
2 -1 7 1
4
-1 2 4 -1
8
2 -1 1 5 11 12 1 -1
3
-1 -1 -1
3
2 5 4
2
-1 5
OutputCopy
1
2 0 7 1
0
0 2 4 0
0
2 0 1 5 11 12 1 2
0
0 0 0
2
2 5 4
0
5 5
Note
In the first example, we fill in the array 𝑎=[2,0,7,1]
, which yields the difference array 𝑏=[−2,7,−6]
.

The absolute value of the sum of the elements in 𝑏
 is 1
. It can be proven that this is the minimum possible. Furthermore, it can be
proven that this is the lexicographically smallest array 𝑎 that achieves this
minimum.
*/

/* b[i]=a[i+1]-a[i]
 sum of diff array=b1+b2+b3....+bn=a[n]-a[1]
 minimize |an − a1|

 if(a1,an given){
 cost = |an − a1|
 }else if(one is known, other is -1){
 an=a1;
 cost=0
 }else if(a1=-1 && an==-1){
 a1 = 0
an = 0

 }
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

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long a1 = a[0], an = a[n - 1];
    long long cost;

    // Case analysis:
    if (a1 != -1 && an != -1) {
      // Both known
      cost = llabs(an - a1);
    } else if (a1 == -1 && an == -1) {
      // Both missing -> make them 0
      a1 = an = 0;
      a[0] = 0;
      a[n - 1] = 0;
      cost = 0;
    } else if (a1 == -1 && an != -1) {
      // a1 missing → match an
      a1 = an;
      a[0] = an;
      cost = 0;
    } else {
      // a1 known, an missing → match a1
      an = a1;
      a[n - 1] = a1;
      cost = 0;
    }

    // Fill internal -1s with 0 (lexicographically smallest)
    for (int i = 1; i < n - 1; i++) {
      if (a[i] == -1)
        a[i] = 0;
    }

    // Output
    cout << cost << "\n";
    for (int i = 0; i < n; i++) {
      cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
  }
}

// sub: https://codeforces.com/contest/2171/submission/349911191
