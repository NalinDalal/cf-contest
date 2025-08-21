/*D. From 1 to Infinity
time limit per test1.5 seconds
memory limit per test256 megabytes
Vadim wanted to understand the infinite sequence of digits that consists of the
positive integers written consecutively from 1 to infinity. That is, this
sequence looks like 123456789101112131415…

To avoid looking into infinity, Vadim cut this sequence at the 𝑘
-th digit and discarded everything after it. Thus, exactly 𝑘
 digits remained in the sequence. Help him find the sum of the digits in the
remaining sequence.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. The following lines describe
the test cases.

In a single line of each test case, there is an integer 𝑘
 — the number of digits in the remaining sequence (1≤𝑘≤1015)
.

Output
For each given 𝑘
, output the sum of the digits in the sequence of length 𝑘
.

Example
InputCopy
6
5
10
13
29
1000000000
1000000000000000
OutputCopy
15
46
48
100
4366712386
4441049382716054
Note
In the first sample, the remaining sequence will be 12345
.

In the second sample, the remaining sequence will be 1234567891
.

In the third sample, the remaining sequence will be 1234567891011
.

*/

/* tle
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        string s;
            //k=5->12345
            //k=10->1234567891, only length k is possible
            //k=13->1234567891011
for(int i = 1; (int)s.size() < k; i++){
            s += to_string(i);
        }

        // only take prefix of length k
        s = s.substr(0, k);

        long long sum = 0;
        for(char c : s){
            sum += c - '0';
        }
        cout << sum << "\n";
        //output the sum of the digits in the sequence of length k
    }
return 0;}
*/

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// precompute sum of digits for numbers < 10^k (all 9..9)
long long pow10[19], fullSum[19];

long long digitSum(long long n) {
  if (n <= 0)
    return 0;
  string s = to_string(n);
  int len = s.size();

  long long d = s[0] - '0';
  long long p = pow10[len - 1];
  long long rest = n % p;

  // sum of digits of numbers with smaller first digit
  long long res = d * fullSum[len - 1];
  // add sum for smaller leading digits (1..d-1)
  res += (d * (d - 1) / 2) * p;
  // add contribution of first digit d with remainder
  res += d * (rest + 1);
  // add recursively sum of rest
  res += digitSum(rest);
  return res;
}

long long solveOne(long long k) {
  long long len = 1, count = 9, digits = len * count;
  while (k > digits) {
    k -= digits;
    len++;
    count *= 10;
    digits = len * count;
  }
  long long index = (k - 1) / len;
  long long pos = (k - 1) % len;
  long long start = pow10[len - 1];
  long long number = start + index;

  long long fullBefore = digitSum(number - 1);

  string numStr = to_string(number);
  long long partial = 0;
  for (int i = 0; i <= pos; i++)
    partial += numStr[i] - '0';

  return fullBefore + partial;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pow10[0] = 1;
  for (int i = 1; i < 19; i++)
    pow10[i] = pow10[i - 1] * 10;
  fullSum[0] = 0;
  for (int i = 1; i < 19; i++)
    fullSum[i] = fullSum[i - 1] * 10 + 45 * pow10[i - 1];

  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    cout << solveOne(k) << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/contest/2132/submission/334907522
