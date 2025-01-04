/* D. Gifts Order
time limit per test2 seconds
memory limit per test512 megabytes
"T-Generation" has decided to purchase gifts for various needs; thus, they have
𝑛 different sweaters numbered from 1 to 𝑛 . The 𝑖 -th sweater has a size of 𝑎𝑖
. Now they need to send some subsegment of sweaters to an olympiad. It is
necessary that the sweaters fit as many people as possible, but without having
to take too many of them.

They need to choose two indices 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
) to maximize the convenience equal to
max(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)−min(𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟)−(𝑟−𝑙),
that is, the range of sizes minus the number of sweaters.

Sometimes the sizes of the sweaters change; it is known that there have been 𝑞
 changes, in each change, the size of the 𝑝
-th sweater becomes 𝑥
.

Help the "T-Generation" team and determine the maximum convenience among all
possible pairs (𝑙,𝑟) initially, as well as after each size change.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤2⋅105
) — the number of sweaters and the number of size changes.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the sizes of the sweaters.

Each of the following 𝑞
 lines of each test case contains two integers 𝑝
 and 𝑥
 (1≤𝑝≤𝑛
, 1≤𝑥≤109
) — the next size change.

It is guaranteed that the sum of the values of 𝑛
 and the sum of the values of 𝑞
 across all test cases do not exceed 2⋅105
.

Output
For each test case, output the maximum value of convenience among all possible
pairs (𝑙,𝑟) before any actions, as well as after each size change.

Example
InputCopy
3
2 2
1 10
1 10
2 2
5 3
1 2 3 4 5
3 7
1 4
5 2
8 5
7 4 2 4 8 2 1 4
5 4
1 10
3 2
8 11
7 7
OutputCopy
8
0
7
0
4
4
4
5
3
6
6
9
7
Note
Consider the first test case.

Before any changes, you can take all the sweaters; then the convenience is equal
to max(𝑎1,𝑎2)−min(𝑎1,𝑎2)−(2−1)=10−1−1=8
.
After the first query, the sizes of both sweaters will be equal to 10
, you can only take the first sweater and the convenience is equal to 10−10−0=0
.
After the second query, the size of the first sweater will be 10
, and the second 2
, you can take all the sweaters and the convenience is equal to
max(𝑎1,𝑎2)−min(𝑎1,𝑎2)−(2−1)=10−2−1=7
.

*/
