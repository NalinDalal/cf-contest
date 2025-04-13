/* B. Bobritto Bandito
time limit per test1 second
memory limit per test256 megabytes
In Bobritto Bandito's home town of residence, there are an infinite number of
houses on an infinite number line, with houses at …,−2,−1,0,1,2,… . On day 0 ,
he started a plague by giving an infection to the unfortunate residents of house
0 . Each succeeding day, the plague spreads to exactly one healthy household
that is next to an infected household. It can be shown that each day the
infected houses form a continuous segment.

Let the segment starting at the 𝑙
-th house and ending at the 𝑟
-th house be denoted as [𝑙,𝑟]
. You know that after 𝑛
 days, the segment [𝑙,𝑟]
 became infected. Find any such segment [𝑙′,𝑟′]
 that could have been infected on the 𝑚
-th day (𝑚≤𝑛
).

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) – the number of independent test cases.

The only line of each test case contains four integers 𝑛
, 𝑚
, 𝑙
, and 𝑟
 (1≤𝑚≤𝑛≤2000,−𝑛≤𝑙≤0≤𝑟≤𝑛,𝑟−𝑙=𝑛
).

Output
For each test case, output two integers 𝑙′
 and 𝑟′
 on a new line. If there are multiple solutions, output any.

Example
InputCopy
4
4 2 -2 2
4 1 0 4
3 3 -1 2
9 8 -6 3
OutputCopy
-1 1
0 1
-1 2
-5 3
Note
In the first test case, it is possible that on the 1
-st, 2
-nd, and 3
-rd days the interval of houses affected is [−1,0]
, [−1,1]
, [−2,1]
. Therefore, [−1,1]
 is a valid output.*/
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    // Ensure 0 is inside the new segment
    int l_prime = max(l, 0 - m);
    int r_prime = l_prime + m;

    cout << l_prime << " " << r_prime << endl;
  }
  return 0;
}

// sub: https://codeforces.com/contest/2094/submission/315381814
