/*C1. The Cunning Seller (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the easy version of the problem. The easy version differs from the hard
one in that it requires determining the minimum cost with the least number of
deals, while the hard version requires determining the minimum cost with a
limited number of deals.

After the cunning seller sold three watermelons instead of one, he decided to
increase his profit — namely, he bought even more watermelons. Now he can sell
3𝑥 watermelons for 3𝑥+1+𝑥⋅3𝑥−1 coins, where 𝑥 is a non-negative integer. Such a
sale is called a deal.

A calculating buyer came to him, but he has critically little time. Because of
this, he wants to buy exactly 𝑛 watermelons, making the least possible number of
deals.

The buyer is in a hurry and has therefore turned to you to determine the minimum
number of coins he must pay the seller for 𝑛 watermelons, considering that he
will make the least possible number of deals.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of each test case follows.

In a single line of each test case, there is one integer 𝑛
 (1≤𝑛≤109)
 — how many watermelons need to be bought.

Output
For each test case, output a single integer — the minimum cost of the
watermelons.

Example
InputCopy
7
1
3
8
2
10
20
260010000
OutputCopy
3
10
26
6
36
72
2250964728
Note
Note that there is no point in buying more watermelons than needed, so we won't
consider deals where there are more watermelons than necessary.

Let's consider the costs of the first two deal options:

Deal A: 1
 watermelon — 3
 coins.

Deal B: 3
 watermelons — 10
 coins.

In the first sample, the only way to buy 1
 watermelon is to use Deal A, so the answer is 3
.

In the second sample, you can buy 3
 watermelons with a single Deal B for 10
 coins.

In the third sample, you can make 2
 Deals A and 2
 Deals B, which will cost a total of 26
 coins. If we make 3
 deals, we can get 3
, 5
, 7
, or 9
 watermelons. If we make fewer than 3
 deals, we will get no more than 6
 watermelons, which means it is impossible to buy 8
 watermelons for less than 4
 deals.
*/

/*given x
deal:
    - watermelons: pow(3,x)
    - coins: pow(3,x+1)+x*pow(3,x-1)

to buy n watermelon
minimize no of deals

Convert n to base 3.

If there’s a 2, carry to next digit until digits are only 0/1.

The set of 1 positions corresponds to which deals to take.

Compute total cost as sum of deal(x) for each chosen x.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Precompute deals up to x=20
  const int MAXX = 20;
  vector<long long> qty(MAXX), cost(MAXX);
  for (int x = 0; x < MAXX; x++) {
    long long q = 1;
    for (int i = 0; i < x; i++)
      q *= 3;
    qty[x] = q;
    if (x == 0)
      cost[x] = 3;
    else
      cost[x] = (long long)pow(3, x + 1) + x * (long long)pow(3, x - 1);
  }

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (int x = 0; n > 0; x++) {
      int d = n % 3;
      ans += 1LL * d * cost[x];
      n /= 3;
    }
    cout << ans << "\n";
  }
}

// sub: https://codeforces.com/contest/2132/submission/334887538
