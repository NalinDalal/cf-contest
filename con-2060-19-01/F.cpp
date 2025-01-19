/* https://codeforces.com/contest/2060/problem/F

F. Multiplicative Arrays
time limit per test4 seconds
memory limit per test512 megabytes
You're given integers 𝑘
 and 𝑛
. For each integer 𝑥
 from 1
 to 𝑘
, count the number of integer arrays 𝑎
 such that all of the following are satisfied:

1≤|𝑎|≤𝑛
 where |𝑎|
 represents the length of 𝑎
.
1≤𝑎𝑖≤𝑘
 for all 1≤𝑖≤|𝑎|
.
𝑎1×𝑎2×⋯×𝑎|𝑎|=𝑥
 (i.e., the product of all elements is 𝑥
).
Note that two arrays 𝑏
 and 𝑐
 are different if either their lengths are different, or if there exists an
index 1≤𝑖≤|𝑏| such that 𝑏𝑖≠𝑐𝑖
.

Output the answer modulo 998244353
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤103
) — the number of independent test cases.

The only line of each test case contains two integers 𝑘
 and 𝑛
 (1≤𝑘≤105,1≤𝑛≤9⋅108
).

It is guaranteed that the sum of 𝑘
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑘
 space-separated integers on a new line: the number of arrays for 𝑥=1,2,…,𝑘
, modulo 998244353
.

Example
InputCopy
3
2 2
4 3
10 6969420
OutputCopy
2 3
3 6 6 10
6969420 124188773 124188773 729965558 124188773 337497990 124188773 50981194
729965558 337497990 Note In the first test case, there are 2 arrays 𝑎 with |𝑎|≤2
 and the product of elements equal to 1
:

[1]
[1,1]
There are 3
 arrays 𝑎
 with |𝑎|≤2
 and the product of elements equal to 2
:

[2]
[1,2]
[2,1]

*/
