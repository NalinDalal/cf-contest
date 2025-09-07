/*B. Fun Permutation
time limit per test2 seconds
memory limit per test256 megabytes

You are given a permutation∗
 𝑝
 of size 𝑛
.

Your task is to find a permutation 𝑞
 of size 𝑛
 such that GCD
†
(𝑝𝑖+𝑞𝑖,𝑝𝑖+1+𝑞𝑖+1)≥3
 for all 1≤𝑖<𝑛
. In other words, the greatest common divisor of the sum of any two adjacent
positions should be at least 3
.

It can be shown that this is always possible.

∗
A permutation of length 𝑚
 is an array consisting of 𝑚
 distinct integers from 1
 to 𝑚
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑚=3
 but there is 4
 in the array).

†
gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
).

It is guaranteed that the given array forms a permutation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the permutation 𝑞
 on a new line. If there are multiple possible answers, you may output any.

Example
InputCopy
3
3
1 3 2
5
5 1 2 4 3
7
6 7 1 5 4 3 2
OutputCopy
2 3 1
4 5 1 2 3
2 1 3 7 5 6 4
Note
In the first test case, GCD(1+2,3+3)=3≥3
 and GCD(3+3,2+1)=3≥3
, so the output is correct.
*/

#include <bits/stdc++.h>
using namespace std;
/*p vector given
 find a q vector duch that
 gcd(p[i]+q[i],p[i+1]+q[i+1])>=3 for 1<=i<=n
output q

well we found that if gcd>=3
then a-b is divisible by d>=3
a−b≡0(mod gcd(a,b))
we need q[i] to have remainder (-p[i]) % 3 when divided by 3, so that p[i] +
q[i] ≡ 0 (mod 3)

Separate numbers 1 to n into three groups based on their remainder mod 3

For each position, assign the next available number from the appropriate group

Print the resulting permutation

construct a permutation q such that adjacent sums have GCD ≥ 3.

but q[i] is distinct and q[i]<=q.size()
*/
