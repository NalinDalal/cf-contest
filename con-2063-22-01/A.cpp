/* https://codeforces.com/contest/2063/problem/A
A. Minimal Coprime
time limit per test1 second
memory limit per test256 megabytes
Today, Little John used all his savings to buy a segment. He wants to build a
house on this segment. A segment of positive integers [𝑙,𝑟] is called coprime if
𝑙 and 𝑟 are coprime∗
.

A coprime segment [𝑙,𝑟]
 is called minimal coprime if it does not contain†
 any coprime segment not equal to itself. To better understand this statement,
you can refer to the notes.

Given [𝑙,𝑟]
, a segment of positive integers, find the number of minimal coprime segments
contained in [𝑙,𝑟]
.

∗
Two integers 𝑎
 and 𝑏
 are coprime if they share only one positive common divisor. For example, the
numbers 2 and 4 are not coprime because they are both divided by 2 and 1 , but
the numbers 7 and 9 are coprime because their only positive common divisor is 1
.

†
A segment [𝑙′,𝑟′]
 is contained in the segment [𝑙,𝑟]
 if and only if 𝑙≤𝑙′≤𝑟′≤𝑟
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The only line of each test case consists of two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤109
).

Output
For each test case, output the number of minimal coprime segments contained in
[𝑙,𝑟] , on a separate line.

Example
InputCopy
6
1 2
1 10
49 49
69 420
1 1
9982 44353
OutputCopy
1
9
0
351
1
34371
Note
On the first test case, the given segment is [1,2]
. The segments contained in [1,2]
 are as follows.

[1,1]
: This segment is coprime, since the numbers 1
 and 1
 are coprime, and this segment does not contain any other segment inside. Thus,
[1,1] is minimal coprime. [1,2] : This segment is coprime. However, as it
contains [1,1] , which is also coprime, [1,2] is not minimal coprime. [2,2] :
This segment is not coprime because 2 and 2 share 2 positive common divisors: 1
 and 2
.
Therefore, the segment [1,2]
 contains 1
 minimal coprime segment.*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Function to calculate the number of minimal coprime segments in a range [l,
// r]
long long countMinimalCoprimeSegments(long long l, long long r) {
  long long count = 0;
  for (long long i = l; i <= r; ++i) {
    for (long long j = i; j <= r; ++j) {
      if (__gcd(i, j) == 1) {
        ++count;
        break; // Once [i, j] is coprime, no need to check further for this i
      }
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  vector<long long> results;

  while (t--) {
    long long l, r;
    cin >> l >> r;
    results.push_back(countMinimalCoprimeSegments(l, r));
  }

  for (const auto &result : results) {
    cout << result << "\n";
  }

  return 0;
}
