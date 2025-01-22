/* https://codeforces.com/contest/2063/problem/B

B. Subsequence Update
time limit per test1.5 seconds
memory limit per test256 megabytes

After Little John borrowed expansion screws from auntie a few hundred times,
eventually she decided to come and take back the unused ones. But as they are a
crucial part of home design, Little John decides to hide some in the most
unreachable places — under the eco-friendly wood veneers.

You are given an integer sequence 𝑎1,𝑎2,…,𝑎𝑛
, and a segment [𝑙,𝑟]
 (1≤𝑙≤𝑟≤𝑛
).

You must perform the following operation on the sequence exactly once.

Choose any subsequence∗
 of the sequence 𝑎
, and reverse it. Note that the subsequence does not have to be contiguous.
Formally, choose any number of indices 𝑖1,𝑖2,…,𝑖𝑘
 such that 1≤𝑖1<𝑖2<…<𝑖𝑘≤𝑛
. Then, change the 𝑖𝑥
-th element to the original value of the 𝑖𝑘−𝑥+1
-th element simultaneously for all 1≤𝑥≤𝑘
.

Find the minimum value of 𝑎𝑙+𝑎𝑙+1+…+𝑎𝑟−1+𝑎𝑟
 after performing the operation.

∗
A sequence 𝑏
 is a subsequence of a sequence 𝑎
 if 𝑏
 can be obtained from 𝑎
 by the deletion of several (possibly, zero or all) element from arbitrary
positions.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains three integers 𝑛
, 𝑙
, 𝑟
 (1≤𝑙≤𝑟≤𝑛≤105
) — the length of 𝑎
, and the segment [𝑙,𝑟]
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output the minimum value of 𝑎𝑙+𝑎𝑙+1+…+𝑎𝑟−1+𝑎𝑟
 on a separate line.

Example
InputCopy
6
2 1 1
2 1
3 2 3
1 2 3
3 1 3
3 1 2
4 2 3
1 2 2 2
5 2 5
3 3 2 3 5
6 1 3
3 6 6 4 3 2
OutputCopy
1
3
6
3
11
8
Note
On the second test case, the array is 𝑎=[1,2,3]
 and the segment is [2,3]
.

After choosing the subsequence 𝑎1,𝑎3
 and reversing it, the sequence becomes [3,2,1]
. Then, the sum 𝑎2+𝑎3
 becomes 3
. It can be shown that the minimum possible value of the sum is 3
.


*/
