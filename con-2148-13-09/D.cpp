/*D. Destruction of the Dandelion Fields
time limit per test2 seconds
memory limit per test256 megabytes
Farmer John has a lawnmower, initially turned off. He also has 𝑛
 fields, with the 𝑖
-th field having 𝑎𝑖
 dandelions. He will visit all the fields in any order he wants, and each field
exactly once.

FJ's lawnmower seems to have a mind of its own. Right before visiting a field,
it checks if the field has an even or odd number of dandelions. If it has an odd
number, then the lawnmower toggles its state (if it is off, it turns on; if it
is on, it turns off). Then, if the lawnmower is on, it will cut all dandelions
in that field. Otherwise, if the lawnmower is off, then FJ will simply visit the
field and cut no dandelions.

If FJ visits the 𝑛
 fields in optimal order, what is the maximum total number of dandelions he can
cut?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of fields.

The following line contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the number of dandelions in each field.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer on a new line: maximum dandelions FJ can
cut if he visits all 𝑛 fields in optimal order.

Example
InputCopy
3
3
2 4 6
4
4 2 1 6
4
1000000000 999999999 1000000000 999999999
OutputCopy
0
13
2999999999
Note
For the first test case, since there is no field with an odd number of
dandelions, FJ can never turn his lawnmower on. Since his lawnmower is always
off, he can never cut any dandelions, so the answer is 0
.

For the second test case, FJ can visit the third field first; then his lawnmower
will turn on. Then he can visit the other fields in any order. Since his
lawnmower is always on, dandelions in every field can be cut.

For the third test case, FJ can visit the fields in the following order: field 2
, field 1
, field 3
, then field 4
.
*/
/*(t--){
    n,a[i]
    state=0,ans=0
    for(i=0 to n){
        if(a[i]%2)state=1
        else state=0

        if(state==0)move on
        else {cout all, ans+=a[i]}
    }
    cout<<ans<<endl;
  }
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  if (!(cin >> t))
    return 0;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> odds;
    ll sumE = 0;
    for (int i = 0; i < n; ++i) {
      ll a;
      cin >> a;
      if (a % 2 == 0)
        sumE += a;
      else
        odds.push_back(a);
    }

    if (odds.empty()) {
      cout << 0 << '\n';
      continue;
    }

    sort(odds.begin(), odds.end(), greater<ll>());

    int k = ((int)odds.size() + 1) / 2; // ceil
    ll sumOdds = 0;
    for (int i = 0; i < k; ++i)
      sumOdds += odds[i];

    cout << (sumE + sumOdds) << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/contest/2148/submission/338431772
