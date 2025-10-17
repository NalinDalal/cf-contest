/*H. Beautiful Problem
time limit per test2 seconds
memory limit per test256 megabytes
For an array 𝑎
 of length 𝑛
 and three integers 𝑥
, 𝑙
, and 𝑟
（1≤𝑙≤𝑟≤𝑛
), define:

𝑓(𝑎,𝑥,𝑙,𝑟)={0,1,ifif(𝑥−min𝑟𝑗=𝑙(𝑎𝑗))⋅(𝑥−max𝑟𝑗=𝑙(𝑎𝑗)))<0(𝑥−min𝑟𝑗=𝑙(𝑎𝑗))⋅(𝑥−max𝑟𝑗=𝑙(𝑎𝑗)))≥0

You are given an array 𝑎
 of length 𝑛
 (1≤𝑎𝑖≤𝑛
), and 𝑚
 intervals [𝑙𝑖,𝑟𝑖]
 (1≤𝑙𝑖≤𝑟𝑖≤𝑛
).

For each 𝑥=1,2,…,𝑛
, answer the following question independently:

Does there exist a rearrangement 𝑎′
 of 𝑎
, such that for all 1≤𝑖≤𝑚
, 𝑓(𝑎′,𝑥,𝑙𝑖,𝑟𝑖)=1
?
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases. Description of each testcase follows.

The first line contains two integers 𝑛
 and 𝑚
 (2≤𝑛≤2000
, 1≤𝑚≤2000
).

The next line contains 𝑛
 space-separated integers 𝑎1,𝑎2,⋯,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

The next 𝑚
 lines each contain two space-separated integers 𝑙𝑖,𝑟𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤𝑛
), each denoting an interval.

It is guaranteed that the sum of 𝑛2
 and the sum of 𝑚2
 over all test cases does not exceed 4⋅106
, respectively.

Output
For each test case, output a binary string 𝑠
. For 𝑥=1,2,…,𝑛
, 𝑠𝑥=1
 only if there exists a rearrangement 𝑎′
 of 𝑎
, such that for all 1≤𝑖≤𝑚
, 𝑓(𝑎′,𝑥,𝑙𝑖,𝑟𝑖)=1
. Otherwise, 𝑠𝑥=0
.

Example
InputCopy
4
4 2
1 1 3 4
1 2
2 4
3 2
1 1 3
1 2
2 3
3 1
1 1 1
1 3
9 3
4 5 9 1 1 1 2 2 3
1 6
3 7
7 9
OutputCopy
1011
101
111
100100001
Note
In the first test case,

For 𝑥=1
, one valid rearrangement is 𝑎′=[1,1,3,4]
.
For 𝑥=2
, there is no rearrangement 𝑎′
 of 𝑎
 satisfying 𝑓(𝑎′,2,1,2)=𝑓(𝑎′,2,2,4)=1
.
For 𝑥=3
, the only valid rearrangement is 𝑎′=[4,3,1,1]
.
For 𝑥=4
, one valid rearrangement is 𝑎′=[1,1,3,4]
.

*/
