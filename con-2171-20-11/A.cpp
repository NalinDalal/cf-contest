/*
A. Shizuku Hoshikawa and Farm Legs
time limit per test1 second
memory limit per test256 megabytes
Nothing's ever been the same since... that summer with her.
— Shizuku Hoshikawa
Kaori wants to spend the day with Shizuku! However, the zoo is closed, so they
are visiting Farmer John's farm instead.

At Farmer John's farm, Shizuku counts 𝑛
 legs. It is known that only chickens and cows live on the farm; a chicken has 2
 legs, while a cow has 4
.

Count how many different configurations of Farmer John's farm are possible. Two
configurations are considered different if they contain either a different
number of chickens, a different number of cows, or both.

Note that Farmer John's farm may contain zero chickens or zero cows.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
)  — the number of test cases.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
).

Output
For each test case, output a single integer, the number of different
configurations of Farmer John's farm that are possible.

Example
InputCopy
5
2
3
4
6
100
OutputCopy
1
0
2
2
26
Note
For 𝑛=4
, there are two possible configurations of Farmer John's farm:

he can have two chickens and zero cows, or
he can have zero chickens and one cow.
It can be shown that these are the only possible configurations of Farmer John's
farm. For 𝑛=3 , it can be shown that there are no possible configurations of
Farmer John's farm.

*/
/*n=2 so 1 possiblity
 * when n is odd it will be of no use, cause both cows and chicken have even no
 * of legs
 * c= chicken=> 2c legs, w=cows=> 4w legs
 * 2c+4w=n
 * n/2=c+2w
 * c=k-2w
 * => k − 2w ≥ 0
w ≤ k/2

w = 0, 1, 2, ..., floor(k/2)


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans;
    if (n % 2) {
      ans = 0;
    } else {
      int k = n / 2;
      ans = k / 2 + 1; // floor(k/2) + 1
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2171/submission/349889146
