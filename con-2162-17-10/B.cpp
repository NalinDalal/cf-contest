/*B. Beautiful String
time limit per test1 second
memory limit per test256 megabytes
You are given a binary∗
 string 𝑠
 of length 𝑛
.

Your task is to find any subsequence†
 𝑝
 of 𝑠
 such that:

The subsequence 𝑝
 is non-decreasing.
Let 𝑥
 denote the string obtained by removing all characters of 𝑝
 from 𝑠
, while preserving the order of the remaining characters. Then 𝑥
 must be a palindrome‡
.
You only need to output any valid subsequence 𝑝
 that satisfies both conditions. If no such subsequence exists, output −1
.

Note that an empty string is both non-decreasing and a palindrome.

∗
A binary string is a string consisting of characters '0' and '1'.

†
A subsequence of a string 𝑠=𝑠1𝑠2…𝑠𝑛
 is a sequence 𝑝=𝑠𝑖1𝑠𝑖2…𝑠𝑖𝑘
 such that 1≤𝑖1<𝑖2<…<𝑖𝑘≤𝑛
. The characters are selected in order, but not necessarily contiguously. Note
that an empty string is a subsequence of any string.

‡
A string 𝑡=𝑡1𝑡2…𝑡𝑚
 is a palindrome if 𝑡𝑖=𝑡𝑚−𝑖+1
 for all 1≤𝑖≤𝑚
. In other words, the string reads the same forward and backward.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤3000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤10
) — the length of the string.

The second line contains a binary string 𝑠
 of length 𝑛
.

Output
If a solution exists:

On the first line, print a single integer 𝑘
 (0≤𝑘≤𝑛
) — the length of the subsequence 𝑝
.
On the second line, print 𝑘
 distinct integers 𝑖1,𝑖2,…,𝑖𝑘
 (1≤𝑖1<𝑖2<⋯<𝑖𝑘≤𝑛
) — the indices of the characters in 𝑠
 that form 𝑝
 (in order as they appear in 𝑠
).
Otherwise, print a single line containing −1
.

Example
InputCopy
5
3
010
3
001
5
00111
8
11010011
6
100101
OutputCopy
0

2
2 3
5
1 2 3 4 5
2
3 4
2
5 6
Note
In the first test case, we remove an empty string, resulting in 𝑥=𝟶𝟷𝟶
, which is a palindrome.

In the second test case, we remove 𝑝=𝟶𝟷
 (indices 2
, 3
), resulting in 𝑥=𝟶
, which is a palindrome.

In the third test case, we remove 𝑝=𝟶𝟶𝟷𝟷𝟷
 (indices 1
 to 5
), resulting in an empty string, which is trivially a palindrome.

In the fourth test case, we remove 𝑝=𝟶𝟷
 (indices 3
, 4
), resulting in 𝑥=𝟷𝟷𝟶𝟶𝟷𝟷
, which is a palindrome.

In the fifth test case, we remove 𝑝=𝟶𝟷
 (indices 5
, 6
), resulting in 𝑥=𝟷𝟶𝟶𝟷
, which is a palindrome.
*/

/*solution:
 p is subseq of s
 p is non-decreasing
 let x be a string obtained after removing p from s
 x must be palindrome

//if solution exists then print length of subsequence p which is k and next line
k distinct integer which are
//indices of char from s that form p
//p[i]<p[i+1]


vector<int> p;

cout<<p.length()<<endl;
//k distinct int - indices of char in s that form p

requires a backtracking or dynamic programming approach combining:

Palindrome checking of the leftover string after removal.

Building the non-decreasing subsequence p.

Iterate over possible subsequences p to find if leftover x is palindrome.

Because brute force over all subsequences is exponential, use a two-pointer
technique to check for the leftover palindrome while choosing p greedily or
using DP.

Use a recursive or iterative search with memoization:

Try to include or exclude characters in p.

Track indices of p, characters in sorted order.

Check leftover palindrome condition efficiently by two pointers.



*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, vector<bool> &removed) {
  int left = 0, right = (int)s.size() - 1;
  while (left < right) {
    if (removed[left]) {
      left++;
      continue;
    }
    if (removed[right]) {
      right--;
      continue;
    }
    if (s[left] != s[right])
      return false;
    left++;
    right--;
  }
  return true;
}

bool solve(int pos, char lastChar, string &s, vector<int> &currentP,
           vector<bool> &removed, vector<int> &bestP) {
  if (pos == (int)s.size()) {
    if (isPalindrome(s, removed)) {
      // Update best solution if found and it's better (longer p)
      if (currentP.size() > bestP.size()) {
        bestP = currentP;
      }
      return true;
    }
    return false;
  }

  bool found = false;

  // Option 1: Include s[pos] in p if it is >= last character in p to keep
  // non-decreasing
  if (s[pos] >= lastChar) {
    removed[pos] = true;
    currentP.push_back(pos + 1); // store 1-based index
    found |= solve(pos + 1, s[pos], s, currentP, removed, bestP);
    currentP.pop_back();
    removed[pos] = false;
  }

  // Option 2: Exclude s[pos] from p
  found |= solve(pos + 1, lastChar, s, currentP, removed, bestP);

  return found;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> currentP, bestP;
    vector<bool> removed(n, false);

    if (solve(0, char(0), s, currentP, removed, bestP)) {
      cout << (int)bestP.size() << "\n";
      for (int idx : bestP)
        cout << idx << " ";
      cout << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
