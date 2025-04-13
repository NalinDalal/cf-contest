/* H. La Vaca Saturno Saturnita
time limit per test4 seconds
memory limit per test256 megabytes
Saturnita's mood depends on an array 𝑎
 of length 𝑛
, which only he knows the meaning of, and a function 𝑓(𝑘,𝑎,𝑙,𝑟)
, which only he knows how to compute. Shown below is the pseudocode for his
function 𝑓(𝑘,𝑎,𝑙,𝑟)
.

function f(k, a, l, r):
   ans := 0
   for i from l to r (inclusive):
      while k is divisible by a[i]:
         k := k/a[i]
      ans := ans + k
   return ans
You are given 𝑞
 queries, each containing integers 𝑘
, 𝑙
, and 𝑟
. For each query, please output 𝑓(𝑘,𝑎,𝑙,𝑟)
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑞
 (1≤𝑛≤105,1≤𝑞≤5⋅104
).

The following line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (2≤𝑎𝑖≤105
).

The following 𝑞
 lines each contain three integers 𝑘
, 𝑙
, and 𝑟
 (1≤𝑘≤105,1≤𝑙≤𝑟≤𝑛
).

It is guaranteed that the sum of 𝑛
 does not exceed 105
 over all test cases, and the sum of 𝑞
 does not exceed 5⋅104
 over all test cases.

Output
For each query, output the answer on a new line.

Example
InputCopy
2
5 3
2 3 5 7 11
2 1 5
2 2 4
2310 1 5
4 3
18 12 8 9
216 1 2
48 2 4
82944 1 4
OutputCopy
5
6
1629
13
12
520

*/
