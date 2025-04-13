/* E. Boneca Ambalabu
time limit per test2 seconds
memory limit per test256 megabytes
Boneca Ambalabu gives you a sequence of 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
.

Output the maximum value of (𝑎𝑘⊕𝑎1)+(𝑎𝑘⊕𝑎2)+…+(𝑎𝑘⊕𝑎𝑛)
 among all 1≤𝑘≤𝑛
. Note that ⊕
 denotes the bitwise XOR operation.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) – the number of independent test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) – the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖<230
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum value on a new line.

Example
InputCopy
5
3
18 18 18
5
1 2 4 8 16
5
8 13 4 5 15
6
625 676 729 784 841 900
1
1
OutputCopy
0
79
37
1555
0
Note
In the first test case, the best we can do is (18⊕18)+(18⊕18)+(18⊕18)=0
.

In the second test case, we choose 𝑘=5
 to get (16⊕1)+(16⊕2)+(16⊕4)+(16⊕8)+(16⊕16)=79
.*/
/* maximize the total XOR sum defined by:

∑
𝑖
=
1
𝑛
(
𝑎
𝑘
⊕
𝑎
𝑖
)
i=1
∑
n
​
 (a
k
​
 ⊕a
i
​
 )



*/

/*#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
      long long current_sum = 0;
      for (int j = 0; j < n; ++j) {
        current_sum += (a[i] ^ a[j]);
      }
      max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << "\n";
  }
  return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    // Precompute how many numbers have each bit set
    vector<int> bitCount(30, 0);
    for (int num : a) {
      for (int b = 0; b < 30; ++b) {
        if (num & (1 << b)) {
          bitCount[b]++;
        }
      }
    }

    long long maxXorSum = 0;
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int b = 0; b < 30; ++b) {
        if (a[i] & (1 << b)) {
          // This bit is 1 in a[i], will XOR to 1 with 0s
          sum += 1LL * (n - bitCount[b]) * (1 << b);
        } else {
          // This bit is 0 in a[i], will XOR to 1 with 1s
          sum += 1LL * bitCount[b] * (1 << b);
        }
      }
      maxXorSum = max(maxXorSum, sum);
    }

    cout << maxXorSum << '\n';
  }
  return 0;
}

// sub: https://codeforces.com/contest/2094/submission/315426863
