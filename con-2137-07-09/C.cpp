/*C. Maximum Even Sum
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integers 𝑎
 and 𝑏
. You are to perform the following procedure:

First, you choose an integer 𝑘
 such that 𝑏
 is divisible by 𝑘
. Then, you simultaneously multiply 𝑎
 by 𝑘
 and divide 𝑏
 by 𝑘
.

Find the greatest possible even value of 𝑎+𝑏
. If it is impossible to make 𝑎+𝑏
 even, output −1
 instead.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤𝑎⋅𝑏≤1018)
.

Output
For each test case, output the maximum even value of 𝑎+𝑏
 on a new line.

Example
InputCopy
7
8 1
1 8
7 7
2 6
9 16
1 6
4 6
OutputCopy
-1
6
50
8
74
-1
14
Note
In the first test case, it can be shown it is impossible for 𝑎+𝑏
 to be even.

In the second test case, the optimal 𝑘
 is 2
. The sum is 2+4=6
.
*/

/*given a,b
 * k such that b%k==0
 * a=a*k
 * b=b/k
 * ans= greatest possible even value of a+b
 * else ans=-1
 */
/*a,b given. b is divisible by k i.e. b%k==0 => a=a*k,b=b/k

if((a+b)%2)cout<<-1<<endl;
else cout<<a+b<<endl;
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long a, b;
    cin >> a >> b;

    long long ans = -1;

    for (long long k = 1; k * k <= b; k++) {
      if (b % k == 0) {
        long long sum1 = a * k + b / k;
        if (sum1 & 1 ^ 1)
          ans = max(ans, sum1); // Check if even using bitwise

        if (k != b / k) {
          long long sum2 = a * (b / k) + k;
          if (sum2 & 1 ^ 1)
            ans = max(ans, sum2);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
