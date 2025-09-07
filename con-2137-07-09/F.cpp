/*F. Prefix Maximum Invariance
time limit per test3 seconds
memory limit per test256 megabytes
Given two arrays 𝑥
 and 𝑦
 both of size 𝑚
, let 𝑧
 be another array of size 𝑚
 such that the prefix maximum at each position of 𝑧
 is the same as the prefix maximum at each position of 𝑥
. Formally, max(𝑥1,𝑥2,…,𝑥𝑖)=max(𝑧1,𝑧2,…,𝑧𝑖)
 should hold for all 1≤𝑖≤𝑚
. Define 𝑓(𝑥,𝑦)
 to be the maximum number of positions where 𝑧𝑖=𝑦𝑖
 over all possible arrays 𝑧
.

You are given two sequences of integers 𝑎
 and 𝑏
, both of size 𝑛
. Please find the value of ∑𝑛𝑙=1∑𝑛𝑟=𝑙𝑓([𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟],[𝑏𝑙,𝑏𝑙+1,…,𝑏𝑟])
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2⋅𝑛)
.

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2⋅𝑛)
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the sum of 𝑓([𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟],[𝑏𝑙,𝑏𝑙+1,…,𝑏𝑟])
 over all pairs of (𝑙,𝑟)
.

Example
InputCopy
6
3
5 3 1
4 2 1
5
1 2 3 4 5
1 2 3 4 5
6
7 1 12 10 5 8
9 2 4 3 6 5
1
1
2
6
5 1 2 6 3 4
3 1 6 5 2 4
2
2 2
1 1
OutputCopy
5
35
26
0
24
1
Note
In the first test case, the answer is the sum of the following:

𝑓([5],[4])=0
, using 𝑧=[5]
.
𝑓([3],[2])=0
, using 𝑧=[3]
.
𝑓([1],[1])=1
, using 𝑧=[1]
.
𝑓([5,3],[4,2])=1
, using 𝑧=[5,2]
.
𝑓([3,1],[2,1])=1
, using 𝑧=[3,1]
.
𝑓([5,3,1],[4,2,1])=2
, using 𝑧=[5,2,1]
.


*/
