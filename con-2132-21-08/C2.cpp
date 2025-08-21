/*C2. The Cunning Seller (hard version)
time limit per test2 seconds
memory limit per test256 megabytes
This is the hard version of the problem. The easy version differs from the hard
one in that it requires determining the minimum cost with the least number of
deals, while the hard version requires determining the minimum cost with a
limited number of deals.

After the cunning seller sold three watermelons instead of one, he decided to
increase his profit — namely, he bought even more watermelons. Now he can sell
3𝑥 watermelons for 3𝑥+1+𝑥⋅3𝑥−1 coins, where 𝑥 is a non-negative integer. Such a
sale is called a deal.

A calculating buyer came to him, but he has little time, so the buyer can make
no more than 𝑘 deals and plans to buy exactly 𝑛 watermelons.

The buyer is in a hurry and has therefore turned to you to determine the minimum
number of coins he must pay the seller for 𝑛 watermelons if he makes no more
than 𝑘 deals. If it is impossible to buy exactly 𝑛 watermelons while making no
more than 𝑘 deals, output −1
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of each test case follows.

In a single line of each test case, there are two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤109)
 — how many watermelons need to be bought and how many deals can be made.

Output
For each test case, output a single integer — the minimum cost of the
watermelons or −1 if it is impossible to buy the watermelons while meeting all
the conditions.

Example
InputCopy
8
1 1
3 3
8 3
2 4
10 10
20 14
3 2
9 1
OutputCopy
3
9
-1
6
30
63
10
33
Note
Note that there is no point in buying more watermelons than needed, so we will
not consider deals where there are more watermelons than necessary.

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
 watermelons either with Deal B for 10
 coins or with three Deal A for 9
 coins, so the answer is 9
.

In the third sample, there are the following options for 3
 deals:

3
 Deals A — 3
 watermelons.

2
 Deals A and 1
 Deal B — 5
 watermelons.

1
 Deal A and 2
 Deals B — 7
 watermelons.

3
 Deals B — 9
 watermelons.

It can be seen that it is impossible to buy exactly 8 watermelons.
*/

/* 1. if n>k*pow(3,19) -> impossible
  2. Start with all 1’s → cost = 3n, deals = n.
  3. while(deals>k){
    Replace 3 small blocks by 1 bigger block.

Increase cost by (cost(big) - 3×cost(small)).

Decrease deal count by 2.

Always compress the largest possible (cheapest increase).
  }


For each test case (n, k):

1. Convert n to base-3.
Let minDeals = sum of base-3 digits.
If minDeals > k → print -1.

2. Else:
    - Start with n written as powers of 3 (greedy largest-first).
    - If number of deals ≤ k → compute cost directly.
    - If less than k, we can split some large deals into smaller ones, but cost
will only increase. Since we only need ≤ k, best is exact decomposition without
unnecessary splitting.

3. Compute total cost as sum of cost(x) for each used 3^x.
*/

/*Find minimum deals needed (sum of base-3 digits)
If this exceeds k, return -1
Calculate initial cost using optimal base-3 representation
Iteratively try to split expensive deals into cheaper combinations if we have
spare deal capacity Return the minimized total cost
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  // Precompute powers of 3 and deal costs up to a reasonable limit
  vector<ll> power3(40, 1);
  vector<ll> dealCost(40);

  for (int i = 1; i < 40; i++) {
    power3[i] = power3[i - 1] * 3;
    if (power3[i] > 2e18)
      break; // prevent overflow
  }

  for (int i = 0; i < 40; i++) {
    ll p = power3[i];
    ll p_next = (i < 39) ? power3[i + 1] : p * 3;
    ll p_prev = (i == 0) ? 0 : power3[i - 1];
    dealCost[i] = p_next + (ll)i * p_prev;
  }

  while (t--) {
    ll n, k;
    cin >> n >> k;

    // Convert n to base 3 to find minimum deals needed
    vector<int> digits;
    ll temp = n;
    while (temp > 0) {
      digits.push_back(temp % 3);
      temp /= 3;
    }

    // Calculate minimum deals needed
    int minDeals = 0;
    for (int d : digits) {
      minDeals += d;
    }

    if (minDeals > k) {
      cout << -1 << "\n";
      continue;
    }

    // Key insight: if we have extra deals, we should split from the highest
    // position where splitting reduces cost per watermelon

    ll totalCost = 0;
    int dealsUsed = minDeals;

    // Calculate base cost
    for (int i = 0; i < digits.size(); i++) {
      totalCost += (ll)digits[i] * dealCost[i];
    }

    // Only try to optimize if we have significantly more deals available
    // and if splitting could help (only check a few top levels)
    for (int i = min(20, (int)digits.size() - 1); i >= 1 && dealsUsed < k;
         i--) {
      if (digits[i] > 0) {
        // Check if splitting deal i into 3 deals of type (i-1) is beneficial
        ll currentCost = dealCost[i];
        ll splitCost = 3 * dealCost[i - 1];

        if (splitCost < currentCost) {
          // Calculate how many times we can split
          ll maxSplits = min((ll)digits[i], (k - dealsUsed) / 2);

          if (maxSplits > 0) {
            digits[i] -= maxSplits;
            digits[i - 1] += 3 * maxSplits;
            totalCost += maxSplits * (splitCost - currentCost);
            dealsUsed += 2 * maxSplits;
          }
        }
      }
    }

    cout << totalCost << "\n";
  }

  return 0;
}
// sub:https://codeforces.com/contest/2132/submission/334899480
